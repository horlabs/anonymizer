#! /usr/bin/env python

import re
import sys

with open(sys.argv[1], encoding="iso-8859-1") as f:
    content = f.read()

content = re.sub("\nmain\(int ", "int main(int ", content)
changed = False

mainf = """#ifndef _MAINF_H_
#define _MAINF_H_
int mainf(int argc, char** argv) {
    return 0;
}
#endif
"""

match = re.search("\n\[ \t]*int main\(int \[^;{]+\)[^;]", content)
if match is not None:
    depth = 0
    in_main_fun = False
    for end in range(match.start(), len(content)):
        if content[end] == "{":
            depth += 1
            in_main_fun = True
        elif content[end] == "}":
            depth -= 1

        if in_main_fun and depth == 0:
            break

    main = content[match.start():end+1]
    if "return" not in main:
        content = content[:end] + "return 0;\n" + content[end:]
        changed = True
else:
    lines = content.split("\n")
    while lines[-1] == "":
        del lines[-1]
    if "#endif" in lines[-1]:
        lines = lines[:-1] + [mainf] + lines[-1:]
    else:
        lines.append(mainf)
    content = "\n".join(lines)
    changed = True

if changed:
    with open(sys.argv[1], "w", encoding="iso-8859-1") as f:
        f.write(content)