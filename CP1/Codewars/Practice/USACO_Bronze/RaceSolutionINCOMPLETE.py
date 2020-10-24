import sys

sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")

""" sys.stdin = open("shell.in", "r")
sys.stdout = open("shell.out", "w") """


def solve(dist):
    minspeed = int(input())
    lhstravel = 0
    rhstravel = 0
    timeused = 0
    currspeed = 1
    while currspeed > 0:
        lhstravel += currspeed
        timeused += 1
        if lhstravel + rhstravel >= dist:
            return timeused
            # currspeed = -2
        elif currspeed >= minspeed:
            rhstravel += currspeed
            timeused += 1
            currspeed += 1
        elif lhstravel + rhstravel >= dist:
            return timeused
            # currspeed = -2
        else:
            currspeed += 1


k, n = map(int, input().split())
for i in range(0, n):
    print(solve(k))
