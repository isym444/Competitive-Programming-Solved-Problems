import sys

sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")

""" sys.stdin = open("buckets.in", "r")
sys.stdout = open("buckets.out", "w") """
a = []
[a.append(input()) for _ in range(10)]
barn = []
lake = []
rock = []
counti = 0
countj = 0
for i in a:
    counti += 1
    countj = 0
    for j in i:
        countj += 1
        if j == "B":
            barn.append(counti)
            barn.append(countj)
        if j == "L":
            lake.append(counti)
            lake.append(countj)
        if j == "R":
            rock.append(counti)
            rock.append(countj)


""" print(barn)
print(lake) """

answer = abs(lake[1] - barn[1]) + abs(lake[0] - barn[0]) - 1

if barn[0] == rock[0] == lake[0] or barn[1] == rock[1] == lake[1]:
    print(answer + 2)
else:
    print(answer)
