import sys

""" sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")
 """
sys.stdin = open("factory.in", "r")
sys.stdout = open("factory.out", "w")

n = int(input())

otpt = [0 for _ in range(101)]
inpt = [0 for _ in range(101)]

for i in range(n - 1):
    a = list(map(int, input().split()))
    otpt[a[0]] += 1
    inpt[a[1]] += 1


b = []
for i in range(1, n + 1):
    if otpt[i] == 0:
        b.append(i)

if len(b) == 1:
    print(b[0])
else:
    print(-1)