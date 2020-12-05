#!/usr/bin/env python3

def getAnswer(lines):
    for l1 in lines:
        for l2 in lines:
            for l3 in lines:
                if int(l1)+int(l2)+int(l3)==2020:
                    print (int(l1)*int(l2)*int(l3))
                    return

lines=[]
with open('tmp') as f:
    lines = f.readlines()
getAnswer(lines)


