import sys
import itertools

""" sys.stdin = open("/Users/isym444/Desktop/PythonCP/cpp.in", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/cpp.out", "w") """

""" sys.stdin = open("shell.in", "r")
sys.stdout = open("shell.out", "w") """

a = int(input())
b = 1
while b == 1:
    a += 1
    d = list(map(int, str(a)))
    c = set(d)
    if len(c) == 4:
        print(a)
        b = 0