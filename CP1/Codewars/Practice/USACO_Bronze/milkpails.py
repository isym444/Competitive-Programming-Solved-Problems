import sys

""" 
sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")
 """
sys.stdin = open("pails.in", "r")
sys.stdout = open("pails.out", "w")

""" ans=0
while ans<77:
    for i in range (77/X+1):
        for j in range (77/y+1):
            a=x*i+y*j
            b=x*j+y*i
            c=max(a,b)
            if c>ans:
                ans=a"""
x, y, m = map(int, input().split())
ans = 0

for i in range(max(int(m / x + 1), int(m / y + 1))):
    for j in range(max(int(m / x + 1), int(m / y + 1))):
        a = 0
        b = 0
        if x * i + y * j <= m:
            a = x * i + y * j
        if x * j + y * i <= m:
            b = x * j + y * i
        c = max(a, b)
        if c > ans and c <= m:
            ans = a
print(ans)