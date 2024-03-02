#!/usr/bin/env python
import sys
import re

def main(filename):
    with open(filename, encoding="iso-8859-1") as f:
        content = f.read()
    
    callbacks = []
    
    for qsort in re.finditer("\sqsort(_r)?\(", content):
        depth = 1
        for offset in range(qsort.start()+len(qsort.group(0)), len(content)):
            if content[offset] == "(":
                depth += 1
            if content[offset] == ")":
                depth -= 1
            if depth == 0:
                break
        for start in range(offset-1, qsort.start(), -1):
            if content[start] in "), ":
                break
        if content[start+1:offset] in ["strcmp"]:
            continue
        if len(content[start+1:offset]) == 0:
            continue
        callbacks.append(content[start+1:offset])
    
    for bsearch in re.finditer("(\s|\))(signal|bSort|bsearch)\(", content):
        depth = 1
        for offset in range(bsearch.start()+len(bsearch.group(0)), len(content)):
            if content[offset] == "(":
                depth += 1
            if content[offset] == ")":
                depth -= 1
            if depth == 0:
                break
        for start in range(offset-1, bsearch.start(), -1):
            if content[start] in "), ":
                break
        if content[start+1:offset] in ["strcmp"]:
            continue
        if len(content[start+1:offset]) == 0:
            continue
        callbacks.append(content[start+1:offset])
    
    for pthread in re.finditer("\spthread_create\(", content):
        depth = 1
        arg_offsets = [pthread.start()+len(pthread.group(0))]
        for offset in range(pthread.start()+len(pthread.group(0)), len(content)):
            if content[offset] == "(":
                depth += 1
            if content[offset] == ")":
                depth -= 1
            if depth == 0:
                arg_offsets.append(offset)
                break
            if content[offset] == "," and depth == 1:
                arg_offsets.append(offset)
        if len(arg_offsets) < 4:
            print(pthread)
            assert False
        start = arg_offsets[2]
        offset = arg_offsets[3]
        if content[start+1:offset] in ["strcmp"]:
            continue
        if len(content[start+1:offset]) == 0:
            continue
        callbacks.append(content[start+1:offset].strip())
    
    callbacks = [x.lstrip("&*") for x in set(callbacks)]
    
    return callbacks

if __name__ == "__main__":
    callbacks = main(sys.argv[1])
    print(",".join(callbacks))
