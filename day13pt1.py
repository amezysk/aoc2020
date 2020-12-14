#!/usr/bin/env python3

import math

lines=[]
with open('tmp') as f:
    lines = f.readlines()

prev=1
min = int(lines[0])
currMax=0
currBus=""
time=min
buses=lines[1].split(",")
for b in buses:
    if b!="x":
        c= (min%int(b))/int(b)
        if (currMax<c):
            currMax=c
            currBus=int(b)
            time = int(min/int(b))*int(b)+int(b)

       
print(currBus*(time-min))

