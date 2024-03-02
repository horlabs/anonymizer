import os
import re
import shutil
import subprocess
import sys
import tempfile
import typing
from pathlib import Path

import Configuration


def extractfeatures_arff(src: str, input_dir: typing.Optional[str], output_dir: str) -> str:
    if input_dir is None:
        # input-dir is None, means we have not already extracted the features before, so let's do it now!

        targetfile: str = os.path.join(output_dir, "lexical_features.arff")

        if Configuration.naivebaselinecmd is None:
            raise Exception("Use Arff is set to True, but no java feature extraction dir was specified")

        cmdd_transform = ["java -jar", Configuration.naivebaselinecmd, src, targetfile]
        cmdd_transform = " ".join(cmdd_transform)
        p = subprocess.run(cmdd_transform, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True, timeout=145)
        output, err = p.stdout, p.stderr
        if err != b'':
            print("Error while loading new arff features for object:" + src, file=sys.stderr)
            raise Exception("arff feature extraction failure:" + str(err))

        return targetfile
    else:
        return os.path.join(input_dir, "lexical_features.arff")


def extractfeatures_clang(src: str, input_dir: typing.Optional[str], output_dir: str,
                          featureclassidentifier: str) -> dict:
    if featureclassidentifier == "lexems_features":
        return _extractfeatures_clang_lexems(src=src, input_dir=input_dir, output_dir=output_dir,
                                             featureclassidentifier=featureclassidentifier)
    else:
        return _extractfeatures_clang_default(src=src, input_dir=input_dir, output_dir=output_dir,
                                              featureclassidentifier=featureclassidentifier)


def _extractfeatures_clang_lexems(src: str, input_dir: typing.Optional[str], output_dir: str,
                                  featureclassidentifier: str) -> dict:
    if input_dir is None:
        # input-dir is None, means we have not already extracted the features before, so let's do it now!
        if not Path(src).is_file():
            raise NotImplementedError("if input-dir is not given, we can only extract features from one file here!")

        cmdd_transform, targetfile = get_lexems_features_call(src=src, output_dir=output_dir)
        p = subprocess.run(cmdd_transform, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=False, timeout=300)

        output, err = p.stdout, p.stderr
        if err != b'':
            print("Error while loading new lexems features for object:" + src + "call:" + str(cmdd_transform),
                  file=sys.stderr)
            print("Error: {}".format(str(err)), file=sys.stderr)
            raise Exception("feature lexem extraction failure:" + str(err))
        output_lexems = str(output.decode("ISO-8859-1"))
    else:
        _, targetfile = get_lexems_features_call(src=src, output_dir=input_dir)
        assert (os.path.isfile(targetfile))
        # with open(targetfile, "r", encoding='ISO-8859-1') as f:
        #     output = f.readlines()
        #     output_lexems = "".join(output)

    lexems = {featureclassidentifier + ".dat": targetfile}
    return lexems


def _extractfeatures_clang_default(src: str, input_dir: typing.Optional[str], output_dir: str,
                                   featureclassidentifier: str) -> dict:
    if input_dir is None:
        # input-dir is None, means we have not already extracted the features before, so let's do it now!
        if not Path(src).is_file():
            raise NotImplementedError("if input-dir is not given, we can only extract features from one file here!")

        cmdd_transform, call_options, targetfile = get_clang_features_call(src=src, output_dir=output_dir)

        with tempfile.TemporaryDirectory() as tmp_path:
            if Configuration.multifilesetup:
                author = Path(src).parent.name
                project = "/".join(Path(src).name.split("_")[:1])
                project = project.replace("-US-", "_").replace("-SL-", "/")
                subpath = "/".join(Path(src).name.split("_")[1:2])
                subpath = subpath.replace("-US-", "_").replace("-SL-", "/") + Path(src).suffix
                orig_path = Path("/code-imitator/data/dataset_github/dataset_github_filtered/") / author / project
                macros_path = Path("/code-imitator/data/dataset_github/dataset_github_filtered_macrosremoved/") / author / project
                tmp_dir = Path(tmp_path) / author / project
                shutil.copytree(orig_path, tmp_dir)
                os.system(f"cp -r {macros_path} {tmp_dir.parent}")
                link = tmp_dir / subpath
                link.unlink()
                link.symlink_to(Path(src))
                cmdd_transform = [x if x != src else str(link) for x in cmdd_transform]
                
            with open(src, encoding="iso-8859-1") as f:
                if re.search("typedef [^;]* bool;", f.read()) is not None:
                    cmdd_transform.append("-DBOOLTYPE")

            p = subprocess.run(cmdd_transform, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=False, timeout=900)

        output, err = p.stdout, p.stderr
        if err != b'':
            print("Error while loading new features for object:" + src + "call:" + str(cmdd_transform), file=sys.stderr)
            print("Error: {}".format(str(err)), file=sys.stderr)
            raise Exception("feature extraction failure:" + str(err))
        output_clang = str(output.decode("ISO-8859-1"))

        # now we need to parse the output so that we get a string for each feature class
        dict_clang = extract_features_fromfeatureextraction(output=output_clang,
                                                            call_options=call_options)
    else:
        targetfile = os.path.join(input_dir, featureclassidentifier + ".dat")
        assert os.path.isfile(targetfile), f"File not found: {targetfile}"
        # with open(targetfile, "r", encoding='ISO-8859-1') as f:
        #     output = f.readlines()
        #     output_clang = "".join(output)

        dict_clang = {featureclassidentifier + ".dat": targetfile}

    return dict_clang


########################################################################################################################

def get_clang_features_call(src: str, output_dir: str):
    call_options = ["-ast_node_bigram=True", "-ast_node_types=True", "-ast_node_types_avg_dep=True",
                    "-max_depth_ast_node=True", "-code_in_ast_leaves=True", "-code_in_ast_leaves_avg_dep=True",
                    "-lexical_features=True"]

    cmdd_transform = [os.path.join(Configuration.featureextractordir_single, "feature_extraction_single"),
                      src, *call_options, "--", "-I", os.path.join(Configuration.repo_path, "src/LibToolingAST")]

    if src.endswith(".cpp"):
        cmdd_transform.extend(Configuration.flag_list_cpp)
    else:
        cmdd_transform.extend(Configuration.flag_list_c)

    tarfile = os.path.join(output_dir, "clang_features.dat")
    return cmdd_transform, call_options, tarfile


def get_lexems_features_call(src: str, output_dir: str):
    cmdd_transform = [os.path.join(Configuration.featureextractordir, "get_lexems_features"),
                      src, "--", *(Configuration.flag_list_cpp if src.endswith(".cpp") else Configuration.flag_list_c)]
    tarfile = os.path.join(output_dir, "lexems_features.dat")
    return cmdd_transform, tarfile


def extract_features_fromfeatureextraction(output: str, call_options: typing.List[str]) -> typing.Dict[
    str, typing.List[str]]:
    """
    Extract feature strings for each feature class (such as bigrams, ast node types, ...).
    Use this method if we use feature_extraction_single (our clang tool) that outputs all various types per row.
    :param output: the output from feature_extraction_single
    :param call_options: the call options for feature_extraction_single
    :return:
    """

    results = {}

    rows = output.split("\n")
    # assert (len(rows)-1) == len(call_options) # the last row is ''
    if (len(rows) - 1) != len(call_options):
        print("len", len(rows) - 1, ",", len(call_options), file=sys.stderr)
        raise Exception(f"extract features single error: len {len(rows) - 1}, {len(call_options)}")
    for r in rows:
        if r != '':
            rowsplit = r.split("::--::")
            assert len(rowsplit) == 2  # should only be the feature class and the feature name

            featuretype, featurestring = rowsplit[0].strip(), rowsplit[1] + "\n"
            results[featuretype] = [featurestring]

    return results
