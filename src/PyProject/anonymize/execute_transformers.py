import argparse
import multiprocessing
import os
from multiprocessing import Pool
from multiprocessing.managers import BaseManager
from random import shuffle
from pathlib import Path

import Configuration
import ConfigurationGlobalLearning as Config
from anonymize.utils.Logger import Logger
from anonymize.utils.TestRunner import TestRunner

# Backup original AutoProxy function

backup_autoproxy = multiprocessing.managers.AutoProxy


# Defining a new AutoProxy that handles unwanted key argument 'manager_owned'
def redefined_autoproxy(token, serializer, manager=None, authkey=None,
                        exposed=None, incref=True, manager_owned=True):
    # Calling original AutoProxy without the unwanted key argument
    return backup_autoproxy(token, serializer, manager, authkey,
                            exposed, incref)


# Updating AutoProxy definition in multiprocessing.managers package
multiprocessing.managers.AutoProxy = redefined_autoproxy

transformers = [("itervar", "naming-transformers", []),
                ("bufname", "naming-transformers", []),
                ("numbering", "naming-transformers", []),
                ("gentypes", "typedef-transform", []),
                ("using_typedef", "typedef-transform", []),
                ("switch", "if-transformers", []),
                ("comma", "", []),
                ("compoundassign", "", []),
                ("main", "", []),
                ("multidecl", "", []),
                ("braces", "", []),
                ("ifelse", "if-transformers", []),
                ("unnecessaryreturn", "return-transform", []),
                ("voidreturn", "return-transform", []),
                ("flattenif", "if-transformers", []),
                ("paren", "", []),
                ("unused_typedefs", "unused-stuff", [])]


def do_test(transformer_ids, execute=False):
    if not isinstance(transformer_ids, list):
        transformer_ids = [transformer_ids]
    name = ""
    last_dir = None
    i = 0
    for transformer_id in transformer_ids:
        i += 1
        current_transformer = transformers[transformer_id]

        t_name, transformer_categorie, args = current_transformer
        if name != "":
            name += "_"
        name += t_name
        transformer_name = f"{t_name}_transformer"
        transformer_path = os.path.join(Config.repo_path, "src/LibToolingAST/cmake-build-release/transformers",
                                        transformer_categorie, transformer_name)
        test_dir = Configuration.datasetpath if last_dir is None else last_dir
        suffix = "_github_filtered_macrosremoved"

        manager = BaseManager()
        manager.register("Logger", Logger)
        manager.register("Tester", TestRunner)
        manager.start()
        man = multiprocessing.Manager()
        output_lock = man.Lock()
        success_lock = man.Lock()
        error_lock = man.Lock()
        process_lock = man.Lock()
        log = manager.Logger(output_lock, success_lock, error_lock, process_lock)

        log.info(f"Started test for transformer {transformer_name} with testfiles from {test_dir}")
        transformed_dir = os.path.join(Config.repo_path,
                                       f"/tmp/dataset_{name}{suffix}")
        last_dir = transformed_dir
        log.info(f"Write transformed files to {transformed_dir}")
        log.status("Collect testfiles...")
        if i < 0:
            continue
        test_files = [os.path.join(dp, f) for dp, dn, fn in os.walk(os.path.expanduser(test_dir)) for f in fn if
                      f.endswith((('.c', '.cpp', '.h')))]
        #if i == 1:
        #    with open("/code-imitator/obfus_files.txt") as f:
        #        test_files = f.read().strip().split("\n")

        test_files = [Path(test_dir) / Path(x) for x in test_files]
        test_files = [str(x) for x in test_files]
        shuffle(test_files)
        # test_files = ["/tmp/dataset_numbering_github_filtered_macrosremoved/bl0ckeduser/bl0ckeduser/symdiff/optimize.c"]

        log.end_status(f"{len(test_files)} testfiles found!")
        log.set_total(len(test_files))
        log.info("Start tests")

        pool = Pool(processes=10)
        success = []
        failed = []
        try:
            tester = manager.Tester(log, name, transformer_path, transformer_name, execute, transformed_dir, args,  
                                    dataset_path=test_dir)
            for r in pool.imap_unordered(tester.run_test, test_files):
                f, ok = r
                if ok:
                    success.append(f)
                else:
                    failed.append(f)

            log.end_status("All tests finished                                 ")
        except KeyboardInterrupt:
            log.end_status("Aborted by user                                    ")
        except Exception as e:
            import traceback
            log.status("                                                   ")
            log.end_status("Exception: " + str(e.__class__) + " " + str(e) + "\n" + traceback.format_exc())
        finally:
            try:
                pool.terminate()
                pool.close()
            except BrokenPipeError:
                pass
            except Exception:
                pass
            log.info(f"Succeeded {len(log.get_success())} of {log.get_total()} tests")
            log.info(f"{len(log.get_warnings())} warnings occurred")
            if len(log.get_warnings()) > 0:
                log.info("Warning(s) while processing files:")
                for file in log.get_warnings():
                    log.info(file)
            log.info(f"{len(log.get_errors())} errors occurred")
            if len(log.get_errors()) > 0 and False:
                log.info("Error(s) while processing files:")
                for file in log.get_errors():
                    log.info(file)
            if os.path.exists("output.txt"):
                os.remove("output.txt")
            if os.path.exists("out.txt"):
                os.remove("out.txt")
        with open(f"/code-imitator/transformer_{t_name}.error", "w") as f:
            f.write("\n".join(failed) + "\n" if len(failed) > 0 else "")
        with open(f"/code-imitator/transformer_{t_name}.success", "w") as f:
            f.write("\n".join(success) + "\n" if len(success) > 0 else "")
        if i == 400:
            break


def transformer2id(transformer_name):
    for idx, transformer in enumerate(transformers):
        if transformer[0] == transformer_name:
            return idx


if __name__ == "__main__":
    transformer_choices = ["itervar", "bufname", "gentypes", "numbering", "comma", "braces", "multidecl", "voidreturn",
                           "using_typedef", "paren", "ifelse", "switch", "compoundassign", "main", "unnecessaryreturn",
                           "flattenif"]
    parser = argparse.ArgumentParser()
    subparsers = parser.add_subparsers(dest="action")

    test_parser = subparsers.add_parser("test", help="Test specific transformer")
    test_parser.add_argument("-t", "--transformer", nargs="+",
                             choices=transformer_choices, required=True, help="Transformer to test")

    generate_parser = subparsers.add_parser("generate", help="Generate dataset using multiple transformers")
    generate_parser.add_argument("--numbering", action="store_true",
                                 help="Use numbering transformer instead of itervar and bufname")
    generate_parser.add_argument("--unused", action="store_true",
                                 help="Remove unused typedefs after gentypes and using-typedef")

    parser.add_argument("--test-output", action="store_true",
                        help="Test if the output of the transformed program equals the original output (--execute required)")
    parser.add_argument("--execute", action="store_true",
                        help="Execute the transformed program to test the output (--test-output required)")

    args = parser.parse_args()

    if args.action == "generate":
        transformer_ids = [transformer2id(x[0]) for x in transformers if
                           not (
                                   (args.numbering and (x[0] == "itervar" or x[0] == "bufname")) or
                                   (not args.numbering and x[0] == "numbering") or
                                   (not args.unused and x[0] == "unused_typedefs")
                           )]
    elif args.action == "test":
        transformer_ids = []
        mapping = {}
        for t in transformers:
            mapping[t[0]] = transformer2id(t[0])
        for ts in args.transformer:
            transformer_ids.append(mapping[ts])
    else:
        raise RuntimeError("Unknown subparser")

    """
    [("itervar", "naming-transformers", []),         0
     ("bufname", "naming-transformers", []),         1
     ("numbering", "naming-transformers", []),       2
     ("gentypes", "typedef-transform", []),          3
     ("using_typedef", "typedef-transform", []),     4
     ("switch", "if-transformers", []),              5
     ("comma", "", []),                              6
     ("compoundassign", "", []),                     7
     ("ifelse", "if-transformers", []),              8
     ("main", "", []),                               9
     ("multidecl", "", []),                         10
     ("braces", "", []),                            11
     ("unnecessaryreturn", "return-transform", []), 12
     ("voidreturn", "return-transform", []),        13
     ("flattenif", "if-transformers", []),          14
     ("paren", "", []),                             15
     ("unused_typedefs", "unused-stuff", [])]       16
     """

    # transformer_ids = [0,1,3,4,   8,14,   15]

    execute = (args.test_output and args.execute)
    try:
        do_test(transformer_ids, execute=execute)
    except BrokenPipeError:
        pass
    except KeyboardInterrupt:
        pass

