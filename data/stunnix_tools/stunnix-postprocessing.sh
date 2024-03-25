#! /bin/bash

find $1 -type f -iname "*.c" -o -iname "*.h" | parallel --bar ./collapse_obfuscated_lines.py
find $1 -type f -iname "*.c" -o -iname "*.h" | parallel --bar  clang-format -i
find $1 -type f -iname "*.c" -o -iname "*.h" | parallel --bar ./stunnix-fix.py
find $1 -type f -iname "*.c" -o -iname "*.h" | parallel --bar ./stunnix-hash.py
