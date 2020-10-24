import sys

""" sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")
 """
sys.stdin = open("outofplace.in", "r")
sys.stdout = open("outofplace.out", "w")

""" traverse through list
#if n+1<n:
    #a=index(n+1)
counter=-1
b = sort original
traverse through indexes
if b!=original counter+=1"""

n = int(input())
a = [0 for _ in range(n)]
for i in range(n):
    a[i] = int(input())
b = sorted(a)
counter = -1
for i in range(n):
    if a[i] != b[i]:
        counter += 1
print(counter)