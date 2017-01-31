#!/bin/python

import sys

n = int(raw_input().strip())

# If  is odd, print Weird
if (n & 1) == 1:
    print "Weird"
#   If  is even and in the inclusive range of 2 to 5, print Not Weird
elif n in range(2, 6):
    print "Not Weird"
# If  is even and in the inclusive range of  6 to 20, print Weird
elif n in range(6, 21):
    print "Weird"
#  If  is even and greater than 20, print Not Weird
elif n > 20:
    print "Not Weird"
