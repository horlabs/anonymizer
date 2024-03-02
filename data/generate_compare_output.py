#!/usr/bin/env python3

import subprocess
from subprocess import PIPE
import sys
from pathlib import Path
import tempfile
import os
from typing import Dict
import threading
from concurrent.futures import ThreadPoolExecutor, as_completed
from tree_sitter import Language, Parser
from rich.progress import Progress
import logging
from rich.logging import RichHandler
from rich.console import Console
import re

log_file = open("gen_compare.log", "wt")
console = Console(file=log_file)
FORMAT = "%(message)s"
logging.basicConfig(
    level="DEBUG", format=FORMAT, datefmt="[%X]", handlers=[RichHandler(markup=False)]
)
log = logging.getLogger("rich")

C_LANG = Language("<path to tree sitter c.so>", "c") # TODO: Path
parser = Parser()
parser.set_language(C_LANG)

exec_env = os.environ.copy()
exec_env["LD_PRELOAD"] = "/code-imitator/src/LibToolingAST/hooks.so"
exec_env["LD_LIBRARY_PATH"] = "/code-imitator/src/LibToolingAST"

class SubprocessThread(threading.Thread):
    def __init__(self,
                args,
                tmpdirname,
                stdin_pipe=subprocess.PIPE,
                stdout_pipe=subprocess.PIPE,
                stderr_prefix=None,
                timeout=300):
        threading.Thread.__init__(self)
        self.stderr_prefix = stderr_prefix
        global exec_env
        self.p = subprocess.Popen(
            args, cwd=tmpdirname, stdin=stdin_pipe, stdout=stdout_pipe, stderr=subprocess.PIPE, env=exec_env)
        self.timer = threading.Timer(timeout, self.p.kill)
        self.out = ""

    def run(self):
        try:
            self.timer.start()
            self.return_code = self.p.wait()
            self.timer.cancel()
            if self.p.poll() != 0:
                self.return_code = -1
                self.error_message = "Timeout"
            else:
                self.error_message = None
        except (SystemError, OSError):
            self.return_code = -1
            self.error_message = "The process crashed or produced too much output."

cpp_input_dir = Path("/code-imitator/data/dataset_2017/test_inputs")
src_dir = Path(sys.argv[1]).resolve()
clang = Path("/clang+llvm-5.0.0-linux-x86_64-ubuntu16.04/bin/clang")
argsC = ["-o", "a.out", "-w", "-ferror-limit=1", "-std=c99",
        "-L/code-imitator/src/LibToolingAST",  "-lnocstd", "-lm",
        "-include", "/code-imitator/src/LibToolingAST/microsoft_specific.h",
        "-include", "/code-imitator/src/LibToolingAST/nocstd.h",
        "-I", "/clang+llvm-5.0.0-linux-x86_64-ubuntu16.04/lib/clang/5.0.0/include"]
argsCPP = ["-o", "a.out", "-w", "-ferror-limit=1", "-std=c++11", "-lm", 
        "-include", "/code-imitator/src/LibToolingAST/microsoft_specific.h",
        "-include", "/code-imitator/src/LibToolingAST/ourerrors.h",
        "-I", "/clang+llvm-5.0.0-linux-x86_64-ubuntu16.04/lib/clang/5.0.0/include"]
reduced_tasks = [
                    "00000000000000cb_00000000000079cb",
                    "00000000000516b9_0000000000134c90",
                    "0000000000051705_0000000000088231",
                    "1145485_1053485",
                    "1150485_1048486",
                    "1150485_1058489",
                    "1150486_1100485",
                    "1460488_1483488",
                    "1460488_1595491",
                    "1645485_1482494",
                    "1781488_1482492",
                    "1836486_1480487",
                    "186264_203106"
                    "188266_168107",
                    "2270488_2449486",
                    "2270488_2453486",
                    "2270488_2458486",
                    "2270488_2463486", 
                    "2437488_2749486",
                    "2437488_2751486",
                    "2437488_2755486",
                    "2974486_5690574640250880",
                    "2974486_5709773144064000",
                    "2984486_5634947029139456",
                    "2994486_5658282861527040",
                    "2994486_5751500831719424",
                    "32015_24486",
                    "32015_24488",
                    "32016_24482",
                    "32016_24484",
                    "32017_24485",
                    "32017_24489",
                    "3264486_5719854539603968",
                    "3274486_5706636844859392",
                    "4244486_5646553574277120",
                    "4244486_5708284669460480",
                    "4304486_5630113748090880",
                    "4304486_5631989306621952",
                    "6254486_5652388522229760",
                    "8234486_5750872826970112",
                    "8294486_5630967708385280", 
                    "8294486_5681755159789568", 
                    "90101_111101",
                    "90101_116101",
                    "975485_1026487",
                    "975485_1080487",
                    "975485_992486",
                ] # ToDo: Replace this with file-specific list where to use reduced inputs

special_return_codes = {
    "1460488_1483485_ravi00ei51.c": 255
}

log.info(f"Dataset: {src_dir}")
assert src_dir.exists()

input_files: Dict[str, Path] = {}

for d in cpp_input_dir.iterdir():
    if not d.is_dir():
        continue
    for f in d.iterdir():
        if f"{d.stem}_{f.stem}" in reduced_tasks and "reduced" not in str(f):
            continue
        key = f"{d.stem}_{f.stem}".replace("_reduced", "")
        input_files[key] = f

compiled_lock = threading.Lock()
cnt_compiled = 0
out_lock = threading.Lock()
cnt_out = 0
timeout_secs = 600
sanitizer = False
authors = sorted(src_dir.iterdir())

def get_compile_args(f: Path):
    if f.suffix == ".c":
        args = argsC.copy()
        CC = clang
    else:
        args = argsCPP.copy()
        CC = Path(str(clang)+"++")

    if sanitizer:
        args.extend(["-g"])
        args.extend(["-fsanitize=address"])
            
    with open(f, "rb") as fd:
        code = fd.read()
    tree = parser.parse(code)
    query = C_LANG.query("(function_declarator declarator: (identifier) @func) (preproc_def name: (identifier) @define_name) (type_definition declarator: (type_identifier) @type_id)")
    for capture,_ in query.captures(tree.root_node):
        if capture.text in [b"min", b"max"]:
            args.extend(["-D", "MIN_MAX"])
        if capture.text == b"itoa":
            args.extend(["-D", "ITOA"])
        if capture.text == b"bool":
            args.extend(["-D", "BOOLTYPE"])
    if re.search(b"typedef [^;]* bool;", code) and not "BOOLTYPE" in args:
        args.extend(["-D", "BOOLTYPE"])
    return args, CC

def run_standalone(f, args, CC, problem, tmpdirname, exe_path):
    with open(input_files[problem], "rb") as in_file:
        s = subprocess.run([str(exe_path), "in", "out"], cwd=tmpdirname, stderr=PIPE, stdout=PIPE, stdin=in_file, env=exec_env, timeout=timeout_secs)
        if (s.returncode != 0 and s.returncode != 1)  and (f.name not in special_return_codes or special_return_codes[f.name] != s.returncode) or len(s.stdout) == 0 or (b"AddressSanitizer" in s.stderr and not b"WARNING: unexpected format specifier in" in s.stderr):
            in_file.seek(0)
            s = subprocess.run([str(exe_path), "in"], cwd=tmpdirname, stderr=PIPE, stdout=PIPE, stdin=in_file, env=exec_env, timeout=timeout_secs)
    out = s.stdout
    if s.returncode != 0 and s.returncode != 1 and (f.name not in special_return_codes or special_return_codes[f.name] != s.returncode):
        raise RuntimeError(" ".join([str(CC), str(f)] + args))
    if b"AddressSanitizer" in s.stderr and not b"LeakSanitizer" in s.stderr and not b"WARNING: unexpected format specifier in" in s.stderr:
        raise RuntimeError(" ".join([str(CC), str(f)] + args))
    return out

def run_interactive(f, args, CC, problem, tmpdirname, exe_path):
    if problem in ["00000000000000cb_0000000000007a30", "0000000000007765_000000000003e068"]:
        s = subprocess.run(["python", input_files[problem], str(exe_path)], cwd=tmpdirname, stderr=PIPE, stdout=PIPE, timeout=60)
        out = s.stdout
        if s.returncode != 0 and s.returncode != 1 and (f.name not in special_return_codes or special_return_codes[f.name] != s.returncode):
            raise RuntimeError(" ".join([str(CC), str(f)] + args))
    else:
        t_sol = SubprocessThread(str(exe_path), tmpdirname, stderr_prefix="  sol: ")
        t_judge = SubprocessThread(
                                ["python", input_files[problem], "0"],
                                tmpdirname,
                                stdin_pipe=t_sol.p.stdout,
                                stdout_pipe=t_sol.p.stdin,
                                stderr_prefix="judge: ")
        t_sol.start()
        t_judge.start()
        t_judge.join()
        if t_sol.is_alive() and t_sol.p.poll() is None:
            try:
                t_sol.p.kill()
                raise subprocess.TimeoutExpired(str(f), 300.0)
            except ProcessLookupError:
                pass
        t_sol.join()
        t_sol.p.poll()
        out = t_judge.p.stderr.read()
        if t_sol.p.returncode != 0:
            if t_sol.error_message == "Timeout":
                raise subprocess.TimeoutExpired(str(f), 300.0)
            raise RuntimeError(" ".join([str(CC), str(f)] + args))
        assert t_judge.p.stderr is not None
    return out

def execute(f: Path, author_dir: Path):
    global cnt_compiled
    global cnt_out
    problem = "_".join(f.stem.split("_")[:2])
    with tempfile.TemporaryDirectory() as tmpdirname:
        out = b""
        try:
            args, CC = get_compile_args(f)
            s = subprocess.run([str(CC), str(f)] + args, cwd=tmpdirname, stderr=PIPE, stdout=PIPE, timeout=120)
            s.check_returncode()
            with compiled_lock:
                cnt_compiled += 1
            out_file = author_dir.joinpath(f.stem+".out")
            if out_file.exists() and out_file.stat().st_size > 0:
                return
            if problem not in input_files:
                raise FileNotFoundError(f"No input file for {problem}")
            exe_path = Path(tmpdirname)/Path("a.out")
            out = b""
            
            if input_files[problem].suffix == ".in":
                out = run_standalone(f, args, CC, problem, tmpdirname, exe_path)
            elif input_files[problem].suffix == ".py":
                out = run_interactive(f, args, CC, problem, tmpdirname, exe_path)
            else:
                raise NotImplementedError(f"Using file of type {input_files[problem].suffix} is not implemented yet")
            assert out is not None
            assert len(out) > 0
            with open(out_file, "wb") as of:
                of.write(out)
            assert out_file.stat().st_size > 0
            with out_lock:
                cnt_out += 1
        except KeyboardInterrupt:
            return False
        except SystemExit:
            return False
        except AssertionError:
            log.warning(f"{f.name} returned no output")
        except subprocess.TimeoutExpired:
            log.warning(f"{f.name} takes too long")
            log.debug(out)
            return False
        except subprocess.CalledProcessError:
            log.error(f"Error compiling {f}")
            return False
        except RuntimeError as e:
            log.error(f"Error executing {f}")
            log.info(e)
            return False
        return True

def main():
    with Progress() as progress, ThreadPoolExecutor(max_workers=8) as executor:
        try:
            task_id_authors = progress.add_task("Files", total=0)
            task_authors = progress.tasks[task_id_authors]
            futures = set()
            for author_dir in authors:
                if not author_dir.is_dir():
                    continue
                files = [x for x in sorted(author_dir.iterdir()) if x.suffix in [".cpp", ".c"]]
                assert task_authors.total is not None
                progress.update(task_id_authors, total=task_authors.total + len(files))
                for f in files:
                    futures.add(executor.submit(execute, f, author_dir))
            f = 0
            for future in as_completed(futures):
                progress.advance(task_id_authors)
                f += 1
                progress.update(task_id_authors, description=f"{f}/{task_authors.total} files finished")
        except KeyboardInterrupt:
            log.warning("Interrupted by user")
            for future in futures:
                future.cancel()

    log.info(f"Compiled {cnt_compiled} programs successfully")
    log.info(f"Get non-empty outputs from {cnt_out} programs")
    log_file.close()

if __name__ == "__main__":
    main()
