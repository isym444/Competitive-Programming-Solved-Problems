import sys
import itertools

""" from math import comb """
import operator as op
from functools import reduce


def ncr(n, r):
    r = min(r, n - r)
    numer = reduce(op.mul, range(n, n - r, -1), 1)
    denom = reduce(op.mul, range(1, r + 1), 1)
    return numer // denom  # or / in Python 2


sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")

""" sys.stdin = open("citystate.in", "r")
sys.stdout = open("citystate.out", "w") """

n = int(input())
d = {}
for i in range(n):
    a = input()
    b = a[0:2] + a[-1:-3:-1]
    c = sorted(b)
    c = "".join(c)
    """ print(c) """
    if c in d:
        d[c] += 1
    else:
        d[c] = 1
keys = list(d.keys())
values = list(d.values())
ans = 0
for i in range(len(values)):
    if values[i] > 1:
        ans += values[i]  # len(itertools.combinations(range(values[i] - 1), 2))
print(ans)