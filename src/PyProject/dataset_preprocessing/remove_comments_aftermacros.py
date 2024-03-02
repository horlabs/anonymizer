###################################### ######################################
###                 This file removes all comments from a source file
###                 (excl. those macros that are coming from a header).
###                 Run this script ONLY AFTER removing macros via "remove_macros.py". Although
###                     this file also removes macros, it can give problems with includes. So we need two steps!(*)
###                 Includes are preserved, BUT the position might be different(**)
###                 Call: remove_macros_comments.py /path/inputfile.cpp /path/outputfile.cpp log-file.csv
###################################### ######################################

# (*) Consider vexorian as author who uses #ifdef X, include X, else: include Y.
# This script here would leave both includes X and Y, but if we call remove_macros.py, this script will correctly
# leave only the one that is defined, and then we can call this script here to remove all comments.
#
# (**) The order of includes is remained, but if e.g. one include was after fct definition
#                     before, it will not be just at the beginning in the list of all includes

import argparse
import io
import os
import subprocess
import sys


def remove_comments(inputfile: str, outputfile: str, csvfile: str):
    # print(inputfile)
    # print(outputfile)

    try:
        ### Step 1. Read file and save all includes (INSTEAD OF USING //MACRO-REMOVAL as in remove_macros.py)
        #                   We exploit here the -P parameter instead.
        lines = [line for line in io.open(inputfile, "r", encoding="iso-8859-1")]
        nooflinesbefore: int = len(lines)

        includes_saved = []
        for lineindex in range(len(lines)):
            if lines[lineindex].startswith("#include "):
                includes_saved.append(lines[lineindex])
                lines[lineindex] = lines[lineindex].replace("#include", "//MACRO-REMOVAL #include")
            elif "#include" in lines[lineindex]:
                if not (lines[lineindex].startswith("//") or lines[lineindex].startswith("/*")):
                    raise Exception("was not able to comment out include")

        with io.open(outputfile, 'w', encoding="iso-8859-1") as file:
            for line in lines:
                file.write(line)

        ### Step 2. Call preprocessor
        cmdd_transform = ["clang++", outputfile, "-E", "-P"]
        p = subprocess.run(cmdd_transform, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=False, timeout=20)
        err, output = p.stdout, p.stderr  # iwyu returns the output to stderr, so the other way round
        # if err != b'':
        #     print("Error for {} with {}".format(args.file, str(err)), file=sys.stderr)

        linesprep = [currow + "\n" for currow in err.decode("iso-8859-1").split("\n")]
        if linesprep[-1] == "\n":
            del linesprep[-1]

        ### Step 3. Add all includes again
        linesprepfinal = includes_saved + linesprep

        ### Step 4. save file
        with io.open(outputfile, 'w', encoding="iso-8859-1") as file:
            for lineindex in range(len(linesprepfinal)):
                file.write(linesprepfinal[lineindex])

        ### Step 5. Log number of lines before and after removing macros -- helpful to detect errors,
        # e.g. if some header was included by mistake, just rough estimate, should measure via wc-l afterwards ;)

        with open(csvfile, "a") as currentfile:
            newstring: str = "{},{},{}\n".format(inputfile, nooflinesbefore, len(linesprepfinal))
            currentfile.write(newstring)


    except Exception as e:
        print("ERROR for {}".format(inputfile), file=sys.stderr)
        print(str(e), file=sys.stderr)

        if os.path.exists(outputfile):
            os.remove(outputfile)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Expand all macros from file while keeping includes')
    parser.add_argument('file', type=str, nargs=1,
                        help='the file that we want to preprocess')
    parser.add_argument('output', type=str, nargs=1,
                        help='output file')
    parser.add_argument('csvfile', type=str, nargs=1,
                        help='csv file, number of lines before and after will be saved in csv')
    args = parser.parse_args()

    inputfile: str = args.file[0]
    outputfile: str = args.output[0]
    csvfile: str = args.csvfile[0]

    remove_comments(inputfile, outputfile, csvfile)
