import sys

sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")

""" sys.stdin = open("factory.in", "r")
sys.stdout = open("factory.out", "w") """

""" there must be a RH number that appears n-1 times """

n = int(input())
a = []
for i in sys.stdin:
    a.append(list(map(int, i.split())))
""" print(a) """
b = {}
for i in range(1, n + 1):
    b[i] = 0
""" print(b) """
for i in a:
    b[i[1]] += 1
checker = 0
for i in range(1, n + 1):
    if b[i] == n - 1:
        print(i)
        checker = 1
        break
if checker == 0:
    print(-1)