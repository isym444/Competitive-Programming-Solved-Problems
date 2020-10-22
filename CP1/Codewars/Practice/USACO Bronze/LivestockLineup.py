import sys
import itertools

""" sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")
 """
sys.stdin = open("lineup.in", "r")
sys.stdout = open("lineup.out", "w")

# Bessie, Buttercup, Belinda, Beatrice, Bella, Blue, Betsy, and Sue

n = int(input())
constraints = []
finalconstraints = []
for i in range(n):
    constraints.append(input().split())
""" print(constraints) """
for i in constraints:
    for j in i:
        if j != "must" and j != "be" and j != "milked" and j != "beside":
            finalconstraints.append(j)
""" print(finalconstraints) """


def checker(x):
    for j in range(0, 2 * n, 2):
        if abs(x.index(finalconstraints[j]) - x.index(finalconstraints[j + 1])) > 1:
            return False
    return True


cows = ["Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"]
cows.sort()
""" print(cows) """
p = itertools.permutations(cows)
for i in p:
    if checker(i) == False:
        pass
    else:
        for k in i:
            print(k)
        break
