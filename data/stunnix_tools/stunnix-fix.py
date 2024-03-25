#!/usr/bin/env python3

import sys
from pathlib import Path
import re

with open(sys.argv[1], "r") as f:
    content = f.read()

content = re.sub('in[\n]{0,1}\.[\n]{0,1}tie[\n]{0,1}\([\n]{0,1}\([\n]{0,1}[a-fx0-9+\n-]+\)[\n]{0,1}\)', 'in.tie(0)', content)
content = re.sub('out[\n]{0,1}\.[\n]{0,1}tie[\n]{0,1}\([\n]{0,1}\([\n]{0,1}[a-fx0-9+\n-]+\)[\n]{0,1}\)', 'out.tie(0)', content)
content = re.sub('time\(\([0-9a-fx+-]+\)\)', "time(0)", content)

with open(sys.argv[1], "w") as f:
    f.write(content)