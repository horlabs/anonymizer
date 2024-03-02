###################################### ######################################
###                 This file removes all macros AND comments from a source file
###                 (excl. those macros that are coming from a header)
###                 Includes are preserved, BUT the position might be different*
###                 Consider: (*) The order of includes is remained, but if e.g. one include was after fct definition
###                     before, it will not be just at the beginning in the list of all includes
###                 Call: remove_macros_comments.py /path/inputfile.cpp /path/outputfile.cpp log-file.csv
###################################### ######################################
import argparse
import io
import os
import subprocess
import sys
import re
from tree_sitter import Language, Parser
from pathlib import Path
import random

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
C_LANG = Language("<path to treesitter c.so>", "c") # TODO: Path
parser = Parser()
parser.set_language(C_LANG)

# print(inputfile)
# print(outputfile)

try:
    ### Step 1. Read file and save all includes (INSTEAD OF USING //MACRO-REMOVAL as in remove_macros.py)
    #                   We exploit here the -P parameter instead.
    lines = [line.replace(".h>.", ".h>") for line in io.open(inputfile, "r", encoding="iso-8859-1")]
    nooflinesbefore: int = len(lines)

    includes_saved = {}
    tree = parser.parse("".join(lines).encode())
    query = C_LANG.query("(preproc_include) @include")
    indices = []
    for capture,_ in query.captures(tree.root_node):
        indices.append((capture.start_point[0], capture.start_point[1], capture.end_point[1]))
    for lineindex in range(len(lines)):
        lines[lineindex] = re.sub("/\* *\*/", "", lines[lineindex])
        lines[lineindex] = lines[lineindex].lstrip().replace("# include", "#include").replace("#include<", "#include <").replace("#include\"", "#include \"").replace("\t", " ")

    for lineindex, start, end in indices:
        #if lines[lineindex].startswith("#include "):
        include = lines[lineindex]
        #if start > 0:
        #    include = include[start:]
        #if end > 0:
        #    include = include[:end]
        idx = hex(random.randint(0x01000000, 0xFFFFFFFF))[1:]
        while idx in includes_saved:
            idx = hex(random.randint(0x01000000, 0xFFFFFFFF))[1:]
        includes_saved[idx] = include
        lines[lineindex] = lines[lineindex].replace("#include", "//MACRO-REMOVAL #include") + f"const int {idx} = 1337;\n"

        #re.sub("#[ \t]*include", "//MACRO-REMOVAL #include", lines[lineindex])
        #        #elif "#include" in lines[lineindex]:
        #    if not (lines[lineindex].strip().startswith(("//", "/*", "*", "\""))):
        #        print(lines[lineindex].strip())
        #        raise Exception("was not able to comment out include")

    include_guard = None
    for i in range(len(lines)):
        line = lines[i]
        if include_guard is not None and include_guard[0] == False:
            print(line)
            if f"#define {include_guard[1]}" in line:
                include_guard = (True, include_guard[1])
                lines = lines[:i] + [f"const int include_guard_{include_guard[1]}found = 1337;\n"] + lines[i:]
            else:
                include_guard = None
        
        m = re.search(r"#ifndef ([^ ]+_H_)", line)
        if m is not None:
            print(m)
            include_guard = (False, m.group(1))
    


    with io.open(outputfile, 'w', encoding="iso-8859-1") as file:
        for line in lines:
            file.write(line)

    ### Step 2. Call preprocessor
    compiler = "clang"
    if outputfile.endswith("cpp"):
        compiler = "clang++"
    cmdd_transform = [compiler, outputfile, "-E", "-P"]
    p = subprocess.run(cmdd_transform, stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=False, timeout=20, cwd=Path(inputfile).parent)
    err, output = p.stdout, p.stderr  # iwyu returns the output to stderr, so the other way round
    # if err != b'':
    #     print("Error for {} with {}".format(args.file, str(err)), file=sys.stderr)

    linesprep = [currow + "\n" for currow in err.decode("iso-8859-1").split("\n")]
    if linesprep[-1] == "\n":
        del linesprep[-1]

    ### Step 3. Add all includes again
    #linesprepfinal = includes_saved + linesprep
    linesprepfinal = []
    for line in linesprep:
        m = re.match("const int (x[a-z0-9]+) = 1337;\n", line)
        if m is not None:
            include = includes_saved[m.group(1)]
            line = line.replace(f"const int {m.group(1)} = 1337;", include)
        if include_guard is not None and line == f"const int include_guard_{include_guard[1]}found = 1337;\n":
            line = f"#ifndef {include_guard[1]}\n#define {include_guard[1]}\n"
        linesprepfinal.append(line)
    if include_guard is not None:
        linesprepfinal.append("#endif\n")


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
