import sys
from typing import KeysView

""" sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")
 """
""" sys.stdin = open("shell.in", "r")
sys.stdout = open("shell.out", "w") """

a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = {}
for i in range(len(b)):
    c[i + 1] = b[i]
t = 0
""" for i in b:
    for j in b:
        if i == j:
            pass
        elif t == 0:
            c = i + j
            if c == a[1]:
                print(b.index(i) + 1, b.index(j) + 1)
                t = 1
                break """
keys = list(c.keys())
values = list(c.values())
for i in values:
    d = a[1] - i
    if d in values and t == 0 and len(values) > 1:  # and values.index(i) != values.index(d):
        print(keys[values.index(i)], keys[values.index(d)])
        t = 1

if t == 0:
    print("IMPOSSIBLE")