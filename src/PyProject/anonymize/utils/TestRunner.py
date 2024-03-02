import os
import shutil
import subprocess
from pathlib import Path
from subprocess import PIPE
import re
import tempfile
import time

import Configuration
import ConfigurationGlobalLearning as Config
from tree_sitter import Language, Parser

C_LANG = Language("<path to tree sitter c.so>", "c") # TODO: Path
parser = Parser()
parser.set_language(C_LANG)


class TestRunner:

    def __init__(self, log, name, transformer_path, transformer_name, execute, out_path, optional=None, preload=None, dataset_path=None):
        # todo: pass from execute_transformer/argparse
        preload = os.path.join(Config.repo_path, "src/LibToolingAST/hooks.so")
        if optional is None:
            optional = []
        self.log = log
        self.name = name
        self.transformer_path = transformer_path
        self.transformer_name = transformer_name
        self.execute = execute
        self.optional = optional
        self.preload = preload
        self.out = out_path
        self.dataset_path = dataset_path

    def run_test(self, test_file):
        try:
            cwd = None
            subpath = None
            i = 0
            for p in Path(test_file).absolute().parts:
                if p.startswith("dataset_"):
                    subpath = ""
                elif subpath is not None:
                    i += 1
                    subpath += "/" + p
            subpath = str(Path(subpath).parent)
            inner_path = "/".join(subpath.split("/")[4:])
            subpath = "/".join(subpath.split("/")[1:4])
            orig_path = "/code-imitator/data/dataset_github/dataset_github_filtered/" + subpath
            macros_path = "/code-imitator/data/dataset_github/dataset_github_filtered_macrosremoved/" + subpath
            cwd = Path(test_file).parent
            self.log.process()
            dirname = os.path.join(self.out,
                                subpath)
            if not os.path.exists(dirname):
                os.makedirs(dirname)
            if not (Path(dirname) / inner_path).exists():
                (Path(dirname) / inner_path).mkdir(parents=True, exist_ok=True)
            filename = os.path.join(dirname, inner_path, os.path.basename(test_file))

            compile_args = []
            if filename.endswith(".cpp"):
                compile_args += ["-include", os.path.join(Config.repo_path, "src/LibToolingAST/ourerrors.h"),
                                "-include", os.path.join(Config.repo_path, "src/LibToolingAST/microsoft_specific.h"),
                                "-std=c++11"]
            else:
                compile_args += ["-std=c99", "-lm", "-ldl", "-lgmp", "-lglpk", "-lmpfr", "-lpthread", 
                                "-Wno-error=unused-command-line-argument", "-Wno-error=logical-op-parentheses",
                                '-include', '{}'.format(os.path.join(Config.repo_path, 'src/LibToolingAST/nocstd.h')),
                                #"-include", "/usr/include/stdlib.h",
                                "-I/usr/local/include/glib-2.0", "-I/usr/local/lib/x86_64-linux-gnu/glib-2.0/include", "-I/usr/local/include",
                                #'-L{}'.format(os.path.join(Config.repo_path, 'src/LibToolingAST/')),
                                '-lnocstd', "-DGITHUB"
                                ]
                """-o", "a.out", "-w", "-ferror-limit=1", "-std=c99",
            "-L/code-imitator/src/LibToolingAST",  "-lnocstd", "-lm",
            "-I/usr/local/include/glib-2.0", "-I/usr/local/lib/x86_64-linux-gnu/glib-2.0/include", "-I/usr/local/include","""
            # print(" ".join(transform_args))
            with open(test_file, "rb") as fd:
                code = fd.read()
                if re.search(b"typedef ([^;]*?) uint64_t;", code) is not None:
                    compile_args.append("-DINTTYPES")
                tree = parser.parse(code)
                query = C_LANG.query("(function_declarator declarator: (identifier) @func) (preproc_def name: (identifier) @define_name) (type_definition declarator: (type_identifier) @type_id)")
                for capture,_ in query.captures(tree.root_node):
                    if capture.text in [b"min", b"max"]:
                        compile_args.extend(["-D", "MIN_MAX"])
                    if capture.text == b"itoa":
                        compile_args.extend(["-D", "ITOA"])
                    if capture.text == b"bool":
                        compile_args.extend(["-D", "BOOLTYPE"])
                if re.search(b"typedef [^;]* bool;", code) and not "BOOLTYPE" in compile_args:
                    compile_args.extend(["-D", "BOOLTYPE"])
            if test_file.endswith("Luis_Menina/liberforce/termite/utils.c"): # gets min/max from included custom header
                compile_args.extend(["-D", "MIN_MAX"])

            with tempfile.TemporaryDirectory() as tmp_path:
                if Configuration.multifilesetup:
                    tmp_dir = Path(tmp_path) / subpath
                    shutil.copytree(orig_path, tmp_dir)
                    os.system(f"cp -r {macros_path} {tmp_dir.parent}")
                    tmp_file = tmp_dir / inner_path / Path(test_file).name
                    shutil.copy(test_file, tmp_file)
                transform_args = [self.transformer_path, tmp_file if Configuration.multifilesetup else test_file] + self.optional + ["--"]
                transform_args += ["-I",
                                        os.path.join(Configuration.llvmconfig_libdir, "clang/5.0.0/include")] + compile_args
                transformer_process = subprocess.run(
                    transform_args,
                    stderr=PIPE, stdout=PIPE, cwd=tmp_file.parent if Configuration.multifilesetup else None)
                transform_round = 0
                
                while self.transformer_name == "typedef_transformer" and len(transformer_process.stderr) == 0 \
                        and transformer_process.returncode == 0:
                    if transform_round >= 25:
                        self.log.error(" ".join(transformer_process.args))
                        self.log.error(
                            f"ERROR while transforming {test_file} after transformation with {self.transformer_name}"
                            f" (too much iterations)\n" + transformer_process.stderr.decode())
                        self.log.add_error(test_file)
                        raise RuntimeError("While doesn't end")
                    transform_round += 1
                    with open(tmp_file if Configuration.multifilesetup else filename, "wb") as f:
                        f.write(transformer_process.stdout)
                    transformer_process = subprocess.run(
                        transform_args,
                        stderr=PIPE, stdout=PIPE,
                        cwd=tmp_file.parent if Configuration.multifilesetup else None)
                with open(tmp_file if Configuration.multifilesetup else filename, "wb") as f:
                    f.write(transformer_process.stdout)

                if os.path.getsize(tmp_file) == 0:
                    self.log.error(
                        f"ERROR while transforming {test_file} with {self.transformer_name} (filesize == {tmp_file.stat().st_size})\n" +
                        "stdout: " + transformer_process.stdout.decode() + "\nstderr: " + transformer_process.stderr.decode())
                    self.log.add_error(test_file)
                    return (test_file, False)

                if transformer_process.returncode != 0:
                    self.log.error(
                        f"ERROR while transforming {test_file} with {self.transformer_name}\n" +
                        transformer_process.stderr.decode())
                    #time.sleep(600)
                    self.log.add_error(test_file)
                    return (test_file, False)

                if not Path(self.out).joinpath(".clang-format").exists() and Path(Configuration.repo_path).joinpath("data", ".clang-format").exists():
                    shutil.copy(Path(Configuration.repo_path).joinpath("data", ".clang-format"), Path(self.out).joinpath(".clang-format"))

                format_process = subprocess.run(["clang-format", "--style={BasedOnStyle: LLVM, IndentWidth: 4}", tmp_file], stdout=PIPE)
                with open(tmp_file, "wb") as f:
                    f.write(format_process.stdout)

                if os.path.getsize(tmp_file) == 0:
                    self.log.error(
                        f"ERROR while formatting {test_file} with {self.transformer_name} (filesize == {tmp_file.stat().st_size})\n" +
                        "stdout: " + format_process.stdout.decode() + "\nstderr: " + format_process.stderr.decode())
                    self.log.add_error(test_file)
                    return (test_file, False)

                if format_process.returncode != 0:
                    self.log.error(
                        f"ERROR while formatting {test_file} with {self.transformer_name}\n" +
                        format_process.stderr.decode())
                    self.log.add_error(test_file)
                    return (test_file, False)

                # log.status(f"Test {id} from {len(test_files)} ({len(test_errors)} errors): Compiling..    ")
                problem_name = Path(test_file).stem

                clang_process = subprocess.run(
                    [os.path.join(Configuration.llvmconfig_prefix, "bin", "clang++" if filename.endswith(".cpp") else "clang"),
                    "-o", f"out_{problem_name}.a", "-w", "-c",
                    "-ferror-limit=1", tmp_file if Configuration.multifilesetup else filename,
                    *compile_args],
                    stderr=PIPE, stdout=PIPE, cwd=tmp_file.parent if Configuration.multifilesetup else None)

                if clang_process.returncode != 0:
                    self.log.error(" ".join([str(x) for x in clang_process.args]))
                    self.log.error(
                        f"ERROR while compiling {test_file} after transformation with {self.transformer_name}\n" +
                        clang_process.stderr.decode() if b"forward declaration" not in clang_process.stderr else "forward declaration")
                    self.log.add_error(test_file)
                    return (test_file, False)
                
                with open(filename, "wb") as f:
                    f.write(tmp_file.read_bytes())

                if self.execute:
                    preload_env = None
                    if self.preload:
                        preload_env = os.environ.copy()
                        preload_env["LD_PRELOAD"] = Configuration.iohookspath
                        preload_env["LD_LIBRARY_PATH"] = Configuration.customlibspath

                    original_prog = Path(Configuration.datasetpath).joinpath(problem_name.split("_")[-1],
                        ".".join([Path(filename).stem, "a"]))
                    original_output = Path(str(original_prog)[:-2] + ".out")
                    original_source = Path(str(original_prog)[:-2] + (".cpp" if filename.endswith(".cpp") else ".c"))

                    if not original_prog.exists():
                        subprocess.run(
                            [os.path.join(Configuration.llvmconfig_prefix, "bin", "clang++" if filename.endswith(".cpp") else "clang"), "-o", original_prog, "-w",
                            "-ferror-limit=1", "-std=c++11", original_source,
                            *compile_args])
                    assert original_prog.exists(), f"original prog {original_prog} ({original_source}) doesn't exist"

                    # check if transformation doesn't affect the output
                    parts = problem_name.split("_")[:2]
                    if parts[0] == "8294486" and parts[1] in ["5630967708385280", "5681755159789568"]:
                        parts[1] += "_reduced"
                    parts[1] += ".in"
                    input_file = Path(Config.repo_path).joinpath("data/dataset_2017/test_inputs", *parts)
                
                    # todo: refactor this
                    with open(input_file, "rb") as f_in:
                        if not original_output.exists():
                            proc = subprocess.run(
                                str(original_prog), stdin=f_in, stdout=PIPE, stderr=PIPE, env=preload_env
                                )
                            assert len(proc.stdout) > 0, "original output empty"
                            f_out = open(original_output, "wb")
                            f_out.write(proc.stdout)
                            f_in.seek(0)
                            f_out.close()
                        assert original_output.exists(), "original output doesn't exist"

                        transformed_process = subprocess.run(
                            str(Path().cwd().joinpath(f"out_{problem_name}.a")), stderr=PIPE, stdout=PIPE, stdin=f_in,
                            env=preload_env
                            )
                        f_in.seek(0)

                        transformed_process_out = transformed_process.stdout
                        assert len(transformed_process_out) > 0, "first out empty"

                        with open(original_output, "rb") as orig_out:
                            if orig_out.read() != transformed_process_out:
                                orig_out.seek(0)
                                transformed_process_second = subprocess.run(
                                    str(Path().cwd().joinpath(f"out_{problem_name}.a")), stderr=PIPE, stdout=PIPE,
                                    stdin=f_in, env=preload_env
                                    )
                                f_in.seek(0)
                                transformed_process_second_out = transformed_process_second.stdout
                                assert len(transformed_process_second_out) > 0, "second out empty"

                                if transformed_process_out != transformed_process_second_out:
                                    self.log.error(
                                        f"WARNING different outputs in multiple runs of {test_file} "
                                        f"after transformation with {self.transformer_name}\n")
                                    self.log.add_warning(test_file)
                                elif orig_out.read() != transformed_process_second_out:
                                    self.log.error(
                                        f"ERROR different outputs for {test_file} "
                                        f"after transformation with {self.transformer_name}\n")
                                    with open(problem_name + ".out", "wb") as f:
                                        f.write(transformed_process_out)
                                    self.log.add_error(test_file)
                                    if os.path.exists(f"out_{problem_name}.a"):
                                        os.remove(f"out_{problem_name}.a")
                                    return (test_file, False)
            if os.path.exists(f"out_{problem_name}.a"):
                os.remove(f"out_{problem_name}.a")
        except Exception as e:
            self.log.status("                                                   ")
            self.log.error("Exception: " + str(e.__class__) + " " + str(e))
            self.log.error("File: " + test_file)
            import traceback
            print(traceback.format_exc())
            self.log.add_error(test_file)
            return (test_file, False)
        except Error as e:
            pass
        finally:
            pass

        if os.path.exists(f"out_{problem_name}.a"):
            os.remove(f"out_{problem_name}.a")

        self.log.add_success(test_file)

        return (test_file, True)
