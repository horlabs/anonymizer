#!/usr/bin/env python3

import subprocess
from subprocess import PIPE
import sys
from pathlib import Path
import tempfile
import os
from datetime import datetime
from multiprocessing import Queue, Process, Value, Lock
import queue
from functools import partial
import threading

print(datetime.now().strftime("%c"))

cpp_input_dir = Path("/code-imitator/data/dataset_2017/test_inputs")
src_dir = Path(sys.argv[1]).resolve()
clang = Path("/clang+llvm-5.0.0-linux-x86_64-ubuntu16.04/bin/clang")
include = "/code-imitator/src/LibToolingAST/microsoft_specific.h"
tigress = len(sys.argv) > 2
renamed = len(sys.argv) > 3
if tigress:
    include = "/code-imitator/src/LibToolingAST/microsoft_specific_tigress.h"
exec_env = os.environ.copy()
exec_env["LD_PRELOAD"] = "/code-imitator/src/LibToolingAST/cmake-build-release/libhooks.so"
exec_env["LD_LIBRARY_PATH"] = "/code-imitator/src/LibToolingAST/"
outs_check_dir = Path("/code-imitator/data/dataset_c_only/dataset_c_only")
reduced_tasks = [
                    "8294486_5630967708385280", 
                    "8294486_5681755159789568", 
                    "2974486_5709773144064000", 
                    "2270488_2463486", 
                    "1460488_1483488",
                    "1460488_1595491",
                    "2270488_2449486",
                    "2270488_2453486"
                ]

print("Dataset:", src_dir)
assert src_dir.exists()

input_files = {}

for d in cpp_input_dir.iterdir():
    if not d.is_dir():
        continue
    for f in d.iterdir():
        if f"{d.stem}_{f.stem}" in reduced_tasks and "reduced" not in str(f):
            continue
        key = f"{d.stem}_{f.stem}".replace("_reduced", "")
        input_files[key] = f

files = []
for author_dir in src_dir.iterdir():
    if not author_dir.is_dir():
        continue
    for f in author_dir.iterdir():
        if (f.suffix != ".cpp" and f.suffix != ".c") or (tigress and "obf" not in f.name and not renamed) or (not tigress and "obf" in f.name):
            continue
        files.append(f)

def processing_file(cnt_lock, cnt_compiled, cnt_outs, pqueue):
    try:
        while True:
            f = pqueue.get(False)
            problem = "_".join(f.stem.split("_")[:2])
            author_dir = f.parent
            with tempfile.TemporaryDirectory() as tmpdirname:
                try:
                    with open(f, "rb") as sourcecode:
                        content = sourcecode.read()
                        include_real = include
                        if (b"strlen" in content or b"strncmp" in content) and tigress:
                            include_real = "/code-imitator/src/LibToolingAST/microsoft_specific_tigress_2.h"
    
                    args = ["-o", "a.out", "-w", "-ferror-limit=1", "-std=c99", "-lm", "-ldl", "-lnocstd",
                                "-L", "/code-imitator/src/LibToolingAST/cmake-build-release",
                                "-include", include_real,
                                "-I", "/code-imitator/src/LibToolingAST/",
                                "-I", "/clang+llvm-5.0.0-linux-x86_64-ubuntu16.04/lib/clang/5.0.0/include"]
    
                    s = subprocess.run([str(clang), str(f)] + args, cwd=tmpdirname, stderr=PIPE, stdout=PIPE)
                    s.check_returncode()
                    with cnt_lock:
                        cnt_compiled.value += 1
                    out_file = outs_check_dir.joinpath(author_dir.name, f.stem.replace(".obf", "")+".out")
                    assert out_file.exists(), f"'{out_file}' doesn't exist"
                    with open(input_files[problem], "rb") as in_file:
                        s = subprocess.run(str(Path(tmpdirname).joinpath("a.out")), cwd=tmpdirname, stderr=PIPE, stdout=PIPE, stdin=in_file, env=exec_env, timeout=4000)
                    if s.returncode != 0 and s.returncode != 1:
                        s.check_returncode()
                    with open(out_file, "rb") as out:
                        content = out.read()
                        if s.stdout.strip() != content.strip() and ("2270488_2463486_float." not in f.name or len(s.stdout.split(b"\n")) != len(content.split(b"\n"))):
                            print(f"{f.name} has different output")
                        else:
                            with cnt_lock:
                                cnt_outs.value += 1
                except KeyboardInterrupt:
                    print()
                    exit()
                except SystemExit:
                    exit()
                except AssertionError as e:
                    print("AssertionError", e)
                    exit()
                except subprocess.TimeoutExpired as e:
                    print(f"{f.name} takes too long")
                except subprocess.CalledProcessError as e:
                    print(f"Error compiling or executing {f}: {e}", file=sys.stderr)
                    print(s.stderr.decode(), file=sys.stderr)
    except queue.Empty:
        pass

try:
    cnt_lock = Lock()
    cnt_compiled = Value("i", 0)
    cnt_outs = Value("i", 0)
    pqueue = Queue(len(files))
    for f in files:
        pqueue.put(f)
    process_cnt = 16
    processes = []
    for _ in range(process_cnt):
        worker = Process(target=processing_file, args=(cnt_lock,cnt_compiled,cnt_outs,pqueue))
        worker.start()
        processes.append(worker)
    for worker in processes:
        worker.join()
except KeyboardInterrupt as k:
    pass

print(f"Compiled {cnt_compiled.value} programs successfully")
print(f"Get correct output from {cnt_outs.value} programs")
print(datetime.now().strftime("%c"))