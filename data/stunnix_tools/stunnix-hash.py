#! /usr/bin/env python3
import string
import hashlib
import random
import re
import argparse

parser = argparse.ArgumentParser(description="Mimic stunnix md5-symbol-hashing")
parser.add_argument("FILE", type=str, help="The file to modify")
parser.add_argument("--seed", "-s", default=None, type=str, help="Seed/Prefix for hashing")
parser.add_argument("--len", "-l", default=10, type=int, help="Length of md5 to be used as symbol")
parser.add_argument("--prefix", "-p", default="z", type=str, help="Prefix for the symbols (not starting with a digit)")

args = parser.parse_args()

with open(args.FILE, "r") as f:
    content = f.read()

if args.seed is None:
    salt = ''.join(random.SystemRandom().choices(string.ascii_uppercase + string.digits, k=5))
else:
    salt = args.seed

def hash_replace(symbol):
    symbol = salt + symbol[len("ReplacementFor_"):]
    h = hashlib.md5()
    h.update(symbol.encode())
    symbol = args.prefix+h.hexdigest()[:args.len]
    return symbol

replacement_prefix = r'ReplacementFor_[0-9a-zA-Z_]+'
last_end = 0
replaced = ""
for match in re.finditer(replacement_prefix, content):
    replaced += content[last_end:match.start()]+hash_replace(match.group(0))
    last_end = match.end()
replaced += content[last_end:]

with open(args.FILE, "w") as f:
    f.write(replaced)

