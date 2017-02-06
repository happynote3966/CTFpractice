# -*- coding:utf-8 -*-

import sys
import base64

s = sys.argv[1]

print(base64.b64decode(s))
