#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import argparse
import logging
import os
import re
import subprocess
import sys
import tempfile
from multiprocessing.pool import ThreadPool
from pathlib import Path
from typing import List, Tuple

import ConfigurationGlobalLearning as Config
import dataset_preprocessing.remove_comments_aftermacros as preprocessing
import utils.classify


file_re = re.compile(
    "([0-9]+_[0-9]+)_([a-zA-Z0-9.-]+)(?:_raw_|_raw_format_){0,1}[0-9]*(?:_before|_after_transf_|_final_|_original)?(?:\.out|\.obf)?\.c(?:pp)?$")
results = {}
versions = []


def annotate_file(filename: Path, lines: List[str], line: int, all_but_one: bool = False):
    pragma = "/*@ slice pragma stmt; */\n"
    tmp: List[str] = []
    braces = 0
    for idx, l in enumerate(lines):
        if braces > 0 and ((all_but_one and idx != line) or line == -1 or (not all_but_one and idx == line)):
            if not (l.strip().startswith("(") and l.strip().endswith(");") and l.count("(") == 1):
                tmp.append(pragma)
        elif not all_but_one and idx == line and braces == 0:
            raise IndexError(f"No slicable statement at line {line}")
        elif "init_tigress();" in l:
            tmp.append(pragma)
        braces += l.count("{")
        braces -= l.count("}")
        tmp.append(l)
    assert braces == 0
    lines = tmp
    with open(filename, "w") as f:
        f.writelines(lines)


def slicing(data: Tuple[List[str], int, Path, str, str, List[bytes], str]):
    lines, line, author_dir, problem, author, functions, modelsuffix = data
    if line >= 0:
        working_file: Path = author_dir.joinpath(f"{problem}_{author}_raw_{line}.c")
    else:
        working_file: Path = author_dir.joinpath(f"{problem}_{author}_original.c")
    obfuscated_file = author_dir.joinpath(f"{working_file.stem}.obf.c")
    results[line] = None

    try:
        annotate_file(working_file, lines, line=line, all_but_one=False)
    except IndexError as e:
        logging.error(f"[{line:3}] Error annotating file: {e}")
        return
    sliced_file: Path = author_dir.joinpath(f"{problem}_{author}_{line}_sliced.c")
    s = None
    try:
        s = subprocess.run(
            ["frama-c", "-slicing-level", "0",
             f"-cpp-extra-args=-I{str(Path(Config.repo_path).joinpath('src/LibToolingAST'))}", str(working_file),
             "-slice-pragma", b",".join(functions).decode(), "-then-on", "Slicing export",
             "-print", "-quiet", "-ocode", str(sliced_file)],
            stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        s.check_returncode()
    except subprocess.CalledProcessError as e:
        if b"Statement contract and ACSL pragmas over a local definition are not implemented." in s.stdout:
            logging.error(f"[{line:3}] No slicable statement at line {line}")
        elif s is not None:
            logging.error(f"[{line:3}] {s.stdout.decode()}")
        results[line] = None
        return
    sliced_p_file: Path = author_dir.joinpath(f"{problem}_{author}_{line}.c")
    preprocessing.remove_comments(str(sliced_file), str(sliced_p_file), "/dev/null")
    with open(sliced_p_file) as f:
        content = f.read()

    content = re.sub("[^ \n]+ [^ ]+_va_[0-9]+\(.*\);\n", "", content)
    content = re.sub("([^ ]+)_va_[0-9]+", "\g<1>", content)
    content = re.sub("__fc_(stdin|stdout|stderr)", "\g<1>", content)
    content = re.sub("\n+", "\n", content)
    content = re.sub("init_tigress_slice_[0-9]+", "init_tigress", content)
    content = re.sub("void main\(", "int main(", content)
    content = "#include \"superheader.h\"\n" + re.sub("#include [<\"][a-zA-Z.]+[>\"] *\n", "", content)

    start_main = content.index("int main(")
    main_part = content[start_main:]
    first_main_ret = main_part.index("return")
    brace_after_first_ret = main_part[first_main_ret:].index("}") + first_main_ret + 1
    main_part = content[start_main:start_main + brace_after_first_ret]
    main_part = main_part.replace("return;", "return 0;")

    content = content[:start_main] + main_part + content[start_main + brace_after_first_ret:]

    if content not in versions:
        versions.append(content)

    with open(working_file, "w") as f:
        f.write(content)

    assert working_file.exists() and working_file.stat().st_size > 0
    try:
        logging.info(f"[{line:3}] Obfuscate file")
        env = os.environ
        env["TIGRESS_HOME"] = str(Path.home().joinpath("code/tigress/3.1"))
        env["PATH"] += ":" + env["TIGRESS_HOME"]
        s = subprocess.run(
            f'{str(Path(Config.repo_path).joinpath("data/tigress_tools/obfuscate_tigress.sh"))} {str(working_file)}',
            env=env, cwd=author_dir, shell=True, stderr=subprocess.PIPE, stdout=subprocess.PIPE)
        s.check_returncode()
    except Exception as e:
        logging.error(f"[{line:3}] Error while obfuscating: {e}")
        logging.debug(f"[{line:3}] stdout: {s.stdout[-1500:].decode()}")
        logging.debug(f"[{line:3}] stderr: {s.stderr[-1500:].decode()}")
        return

    if not obfuscated_file.exists() or obfuscated_file.stat().st_size == 0:
        logging.error(f"[{line:3}] Empty file")
        logging.info(b"std::bad_alloc" in s.stderr)
        logging.debug(f"[{line:3}] stdout: {s.stdout[-1500:].decode()}")
        logging.debug(f"[{line:3}] stderr: {s.stderr[-1500:].decode()}")
        return
    logging.info(f"[{line:3}] Classify obfuscated file")
    label, probas = utils.classify.classify(str(obfuscated_file), modelsuffix=modelsuffix)
    best_indices, best_probas = utils.classify.get_best(probas, 2)
    logging.info(f"[{line:3}] Result: {best_indices[0]} {best_probas[0] * 100}")
    results[line] = (best_indices[0], best_probas[0] * 100)


def main(infile: str, modelsuffix: str, tempdir: Path):
    logging.basicConfig(level=logging.INFO, format="%(levelname)-9s %(asctime)s\t\t%(message)s",
                        datefmt="%d.%m.%Y %H:%M:%S")
    problem, author = file_re.search(Path(infile).name).groups()

    logging.info(f"Start processing {author} for problem {problem}")
    s = subprocess.run([Path(Config.repo_path).joinpath("data/tigress_tools/functionList.sh"), infile],
                       stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    functions = s.stdout.strip().split(b",")
    functions.append(b"main")

    with open(infile) as f:
        lines = f.readlines()

    author_dir: Path = Path(tempdir).joinpath(author)
    author_dir.mkdir()

    with ThreadPool(processes=16) as pool:
        pool.map(slicing,
                 [(lines, idx, author_dir, problem, author, functions, modelsuffix) for idx in range(-1, len(lines))])

    if results[-1] is not None or True:
        for idx in sorted(results.keys()):
            if idx == -1:
                if results[idx] is None:
                    print(f"          | // No changes")
                else:
                    print(f"{results[idx][0]:2}; {results[idx][1]:6.3f} | // No changes")
            elif results[idx] is None:
                print(f"           | {lines[idx][:-1]}")
            else:
                print(f"{results[idx][0]:2}; {results[idx][1]:6.3f} | {lines[idx][:-1]}")

    print("#Versions:", len(versions))


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
