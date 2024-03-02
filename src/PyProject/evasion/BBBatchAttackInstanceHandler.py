import os
import re
import shutil
import subprocess
import tempfile
import time
import typing
from collections import namedtuple
from multiprocessing import Pool
from pathlib import Path

import Configuration as Config
import evasion.utils_attack
import evasion.utils_attack_workflow
from evasion.BBAttackInstance import BBAttackInstance
from evasion.Transformers.TransformerBase import TransformerBase
from featureextractionV2.ClangTypes.StyloClangFeaturesGenerator import StyloClangFeaturesGenerator
from featureextractionV2.ClangTypes.StyloLexemFeaturesGenerator import StyloLexemFeatureGenerator
from featureextractionV2.StyloFeatures import StyloFeatures

TransformDetails = namedtuple("TransformDetails",
                              ["source_file", "source_file_copy", "savesrc_1", "cmdd_transform", "error_file",
                               "source_file_modified", "savesrc_2", "clangformat_cmd", "source_file_format",
                               "savesrc_3"])
CompileDetails = namedtuple("CompileDetails",
                            ["clangcompile_cmd", "error_file", "execute_cmd", "clang_call_cmd", "lexems_call_cmd"])


class BBBatchAttackInstanceHandler:
    """
    This class creates a bash script to call various transformers in parallel directly without any python overhead.
    Unfortunately, this class might not be so readable. In future work, we should be able to call transformers
    directly from python.
    """

    def __init__(self, noofcores: int, attackdirauth: str, inputlist: typing.List[typing.Tuple[BBAttackInstance, int,
                                            TransformerBase, int, list]]):
        """
        :param noofcores:
        :param attackdirauth:
        :param inputlist: Input will be: tempattackinstance, nextransformerindex, currenttransformerobj, i*9+nextransformerindex*7, queue
        """
        self.noofcores: int = noofcores
        self.attackdirauth: str = attackdirauth
        self.inputlist: typing.List[typing.Tuple[BBAttackInstance, int,
                                            TransformerBase, int, list]] = inputlist
        self.outputlist: list = [None]*len(inputlist)

        # to avoid that we call multiple times getsubprocesscall,
        # the transformers keep a state, thus this may lead to unwanted behaviour.
        self.simplified_calls: list = [None] * len(inputlist)
        self.unique_transformer_ids: list = [None] * len(inputlist)


        # find out what features need to be extracted
        self.doarff = self.dojoern = self.dolexems = False

        train_obj: StyloFeatures = self.inputlist[0][0].bbattackhandler.learnsetup.data_final_train
        while train_obj is not None:
            # self.doarff # TODO
            # if not, use old value so we basically implement OR operator here for booleans
            self.dojoern = True if StyloClangFeaturesGenerator.check_unique_keys_for_trainobject_comparison(
                trainobj=train_obj) else self.dojoern
            self.dolexems = True if StyloLexemFeatureGenerator.check_unique_keys_for_trainobject_comparison(
                trainobj=train_obj) else self.dolexems
            train_obj = train_obj.codestyloreference

    def batch_do_transformations(self):

        time1 = time.time()
        self.transform_format_preprocess()  # done in python
        nextround: list = self.transform_output_anaylsis()  # done in python
        time2 = time.time()
        self.compile_hash(nextround)  # done in python
        finalround: list = self.compile_hash_analysis(nextround)
        time3 = time.time()
        self.model_prediction(finalround)
        time4 = time.time()
        # print("Transform:{}s, Execute:{}s, Prediction:{}s".format(time2-time1, time3-time2, time4-time3))
        return self.outputlist

    @staticmethod
    def do_transform_format(details: 'TransformDetails'):
        shutil.copyfile(details.source_file, details.source_file_copy)
        if details.savesrc_1 is not "":
            shutil.copyfile(details.source_file, details.savesrc_1)
        
        cmd_transform = details.cmdd_transform
        clangformat_cmd = details.clangformat_cmd
        
        with tempfile.TemporaryDirectory() as tmp_path:
            if Config.multifilesetup:
                srcfile = Path(cmd_transform[1])
                idx = 1
                if srcfile.suffix not in [".c", ".h"]:
                    srcfile = Path(cmd_transform[2])
                    idx = 2
                author = srcfile.parent.name
                project = "/".join(srcfile.name.split("_")[:1])
                project = project.replace("-US-", "_").replace("-SL-", "/")
                subpath = "/".join(srcfile.name.split("_")[1:2]) + Path(srcfile).suffix
                subpath = subpath.replace("-US-", "_").replace("-SL-", "/")
                orig_path = Path("/code-imitator/data/dataset_github/dataset_github_filtered/") / author / project
                macros_path = Path("/code-imitator/data/dataset_github/dataset_github_filtered_macrosremoved/") / author / project
                tmp_dir = Path(tmp_path) / author / project
                shutil.copytree(orig_path, tmp_dir)
                os.system(f"cp -r {macros_path} {tmp_dir.parent}")
                link = tmp_dir / subpath
                link.unlink()
                link.symlink_to(srcfile)
                cmd_transform[idx] = str(link)
                clangformat_cmd[1] = str(link)
            with open(srcfile, encoding="iso-8859-1") as f:
                    if re.search("typedef [^;]* bool;", f.read()) is not None:
                        cmd_transform.append("-DBOOLTYPE")

            s = subprocess.run([x.replace("\"", "") for x in cmd_transform], stderr=subprocess.PIPE,
                    stdout=open(details.source_file_modified, "w"))
        with open(details.error_file, "wb") as f:
            f.write(s.stderr)
        if details.savesrc_2 is not "":
            shutil.copyfile(details.source_file_modified, details.savesrc_2)
        subprocess.run(details.clangformat_cmd, stderr=open(details.error_file, "a"),
                       stdout=open(details.source_file_format, "w"))
        shutil.copyfile(details.source_file_format, details.source_file)
        if details.savesrc_3 is not "":
            shutil.copyfile(details.source_file, details.savesrc_3)

        Path(details.source_file_modified).unlink()
        Path(details.source_file_format).unlink()

    def transform_format_preprocess(self):
        process_details = []
        ix: int = -1
        for inputparams in self.inputlist:
            ix += 1
            curbbattinst: BBAttackInstance = inputparams[0]
            prefix: str = str(inputparams[1])

            source_file_copy = curbbattinst.source_file + ".original"

            # A. + B. Transformation Call + clang-format
            source_file_modified = os.path.splitext(curbbattinst.source_file)[0] + "_raw." + \
                                   curbbattinst.source_file.split(".")[-1]

            cmdd_transform, simplified_cmdd_transform = inputparams[2].getsubprocesscall(
                                                                    source_file=curbbattinst.source_file,
                                                                    seed=inputparams[3])
            self.simplified_calls[ix] = simplified_cmdd_transform
            self.unique_transformer_ids[ix] = inputparams[2].uniqueid

            error_file = os.path.join(curbbattinst.source_file + ".stderr")
            clangformat_cmd, source_file_format = evasion.utils_attack_workflow.get_clang_format_call(
                source_file=source_file_modified)

            # Log files
            savesrc_1 = self.__save_source_file(src_file=curbbattinst.source_file, prefix=prefix,
                                    ending="before", bbatt=curbbattinst)
            savesrc_2 = self.__save_source_file(src_file=source_file_modified, prefix=prefix,
                                    ending="after_transf", bbatt=curbbattinst)
            savesrc_3 = self.__save_source_file(src_file=curbbattinst.source_file, prefix=prefix,
                                    ending="final", bbatt=curbbattinst)

            process_details.append(
                TransformDetails(curbbattinst.source_file, source_file_copy, savesrc_1, cmdd_transform, error_file,
                                 source_file_modified,
                                 savesrc_2, clangformat_cmd, source_file_format,
                                 savesrc_3))

        pool = Pool(processes=self.noofcores)
        try:
            for _ in pool.imap_unordered(BBBatchAttackInstanceHandler.do_transform_format, process_details):
                pass
        except Exception as e:
            print(e)
            pass
        finally:
            try:
                pool.terminate()
                pool.close()
            except BrokenPipeError:
                pass
            except Exception:
                pass

    def transform_output_anaylsis(self):

        qualified_for_next_round = [None] * len(self.inputlist)

        ix: int = -1 # better via enumerate, but typing complains
        for inputparams in self.inputlist:
            ix += 1
            curbbattinst: BBAttackInstance = inputparams[0]
            prefix: str = str(inputparams[1])
            simplified_cmdd_transform = self.simplified_calls[ix]


            try:
                error_file = os.path.join(curbbattinst.source_file + ".stderr")

                # A. + B. Transformer + clang-format
                self.__check_error_file(error_file)

                qualified_for_next_round[ix] = True

            except Exception as e:
                # we only show an exception if we have a real error. If transformation was not possible, we do not show it.
                # But careful. We might have got an exception, continued and then have got Code 123. In this case,
                # we want to show the error as well; we should have multiple error lines == checked by first if-condition:
                e_str = "".join(x.strip() for x in e.args)
                e_str = e_str.replace("\"Callee 'Main' is unknown; in CFGQueryHandler, main possibly gets args\\n\", 'Could not find first stmt of main fct\\n', ", "")
                e_str = e_str.replace("'Could not find main in get_unused_functions\\n'", "Code 123\\n")
                if e_str == "":
                    continue
                if ("Code 123" in e_str or "Code 124" in e_str) and e_str.count("\\n") == 1:
                    pass
                elif "Code 900" in e_str and e_str.count("\\n") == 1:
                    pass
                else:
                    curbbattinst.logger.error(
                        "`{}`, T-id:{}, transformation failed with: {}\n".format(simplified_cmdd_transform, prefix, e)) # e_str

                qualified_for_next_round[ix] = False

                # we restore the original file...
                source_file_copy = curbbattinst.source_file + ".original"
                assert os.path.isfile(source_file_copy)
                os.rename(source_file_copy, curbbattinst.source_file)


        return qualified_for_next_round

    @staticmethod
    def do_compile_hash(details: 'CompileDetails'):
        preload_env = os.environ.copy()
        preload_env["LD_PRELOAD"] = Config.iohookspath
        preload_env["LD_LIBRARY_PATH"] = Config.customlibspath
        cwd = str(Path(details.execute_cmd[0]).parent)
        with tempfile.TemporaryDirectory() as tmp_path:
            try:
                clangcompile_cmd = details.clangcompile_cmd
                idx = 0
                for idx, x in enumerate(clangcompile_cmd):
                    if x.endswith((".c", ".h")) and not x.endswith("nocstd.h"):
                        break
                srcfile = Path(clangcompile_cmd[idx])
                if Config.multifilesetup:
                    author = srcfile.parent.name
                    project = "/".join(srcfile.name.split("_")[:1])
                    project = project.replace("-US-", "_").replace("-SL-", "/")
                    subpath = "/".join(srcfile.name.split("_")[1:2]) + Path(srcfile).suffix
                    subpath = subpath.replace("-US-", "_").replace("-SL-", "/")
                    orig_path = Path("/code-imitator/data/dataset_github/dataset_github_filtered/") / author / project
                    macros_path = Path("/code-imitator/data/dataset_github/dataset_github_filtered_macrosremoved/") / author / project
                    tmp_dir = Path(tmp_path) / author / project
                    shutil.copytree(orig_path, tmp_dir)
                    os.system(f"cp -r {macros_path} {tmp_dir.parent}")
                    link = tmp_dir / subpath
                    link.unlink()
                    link.symlink_to(srcfile)
                    clangcompile_cmd[idx] = str(link)
                with open(srcfile, encoding="iso-8859-1") as f:
                    if re.search("typedef [^;]* bool;", f.read()) is not None:
                        clangcompile_cmd.append("-DBOOLTYPE")

                with open(details.error_file, "w") as f:
                    s = subprocess.run(clangcompile_cmd, stderr=f, stdout=f, cwd=link.parent if Config.multifilesetup else cwd)
                    s.check_returncode()
                infile = details.execute_cmd[1]
                outfile = details.execute_cmd[2]
                execute_process = subprocess.run(details.execute_cmd[0],
                                                 stdin=open(infile, "r"),
                                                 stderr=subprocess.DEVNULL,
                                                 stdout=open(outfile, "w"), cwd=cwd, env=preload_env)
                # if outfile is not None and (execute_process.stdout != b"" or not Path(details.execute_cmd[-1]).exists()):
                #     with open(details.execute_cmd[-1], "wb") as f:
                #         f.write(execute_process.stdout)
                assert (Path(outfile).exists())
                if len(details.clang_call_cmd) > 0:
                    clang_call_cmd = details.clang_call_cmd[0]
                    idx = 0
                    for idx, x in enumerate(clang_call_cmd):
                        if x.endswith((".c", ".h")) and not x.endswith("nocstd.h"):
                            break
                    if Config.multifilesetup:
                        clang_call_cmd[idx] = str(link)
                    with open(clang_call_cmd[idx], encoding="iso-8859-1") as f:
                        if re.search("typedef [^;]* bool;", f.read()) is not None:
                            clang_call_cmd.append("-DBOOLTYPE")
                    subprocess.run(clang_call_cmd, stderr=open(details.clang_call_cmd[1], "w"),
                                   stdout=open(details.clang_call_cmd[2], "w"), cwd=cwd)
            except Exception as e:
                print("Exception:", e)
                pass
            if len(details.lexems_call_cmd) > 0:
                lexems_call_cmd = details.lexems_call_cmd[0]
                if Config.multifilesetup:
                    idx = 0
                    for idx, x in enumerate(lexems_call_cmd):
                        if x.endswith((".c", ".h")) and not x.endswith("nocstd.h"):
                            break
                    lexems_call_cmd[idx] = str(link)
                subprocess.run(lexems_call_cmd, stderr=open(details.clang_call_cmd[1], "w"),
                            stdout=open(details.clang_call_cmd[2], "w"), cwd=cwd)

    def compile_hash(self, qualified_for_next_round: typing.List[typing.Tuple]):

        # I. COMPILE + HASH
        process_details = []
        for ix, inputparams in enumerate(self.inputlist):
            if qualified_for_next_round[ix] is False:
                continue

            curbbattinst: BBAttackInstance = inputparams[0]

            source_file_final = curbbattinst.source_file
            testfileout_test = os.path.join(os.path.dirname(curbbattinst.source_file), "A-small-practice_transformation.out")

            # D. check if transformation was successful
            error_file = os.path.join(source_file_final + ".compiled" + ".stderr")

            clangcompile_cmd, source_file_format_exe = evasion.utils_attack_workflow.get_compileclang_call(
                source_file=source_file_final,
                compilerflags=Config.flag_list_cpp if source_file_final.endswith(".cpp") else Config.flag_list_c)

            # D.2 Execute cmd...
            execute_cmd = (source_file_format_exe, curbbattinst.testfilein,
                           testfileout_test)

            # D.3 compute hash,
            #hashout_file = os.path.join(source_file_final + ".md5_hash")
            #hash_cmd = ["md5sum", testfileout_test, ">", hashout_file, "\n\n"]


            # F. Compute Features in parallel as well != BBAttackInstance,
            #    which takes around >1 min for all transf. if not parallelly done
            error_file_clang = os.path.join(source_file_final + ".clang" + ".stderr")
            error_file_lexems = os.path.join(source_file_final + ".lexems" + ".stderr")
            if self.dojoern:
                clang_call_cmd, _, clang_tarfile = evasion.utils_attack.get_clang_features_call(
                    src=source_file_final, output_dir=curbbattinst.attackdirauth)
                clang_call_cmd = (clang_call_cmd, error_file_clang, clang_tarfile)
            else:
                clang_call_cmd = []
            if self.dolexems:
                lexems_call_cmd, lexems_tarfile = evasion.utils_attack.get_lexems_features_call(
                    src=source_file_final, output_dir=curbbattinst.attackdirauth)
                lexems_call_cmd = (lexems_call_cmd, error_file_lexems, lexems_tarfile)
            else:
                lexems_call_cmd = []

            process_details.append(
                CompileDetails(clangcompile_cmd, error_file, execute_cmd, clang_call_cmd, lexems_call_cmd))

        pool = Pool(processes=self.noofcores)
        try:
            for _ in pool.imap_unordered(BBBatchAttackInstanceHandler.do_compile_hash, process_details):
                pass
        except Exception as e:
            pass
        finally:
            try:
                pool.terminate()
                pool.close()
            except BrokenPipeError:
                pass
            except Exception:
                pass

    def compile_hash_analysis(self, qualified_for_next_round: typing.List[typing.Tuple]):

        # II. ANALYSIS
        qualified_for_final_round = [False] * len(self.inputlist)
        for ix, inputparams in enumerate(self.inputlist):
            if qualified_for_next_round[ix] is False:
                continue

            curbbattinst: BBAttackInstance = inputparams[0]
            prefix = str(inputparams[1])
            simplified_cmdd_transform = self.simplified_calls[ix]

            try:
                source_file_final = curbbattinst.source_file
                error_file = os.path.join(source_file_final + ".compiled" + ".stderr")
                testfileout_test = os.path.join(os.path.dirname(curbbattinst.source_file),
                                                "A-small-practice_transformation.out")

                # Compilation Error?
                self.__check_error_file(error_file)

                #if "_github" not in curbbattinst.source_file and False: # TODO: Watchout! Only for github!
                # Output behaviour changed?
                transformedhash = evasion.utils_attack_workflow.computeHash(source_file=testfileout_test)
                if transformedhash != curbbattinst.originaloutputhash:
                    raise Exception("Output file has changed!!")

                # Feature problems?
                if self.dojoern:
                    error_file_clang = os.path.join(source_file_final + ".clang" + ".stderr")
                    self.__check_error_file(error_file_clang)

                if self.dolexems:
                    error_file_lexems = os.path.join(source_file_final + ".lexems" + ".stderr")
                    self.__check_error_file(error_file_lexems)


                # E. Prepare next iteration,
                # In contrast to BBAttackInstance, we save the final result in source_file, not in a temp file.
                # and if we have an error, we cp the original file to source_file != in BBAttackInstance, the other way round.
                qualified_for_final_round[ix] = True

            except Exception as e:
                curbbattinst.logger.error(
                    "`{}`, T-id:{}, compilation failed with: {}\n".format(simplified_cmdd_transform, prefix, e))
                # we restore the original file... TODO check if necessary
                source_file_copy = curbbattinst.source_file + ".original"
                os.rename(source_file_copy, curbbattinst.source_file)



        return qualified_for_final_round


    def __check_error_file(self, err_file: str):
        if not os.path.isfile(err_file):
            raise Exception(f"Error file {err_file} does not exist")

        if os.path.getsize(err_file) > 0:
            with open(err_file, "r") as f:
                lines = f.readlines()
            if not re.match(
                    "^(?:/usr/bin/ld: )?/tmp/[^\\\]*\\n[^:]*:[^:]*: (?:warning|Warnung): "
                    "the `gets' function is dangerous and should not be used\.\\n$",
                    "".join(lines)):
                raise Exception(str(lines))


    def model_prediction(self, qualified_for_final_round: typing.List[bool]):

        for ix, inputparams in enumerate(self.inputlist):
            ix: int = ix

            curbbattinst: BBAttackInstance = inputparams[0]
            source_file_rewritten = curbbattinst.source_file
            transf_call = self.simplified_calls[ix]
            transf_uid = self.unique_transformer_ids[ix]

            if qualified_for_final_round[ix] is True:
                # tranformation + format + compile + output was successfull, get model prediction now
                curbbattinst.get_model_prediction(source_file=source_file_rewritten,
                                                  target_class=curbbattinst.targetauthor.true_class,
                                                  verbose=0, already_extracted=True)

                curbbattinst.log_chosentransformers = curbbattinst.log_chosentransformers.append(
                    {'transformer_id': transf_uid, 'transformer_call': transf_call, 'success': True,
                     'score': curbbattinst.scoreprednew, 'class': curbbattinst.classprednew}, ignore_index=True)

                self.outputlist[ix] = (inputparams[1], inputparams[2], transf_call, True, curbbattinst.scoreprednew, curbbattinst.classprednew)

            else:
                self.outputlist[ix] = (inputparams[1], inputparams[2], transf_call, False, None, None)



    def __save_source_file(self, src_file: str, prefix: str, ending: str, bbatt: BBAttackInstance) -> str:

        if Config.savemorelogfiles:
            b = bbatt.get_source_log_file_target(src_file=src_file, prefix=prefix, ending=ending)
            return b
        else:
            return ""
