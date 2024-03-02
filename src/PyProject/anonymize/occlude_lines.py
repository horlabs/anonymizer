#!/usr/bin/env python3
import argparse
import logging
import os
import re
import subprocess
import sys
import tempfile
import threading
from multiprocessing.pool import ThreadPool
from pathlib import Path
from typing import Tuple, List

import ConfigurationGlobalLearning as Config
import utils.classify

file_re = re.compile(
    "([0-9]+_[0-9]+)_([a-zA-Z0-9.-]+)(?:_raw_|_raw_format_){0,1}[0-9]*(?:_before|_after_transf_|_final_|_original|\.out){0,1}\.c(?:pp)?$")
results = {}
code_versions = []
versions_lock = threading.Lock()

def occluding(data: Tuple[List[str], int, Path, str, str, str]):
    lines, idx, authordir, author, problem, modelsuffix = data
    lines = lines.copy()
    env = os.environ
    os.chdir(authordir)
    env["TIGRESS_HOME"] = str(Path.home().joinpath("code/tigress/3.1"))
    env["PATH"] += ":" + env["TIGRESS_HOME"]

    workingfile = authordir.joinpath(f"{problem}_{author}_raw_{idx}.c")
    obfuscated_file = authordir.joinpath(f"{problem}_{author}_raw_{idx}.obf.c")
    logging.info(f"[{idx:3}]\tProcessing without line {idx}")
    results[idx] = None
    with open(workingfile, "w") as f:
        if lines[idx].count("{") > lines[idx].count("}"):
            lines[idx+1] = "{\n"+lines[idx+1]
        if idx == 0:
            f.writelines(lines[1:])
        elif idx + 1 == len(lines):
            f.writelines(lines[:-1])
        else:
            #if lines[idx].count("{") > lines[idx].count("}"):
            #    f.write("{\n")
            f.writelines(lines[:idx] + lines[idx + 1:])
    if workingfile.stat().st_size == 0:
        logging.error(f"[{idx:3}] Error: Working file emtpy")
    s = None
    try:
        logging.info(f"[{idx:3}]\tObfuscate file")
        while True:
            s = subprocess.run(
                f'{str(Path(Config.repo_path).joinpath("data/tigress_tools/obfuscate_tigress.sh"))} --advanced {str(workingfile)}',
                env=env, cwd=authordir, shell=True, stderr=subprocess.PIPE, stdout=subprocess.PIPE)
            if b"std::bad_alloc" in s.stderr:
                continue
            s.check_returncode()
            if obfuscated_file.stat().st_size == 0:
                logging.debug("[{idx:3}] Obfuscated file empty")
                continue
            break
    except (Exception, subprocess.CalledProcessError) as e:
        logging.warning(f"[{idx:3}]\tError while obfuscating without '{lines[idx].strip()}'")
        logging.debug(f"[{idx:3}]\t{e}")
        logging.debug(f"[{idx:3}]\tCode:\n{''.join(lines)}")
        if s is not None:
            logging.debug(f"[{idx:3}]\tstderr: {s.stderr}")
            logging.debug(f"[{idx:3}]\tstdout: {s.stdout}")
        return
    logging.info(f"[{idx:3}]\tClassify obfuscated file")
    probas = None
    while True:
        try:
            label, probas = utils.classify.classify(str(obfuscated_file), modelsuffix=modelsuffix)
            break
        except AssertionError as e:
            print("\n".join(
                [f"Without line {idx}: {lines[idx]} ({obfuscated_file.stat().st_size})", open(obfuscated_file).read()]))
            print(e)
            return
        except KeyboardInterrupt:
            exit()
        except Exception as e:
            logging.warning(f"[{idx:3}]\t{e}")
            continue
    assert probas is not None and len(probas) > 0
    global versions_lock
    with versions_lock:
        global code_versions
        content = open(workingfile).read()
        content = re.sub("\n{2,}", "\n", content)
        if content not in code_versions:
            code_versions.append(content)

    best_indices, best_probas = utils.classify.get_best(probas, 2)
    logging.info(
        f"[{idx:3}]\tResult without line {idx} ('{lines[idx].strip()}'): {best_indices[0]:2} {best_probas[0] * 100:6.3f}")
    results[idx] = (best_indices[0], best_probas[0] * 100)


def main(filename: str, modelsuffix: str, tempdir: Path):

    logging.basicConfig(level=logging.ERROR, format="%(levelname)-9s %(asctime)s\t\t%(message)s",
                        datefmt="%d.%m.%Y %H:%M:%S")
    problem, author = file_re.search(Path(filename).name).groups()
    logging.info(f"Start processing {author} for problem {problem}")
    authordir = tempdir.joinpath(author)
    authordir.mkdir()
    env = os.environ
    env["TIGRESS_HOME"] = str(Path.home().joinpath("code/tigress/3.1"))
    env["PATH"] += ":" + env["TIGRESS_HOME"]
    with open(filename) as f:
        lines = f.readlines()
    workingfile = authordir.joinpath(f"{problem}_{author}.c")
    obfuscated_file = authordir.joinpath(f"{problem}_{author}.obf.c")

    logging.info("Processing whole file as reference")
    s = None
    with open(workingfile, "w") as f:
        f.writelines(lines)
    assert workingfile.exists() and workingfile.stat().st_size > 0
    try:
        logging.info("Obfuscate file")
        s = subprocess.run(
            f'{str(Path(Config.repo_path).joinpath("data/tigress_tools/obfuscate_tigress.sh"))} --advanced {str(workingfile)}',
            env=env, cwd=authordir, shell=True, stderr=subprocess.PIPE, stdout=subprocess.PIPE)
        s.check_returncode()
    except Exception as e:
        logging.error(f"Error while obfuscating: {e}")
        logging.debug(f"Code:\n{lines}")
        logging.debug(f"stdout: {s.stdout[-1500:]}")
        logging.debug(f"stderr: {s.stderr[-1500:]}")
        exit()

    if not obfuscated_file.exists() or obfuscated_file.stat().st_size == 0:
        logging.error("Empty file")
        logging.info(b"std::bad_alloc" in s.stderr)
        logging.debug(f"stdout: {s.stdout[-1500:].decode()}")
        logging.debug(f"stderr: {s.stderr[-1500:].decode()}")
        exit()
    logging.info(f"Classify obfuscated file")
    label, probas = utils.classify.classify(str(obfuscated_file), modelsuffix=modelsuffix)
    best_indices, best_probas = utils.classify.get_best(probas, 2)
    logging.info(f"Result: {best_indices[0]} {best_probas[0] * 100}")

    with ThreadPool(processes=24) as pool:
        pool.map(occluding, [(lines, idx, authordir, author, problem, modelsuffix) for idx in range(len(lines))])

    print(f"{best_indices[0]:2}; {best_probas[0] * 100:6.3f} | // No changes")
    for idx in sorted(results.keys()):
        if results[idx] is not None:
            out = f"{results[idx][0]:2}; {results[idx][1]:6.3f} | {lines[idx][:-1]}"
        else:
            out = f"           | {lines[idx][:-1]}"
        print(out)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Test file line by line if the probability drops")
    parser.add_argument("-m", "--modelsuffix", required=False, type=str, default="c_only_tigress_v7",
                        help="Suffix of model to classify")
    parser.add_argument("file", metavar="FILE", type=str, help="File to process")
    args = parser.parse_args()
    if not Path(args.file).exists():
        print(f"File not found: {args.file}", file=sys.stderr)
        exit(-1)
    if file_re.match(Path(args.file).name) is None:
        print("Filename doesn't match the specification", file=sys.stderr)
        exit(-1)
    with tempfile.TemporaryDirectory(prefix=f"{Path(args.file).name}_", dir="/tmp") as tmpdir:
        main(args.file, args.modelsuffix, Path(tmpdir))
