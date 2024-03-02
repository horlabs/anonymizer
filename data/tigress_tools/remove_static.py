#!/usr/bin/env python
import re
import sys
import get_qsort_callback

with open(sys.argv[1], encoding="iso-8859-1") as f:
    content = f.read()

callbacks = get_qsort_callback.main(sys.argv[1])

for x in re.findall("((?:inline)?)((?:static *)?)((?:inline *)?)((?:long|unsigned|signed)?)( *[a-zA-Z0-9_]+[ *]+)([a-zA-Z0-9\$_]+)(\([^};]*?\) *)", content): #1,3,4,5
    if x[5] in callbacks:
        continue
    content = content.replace("".join(x), "".join((x[0],)+x[2:]))

with open(sys.argv[1], "w", encoding="iso-8859-1") as f:
    f.write(content)
