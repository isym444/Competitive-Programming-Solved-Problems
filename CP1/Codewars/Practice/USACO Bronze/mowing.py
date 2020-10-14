import sys
import copy

sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")

""" sys.stdin = open("mowing.in", "r")
sys.stdout = open("mowing.out", "w") """

""" make a coordinate system loc=list(0,0) for x,y
N modifies (0,N)
S modifies (0,-S)
E modifies (E,0)
W modifies (-W,0)
keep a database of visited coordinates vc=[]
regrowtime=[]
cuonter=0
i.e. for every new instruction, move 1 square at a time and at each step add coordinate to database
at each step also check if loc in vc: regrowtime.append(size of vc - index of visited square) add to visited coordinates
note that func() allows index of visited square index to be last occuring instance index to be found in case of repeatedly visited squares
print(min(regrowtime)) """

currloc = [0, 0]
vc = [[0, 0]]
instructions = []
regrowtime = []
counter = 0
n = int(input())
for i in range(n):
    instructions.append(input().split())
for i in range(n):
    instructions[i][1] = int(instructions[i][1])
""" print(instructions) """


def func():
    for z in range(len(vc) - 1, -1, -1):
        if vc[z] == currloc:
            return len(vc) - z


for i in range(n):
    # moving north
    if instructions[i][0] == "N":
        for j in range(instructions[i][1]):
            currloc[1] += 1
            if currloc in vc:
                regrowtime.append(func())
                vc.append(copy.copy(currloc))
                """ counter += 1 """
            else:
                vc.append(copy.copy(currloc))
    # moving south
    elif instructions[i][0] == "S":
        for j in range(instructions[i][1]):
            currloc[1] -= 1
            if currloc in vc:
                regrowtime.append(func())
                vc.append(copy.copy(currloc))
                """ counter += 1 """
            else:
                vc.append(copy.copy(currloc))
    # moving east
    elif instructions[i][0] == "E":
        for j in range(instructions[i][1]):
            currloc[0] += 1
            if currloc in vc:
                regrowtime.append(func())
                vc.append(copy.copy(currloc))
                """ counter += 1 """
            else:
                vc.append(copy.copy(currloc))
    # moving west
    elif instructions[i][0] == "W":
        for j in range(instructions[i][1]):
            currloc[0] -= 1
            if currloc in vc:
                regrowtime.append(func())
                vc.append(copy.copy(currloc))
                """ counter += 1 """
            else:
                vc.append(copy.copy(currloc))
""" print(regrowtime) """
if regrowtime == []:
    print(-1)
else:
    print(min(regrowtime))
