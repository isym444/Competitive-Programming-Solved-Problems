import sys

""" 
sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")
 """
""" sys.stdin = open("shell.in", "r")
sys.stdout = open("shell.out", "w") """

""" if input array t has length 3:
a[t[1]]=t[2]
elif input array t has length 2:
    print a[t[1]] """

n = int(input())
for _ in range(n):
    t = []
    t = list((map(int, input().split())))
    if len(t) == 3:
        a[t[1]] = t[2]
    elif len(t) == 2:
        print(a[t[1]])