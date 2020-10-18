import sys

""" sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")
 """
sys.stdin = open("cowtip.in", "r")
sys.stdout = open("cowtip.out", "w")

n = int(input())
inptrect = []
for i in range(n):
    inptrect.append(list(map(int, input())))
""" print(inptrect) """
counter = 0


def flip(y, x):
    """
    docstring
    """
    for k in range(y + 1):
        for t in range(x + 1):
            if inptrect[k][t] == 1:
                inptrect[k][t] = 0
            elif inptrect[k][t] == 0:
                inptrect[k][t] = 1
    return inptrect


for i in range(n - 1, -1, -1):
    for j in range(n - 1, -1, -1):
        if inptrect[i][j] == 1:
            inptrect = flip(i, j)
            counter += 1
        else:
            pass

print(counter)