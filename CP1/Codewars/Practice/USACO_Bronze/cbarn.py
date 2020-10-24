import sys

""" sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")
 """
sys.stdin = open("cbarn.in", "r")
sys.stdout = open("cbarn.out", "w")

n = int(input())
roomcap = []
for i in range(n):
    roomcap.append(int(input()))


def rotatearr(x, arsize):
    """
    docstring
    """
    temp = x[0]
    for i in range(arsize - 1):
        x[i] = x[i + 1]
    x[arsize - 1] = temp


distance = 0
mindist = 10000000000


for j in range(n):
    for i in range(n):
        distance += roomcap[i] * (i)
    if distance < mindist:
        mindist = distance
    distance = 0
    rotatearr(roomcap, n)
print(mindist)
