import sys

sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")

""" sys.stdin = open("mixmilk.in", "r")
sys.stdout = open("mixmilk.out", "w") """

c1, m1 = map(int, input().split())
c2, m2 = map(int, input().split())
c3, m3 = map(int, input().split())


def fun1(a, b, c):
    amt = min(a, b - c)
    a -= amt
    c += amt
    return a, c


# pours 1 to 99
for i in range(1, 34):
    m1, m2 = fun1(m1, c2, m2)
    m2, m3 = fun1(m2, c3, m3)
    m3, m1 = fun1(m3, c1, m1)
# pour 100
m1, m2 = fun1(m1, c2, m2)

result = [m1, m2, m3]
for i in result:
    print(i)