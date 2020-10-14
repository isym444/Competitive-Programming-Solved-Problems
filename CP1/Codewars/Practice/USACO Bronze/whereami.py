import sys

""" sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")
 """
sys.stdin = open("whereami.in", "r")
sys.stdout = open("whereami.out", "w")

n = int(input())
A = input()
breaker = 0
for i in range(n):
    checker = []
    breaker = 0
    for j in range(n):
        if i + 1 + j <= n and breaker == 0:
            b = A[j : i + 1 + j]
            if len(b) > 1 and breaker == 0:
                if b not in checker:
                    checker.append(b)
                else:
                    breaker = 1
    if len(checker) == n - len(b) + 1:
        print(len(b))
        break
