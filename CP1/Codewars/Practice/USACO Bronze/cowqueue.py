import sys

""" sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")
 """
sys.stdin = open("cowqueue.in", "r")
sys.stdout = open("cowqueue.out", "w")

""" make list of lists, order by first element
current time = 0
for every element
if a[0] > current time:
    current time == a[0]
    current time += a[1]
else current time += a[1]
print(current time)
"""

ct = 0
a = []
b = []
n = int(input())
for i in range(n):
    a.append(list(map(int, input().split())))
a.sort(key=lambda x: x[0])
for i in a:
    if i[0] > ct:
        ct = i[0]
        ct += i[1]
    else:
        ct += i[1]
print(ct)