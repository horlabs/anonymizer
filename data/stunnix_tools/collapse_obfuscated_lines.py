#!/bin/env python3
import sys
try:
    with open(sys.argv[1], "r") as f:
        lines = f.readlines()
    lines = [line.strip() for line in lines]
    out = ""
    tmp = []
    for line in lines:
        out += line
        if line.endswith("\\"):
            out = out[:-1]
            continue
        tmp.append(out)
        out = ""
    
    lines = []
    for line in tmp:
        if line.startswith("#") and len(out) > 0:
            lines.append(out)
            out = ""
        if line.startswith("#"):
            lines.append(line)
            continue
        if len(lines) > 0 and lines[-1].startswith("#"):
            lines.append("")
        out += line + " "
    lines.append(out)
    
    with open(sys.argv[1], "w") as f:
        f.write("\n".join(lines))
        f.write("\n")
except UnicodeDecodeError as e:
    print(sys.argv[1], ":", e)
