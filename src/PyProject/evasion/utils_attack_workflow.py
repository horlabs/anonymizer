import shutil
import os
import subprocess
import hashlib
import typing
import re
import csv

import Configuration


def check_if_author_needs_reduced_testfile(authiid: str, author: str, call_instructions_csv_path: str) -> bool:
    """
    Check if author needs a reduced test file as input. Some authors (only very few)
    had some problems (especially for 8294486_5681755159789568) with some test cases.
    For these authors, we use a reduced test file with less test cases.
    :param authiid: the file that we want to attack.
    :param author: the author name
    :param call_instructions_csv_path: path to dataset_2017/call_database_authors/call_instructions.csv
    :return: true if reduced should be used.
    """
    with open(call_instructions_csv_path, 'r', encoding="UTF8") as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            if row["Author"] == author:
                problemid = "_".join([authiid.split("_")[0], authiid.split("_")[1]])
                if row["Use_Reduced_TestInput"] == "TRUE" and row["Problem"] == problemid:
                    return True

    return False



def create_dir_structure_forattack(datasetpath: str, attackdirauth: str, authiid: str, author: str) -> typing.Tuple[str, str]:
    """
    Creates the directory structure for the given author where all source files are located, feature files are calculated.
    Under the root dir defined by attack dir, we have the directory of the author, and there is the source file,
    adversarlly modified source file. We also create a log directory for saving some results.
    :param datasetpath: the path where the source files are located.
    :param attackdirauth: root directory of attack.
    :param authiid: the file that we want to attack.
    :param author: the author name
    :return a tuple with source file, and the log directory
    """

    if os.path.exists(attackdirauth):
        shutil.rmtree(attackdirauth)

    os.makedirs(attackdirauth)
    os.makedirs(os.path.join(attackdirauth,"log"))

    sourcefile = copy_sourcefile(datasetpath=datasetpath, attackdirauth=attackdirauth, authiid=authiid,
                                 author = author)

    return sourcefile, os.path.join(attackdirauth,"log")


def copy_sourcefile(datasetpath: str, attackdirauth: str, authiid: str, author: str) -> str:
    """
    copy the source file from dataset directory to given target directory.
    :param datasetpath: the path where the source files are located.
    :param attackdirauth: root directory of attack.
    :param authiid: the file that we want to attack.
    :param author: the author name
    :return the new path to source file
    """
    sourcefile = os.path.join(attackdirauth, authiid)
    assert (os.path.exists(os.path.join(datasetpath, author, authiid)))
    shutil.copyfile(os.path.join(datasetpath, author, authiid), sourcefile)
    return sourcefile


def copytestfile(testfilesdir: str, authiid: str, targettestfile: str, reduced: bool = False) -> None:
    """
    copy test file for cpp file.
    :param testfilesdir: the directory where the test files are located
    :param authiid: the file that we want to attack.
    :param targettestfile: where test file will be copied
    :param reduced: if true, then reduced test file will be loaded.
    """
    suffix = ".in" if reduced is False else "_reduced.in"

    assert (os.path.join(testfilesdir, authiid.split("_")[0], authiid.split("_")[1] + suffix))
    shutil.copyfile(os.path.join(testfilesdir, authiid.split("_")[0], authiid.split("_")[1] + suffix), targettestfile)


def get_compileclang_call(source_file: str, compilerflags: typing.List[str]):
    return ["clang++" if source_file.endswith(".cpp") else "clang", *compilerflags, source_file, "-o",
            os.path.splitext(source_file)[0]], \
           os.path.splitext(source_file)[0]


def compileclang(source_file: str, compilerflags: typing.List[str]) -> str:
    """
    Compiles source file via clang++
    :param source_file: the path to the source file
    :param compilerflags: some flags for the compiler...
    :return: the path to the executable
    """
    cmdd_clang, outfile = get_compileclang_call(source_file=source_file, compilerflags=compilerflags)

    p = subprocess.run(cmdd_clang, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=False, timeout=145)
    output, err = p.stdout, p.stderr

    err = re.sub(
        b"(?:/usr/bin/ld: )?/tmp/[^\\\]*\\n[^:]*:[^:]*: (?:warning|Warnung): the `gets' function is dangerous and should not be used\.\\n",
        b"", err)
    if err != b'':
        raise Exception("Compiling Clang Error:" + str(err))
    else:
        return outfile


def executecontestfile(source_file_executable: str, testfilein: str, testfileout: str) -> None:
    """
    Executes the source file.
    :param source_file_executable: the path to the executable.
    :param testfilein: the path to file containing the tests
    :param testfileout: the wanted path to file containing the outputs of tests
    """
    assert(os.path.exists(source_file_executable))

    # # A. Prepare Call Command
    cmdd_run = source_file_executable

    # New:
    timeouttime: int = 145*3
    # A. and B. Prepare Call Command depending on input / output behaviour
    preload_env = os.environ.copy()
    preload_env["LD_PRELOAD"] = Configuration.iohookspath
    preload_env["LD_LIBRARY_PATH"] = Configuration.customlibspath
    p = subprocess.run(cmdd_run, stdout=open(testfileout, 'w'), stderr=subprocess.PIPE, stdin=open(testfilein),
                       shell=False, timeout=timeouttime, env=preload_env)

    # C. Analyze output
    # output, err = p.stdout, p.stderr
    # p.check_returncode()
    # if p.returncode != 0 or p.returncode != 1:
    #     raise Exception(p.returncode)
    # we check the correct behaviour by comparing output file... since some author pipe s.th. into stderr


def get_clang_format_call(source_file: str):
    target_file: str = os.path.join(os.path.splitext(source_file)[0] + "_format." + source_file.split(".")[-1])
    cmdd_format = ["clang-format", source_file]
    return cmdd_format, target_file


def do_clang_format(source_file: str):
    """
    Calls clang-format on source file. Returns path to formatted file.
    :param source_file: path to source file.
    :return: path to new file that was processed by clang-format.
    """

    cmdd_format, target_file = get_clang_format_call(source_file=source_file)

    with open(target_file, 'w') as target:
        p = subprocess.run(cmdd_format, stdout=target, stderr=subprocess.PIPE, shell=False, timeout=145)
    output, err = p.stdout, p.stderr

    err = re.sub(b"(?:/usr/bin/ld: )?/tmp/[^\\\]*\\n[^:]*:[^:]*: (?:warning|Warnung): "
                 b"the `gets' function is dangerous and should not be used\.\\n", b"", err)
    if err != b'':
        raise Exception("Clang-format error:" + str(err))
    else:
        return target_file


def computeHash(source_file: str):
    hasher = hashlib.md5()
    with open(source_file, 'rb') as afile:
        buf = afile.read()
        hasher.update(buf)

    return hasher.hexdigest()