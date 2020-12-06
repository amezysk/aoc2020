#!/usr/bin/env python3

lines=[]
with open('tmp') as f:
    lines = f.readlines()

first=1
total=0
for l in lines:
    if first==1:
        q=set(l)
        first=0
    elif l!="\n":
        q=q.intersection(set(l))
    else:
        q.discard("\n")
        first=1
        total=total+len(q)
        q.clear()

total=total+len(q)

print(total)