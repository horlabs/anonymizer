#!/usr/bin/env python3

import sys
import re
import random
import string

if len(sys.argv) < 2 or len(sys.argv) > 3:
    print(f"Usage: {sys.argv[0]} [<SEED>] <FILE>")
    exit()

if len(sys.argv) == 3:
    seed = int(sys.argv[1])
    if seed == 0:
        seed = random.SystemRandom().random()
    random.seed(seed)
else:
    random.seed(1337)

with open(sys.argv[-1]) as f:
    content = f.read()

include_re = re.compile("(?<=#include )\"[^\"]+\"")
includes = []
for match in re.findall(include_re, content):
    includes.append(match)

limited_re = re.compile("(?:\[[0-9a-fx]+\] = )(?:\{)?\"[^\"]+\"")
limited = []
for match in re.findall(limited_re, content):
    limited.append("\"" + "\"".join(match.split("\"")[1:]))

string_re = re.compile("\"[^\"]*\"")
replaced = []
for match in re.findall(string_re, content):
    if match in includes:
        continue
    if match in limited:
        continue
    if match in replaced:
        continue
    if content[content.index(match)+len(match):content.index(match)+len(match)+5].strip(" ").startswith("\n"):
        continue
    replacement = match
    if len(match) < 50:
        replacement = match[:-1] + "\\0X" + ''.join(random.choices(string.ascii_uppercase + string.ascii_lowercase + string.digits, k=50-len(match)-2)) + "\""
        #replacement = match[:-1] + "\\0" + ''.join(random.choices("x", k=50-len(match)-1)) + "\""
        replaced.append(match)
    content = content.replace(match, replacement)

print(content)

