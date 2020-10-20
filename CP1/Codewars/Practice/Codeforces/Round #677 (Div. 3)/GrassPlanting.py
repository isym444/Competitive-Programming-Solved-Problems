import sys

""" sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")
 """
sys.stdin = open("planting.in", "r")
sys.stdout = open("planting.out", "w")

n = int(input())
degrees = {}
for i in range(n):
    degrees[i + 1] = 0
inpt = [[0, 0] for _ in range(n - 1)]
for i in range(n - 1):
    a = list(map(int, input().split()))
    inpt[i] = a
""" print(degrees)
print(inpt) """
for i in range(n - 1):
    a = inpt[i][0]
    b = inpt[i][1]
    degrees[a] += 1
    degrees[b] += 1
print(max(list(degrees.values())) + 1)
