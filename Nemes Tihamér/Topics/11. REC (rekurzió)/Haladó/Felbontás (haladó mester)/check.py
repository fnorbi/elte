#!/usr/bin/env python3

# Ha kiiratod az összes megoldást egy fileba, majd beküldöd ennek, akkor végigcsekkolja

ok=True
for x in range(6561):
    orig, asd =input().split() 
    if(int(orig)!=int(eval(asd))):
        ok=False
        print(int(orig))
        print(int(eval(asd)))
print(ok)
