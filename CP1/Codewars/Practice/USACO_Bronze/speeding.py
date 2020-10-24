import sys

"""
sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")
 """
sys.stdin = open("speeding.in", "r")
sys.stdout = open("speeding.out", "w")

"""limitarr=[]
cowarr=[]
for i in range(N):
    unitarr.append(a[i])
for i in range(N,2N):
    cowarr.append()"""

N, M = list(map(int, input().split()))
limitarr = []
cowarr = []
maxover = 0
for i in range(N):
    a, b = list(map(int, input().split()))
    [limitarr.append(b) for _ in range(a)]
for i in range(N):
    a, b = list(map(int, input().split()))
    [cowarr.append(b) for _ in range(a)]
for i in range(100):
    if cowarr[i] > limitarr[i] and cowarr[i] - limitarr[i] > maxover:
        maxover = cowarr[i] - limitarr[i]
print(maxover)
