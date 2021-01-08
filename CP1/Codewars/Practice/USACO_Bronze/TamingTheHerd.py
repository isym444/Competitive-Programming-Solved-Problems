import sys

""" sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")
 """
sys.stdin = open("taming.in", "r")
sys.stdout = open("taming.out", "w")

""" breakouts = 1
start counting from -1
if find non -1 non 0 number: change previous indexes -1 until reach change to 0
min_breakouts = 1+num_of_0s in a[]
max_breakouts = min_breakouts+number of -1s
special cases: everything is -1:min_breakouts=1, max_breakouts=n

error catching: explictly inconsistent record: a[i-1] != a[i]-1 UNLESS a[i]=0"""

n = int(input())
a = list(map(int, input().split()))
min_breakouts = 0
max_breakouts = 0
breaker = 1
if set(a) == 1:
    min_breakouts = 1
    max_breakouts = n
    print(min_breakouts, max_breakouts)
else:
    for i in range(-1, -n, -1):
        if a[i] != -1:
            if a[i] != 0 and a[i - 1] != -1 and a[i - 1] != a[i] - 1:
                print(-1)
                breaker = 0
                break
            elif a[i] - 1 >= 0:
                a[i - 1] = a[i] - 1
    if breaker == 1:
        min_breakouts = 1 + a[1:n].count(0)
        max_breakouts = min_breakouts + a[1:n].count(-1)
        print(min_breakouts, max_breakouts)
