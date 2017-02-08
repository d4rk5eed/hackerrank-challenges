#!/bin/python

import sys

def hourglass(arr, y, x):
    return arr[y][x] + arr[y][x+1] + arr[y][x+2] + arr[y+1][x+1] + arr[y+2][x] + arr[y+2][x+1] + arr[y+2][x+2]

arr = []
for arr_i in xrange(6):
   arr_temp = map(int,raw_input().strip().split(' '))
   arr.append(arr_temp)

sums = []
for y in range(4):
    for x in range(4):
        sums.append(hourglass(arr, x, y))

print max(sums)
