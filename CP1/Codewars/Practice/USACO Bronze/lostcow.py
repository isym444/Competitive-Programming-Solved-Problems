import sys

""" sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")
 """
sys.stdin = open("lostcow.in", "r")
sys.stdout = open("lostcow.out", "w")
x, y = map(int, input().split())
counter = 1
position = x
totaldist = 0
result = 0
matcher = x
loopchecker = True
while loopchecker == True:
    position = x + counter
    totaldist += abs(x - matcher)
    matcher = x
    for i in range(abs(x - position)):
        if matcher == y:
            print(totaldist)
            loopchecker = False
            break
        elif position > x:
            matcher += 1
            totaldist += 1
        else:
            matcher -= 1
            totaldist += 1
    counter *= -2
