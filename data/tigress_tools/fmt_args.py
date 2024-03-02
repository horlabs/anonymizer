#!/usr/bin/env python3

import sys

with open(sys.argv[1]) as f:
    content = f.read()

functions = [
        (" printf(", 6),
        (" scanf(", 6),
        (" fprintf(", 7),
        (" fscanf(", 7),
        (" sprintf(", 7),
        (" sscanf(", 7)
    ]

for name, arg_num in functions:
    i = 0
    try:
        while True:
            i = content.index(name, i)
            j = i + len(name)
            args = []
            tmp_arg = ""
            braces = 1
            while braces > 0:
                if content[j] == "(":
                    braces += 1
                elif content[j] == ")":
                    braces -= 1
                if (braces == 1 and content[j] == ",") or braces == 0:
                    args.append(tmp_arg.strip())
                    tmp_arg = ""
                else:
                    tmp_arg += content[j]
                j += 1
        
            if len(args) < arg_num:
                insert_arg = args[-1].replace("--", "")
                insert_arg = insert_arg.replace("++", "")
                content = content[:i] + name + ", ".join(args + [insert_arg]*(arg_num-len(args))) + ")" + content[j:]
            i = j
    except ValueError:
        pass

with open(sys.argv[1], "w") as f:
    f.write(content)

