#!/bin/python

import sys

n = int(raw_input().strip())
phone_book = {}

for x in range(0, n):
    [name, phone] = raw_input().strip().split(' ')
    phone_book[name] = phone

while True:
    try:
        input = raw_input().strip()
    except EOFError:
        break

    if input in phone_book:
        sys.stdout.write(input + "=" + phone_book[input] + "\n")
    else:
        print "Not found"
