import sys

""" sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")
 """
sys.stdin = open("gymnastics.in", "r")
sys.stdout = open("gymnastics.out", "w")

""" n, k = map(int, input().split())

a = []
a = list(map(int, input().split()))
const = 0
for i in range(k):
    const += i

for i in range(1, n):
    b = []
    b = list(map(int, input().split()))
    for j in b:
        if b.index(j) < a.index(j):
            const -= a.index(j) - b.index(j)
print(const) """

n, k = map(int, input().split())
const = 0
a = []
for i in range(0, n):
    b = []
    b = list(map(int, input().split()))
    a.append(b)
""" print(a) """
""" for i in range(n):
    for j in range(k):
        for k in range(j + 1, k):
            if a[i].index(a[i][j]) > a[i].index(a[i][k]):
                pass """
for i in range(0, k):
    for j in range(i + 1, k):
        checker = 0
        for t in range(n):
            q = a[t].index(a[0][i])
            w = a[t].index(a[0][j])
            if q < w:
                checker += 1
            if checker == n:
                const += 1
print(const)


""" extract pair per for loop """