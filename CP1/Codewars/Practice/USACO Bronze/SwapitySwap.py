import sys

sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")

""" sys.stdin = open("swap.in", "r")
sys.stdout = open("swap.out", "w") """

n, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
cows = [i for i in range(1, n + 1)]
origcows = [i for i in cows]


def rearr(x, y):
    temp = []
    for j in range(x, y + 1):
        temp.append(cows[j - 1])
    counter = 0
    for k in range(x, y + 1):
        counter += 1
        cows[k - 1] = temp[-counter]
    return cows


counter2 = 0
cyclelen = 0
for i in range(k):
    counter2 += 1
    # do rearr 1
    cows = rearr(a[0], a[1])
    # do rearr 2
    cows = rearr(b[0], b[1])
    if cows == origcows:
        cyclelen = counter2
        break

cows = origcows

""" print(counter2) """
if cyclelen == 0:
    for i in range(k):
        # do rearr 1
        cows = rearr(a[0], a[1])
        # do rearr 2
        cows = rearr(b[0], b[1])
else:
    for i in range(k % cyclelen):
        # do rearr 1
        cows = rearr(a[0], a[1])
        # do rearr 2
        cows = rearr(b[0], b[1])

for l in range(n):
    print(cows[l])
