#!/bin/python

import sys

n = int(raw_input().strip())

for i in range(0, n):
    str = raw_input().strip()
    for c in range(0, len(str), 2):
        sys.stdout.write(str[c])
    sys.stdout.write(" ")
    for c in range(1, len(str), 2):
        sys.stdout.write(str[c])
    sys.stdout.write("\n")
