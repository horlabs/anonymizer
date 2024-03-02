#! /usr/bin/env python3
import re
import sys

with open(sys.argv[1], "rb") as f:
    content = f.read()
    content = re.sub(b"\n+{", b" {", content)

with open(sys.argv[1], "wb") as f:
    f.write(content)
