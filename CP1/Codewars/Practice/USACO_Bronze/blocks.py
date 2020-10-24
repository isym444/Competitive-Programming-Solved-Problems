import sys
import string
from collections import OrderedDict


""" sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")
 """
sys.stdin = open("blocks.in", "r")
sys.stdout = open("blocks.out", "w")

n = int(input())
inputarr = [0 for _ in range(n)]
finaldict1 = OrderedDict([("a", 0) for _ in range(26)])
""" {key: value for (key, value) in iterable} """
finaldict2 = OrderedDict([("a", 0) for _ in range(26)])
finaldict3 = OrderedDict([("a", 0) for _ in range(26)])
for i in string.ascii_lowercase:
    finaldict1[i] = 0
    finaldict2[i] = 0
    finaldict3[i] = 0
for i in range(n):
    inputarr[i] = list(input().split())
for i in inputarr:
    for j in i[0]:
        finaldict1[j] += 1
    for j in i[1]:
        finaldict2[j] += 1
    for j in string.ascii_lowercase:
        finaldict3[j] += max(finaldict1[j], finaldict2[j])
        finaldict1[j] = 0
        finaldict2[j] = 0
for i in finaldict3.values():
    print(i)