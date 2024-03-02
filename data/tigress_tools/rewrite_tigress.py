#!/usr/bin/env python3

import hashlib
import re
import sys
import secrets

salt = secrets.token_bytes(16)

with open(sys.argv[1], "r") as f:
    content = f.read()

dlsym = re.compile(" *o___[0-9]+\([0-9]+, o___[0-9]+\);\n *l___[0-9]+ = dlsym\(\(void \*\)[0-9]+, o___[0-9]+\);\n *o___[0-9]+\[[0-9]+\] = l___[0-9]+;", re.MULTILINE)

gotolabel = re.compile("_[0-9+]_[a-zA-Z0-9$_]+")
names = re.compile("[olft]___[0-9]+")

for match in re.finditer(dlsym, content):
    #print(match.group(0))
    pass

l = []

for match in re.finditer(gotolabel, content):
    l.append(match.group(0))

for match in re.finditer(names, content):
    l.append(match.group(0))

s = set(l)
m = {}
for x in s:
    #h = hashlib.sha256()
    h = hashlib.md5()
    h.update(salt + x.encode())
    m[x] = f"l{h.hexdigest()}"
    content = content.replace(x, m[x])

content = re.sub("(__restrict|__format) *", "", content)

with open(sys.argv[1], "w") as f:
    f.write(content)
