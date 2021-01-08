import sys

""" sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")
 """
""" sys.stdin = open("shell.in", "r")
sys.stdout = open("shell.out", "w") """

n, t = map(int, input().split())
a = list(input())

""" def swap(x):
    pass """


for j in range(t):
    passer = 0
    for i in range(n - 1):
        if a[i] == "B" and a[i + 1] == "G" and passer == 0:
            a[i] = "G"
            a[i + 1] = "B"
            passer = 1
        elif passer == 1:
            passer = 0
print("".join(a))


""" GBBGBB """