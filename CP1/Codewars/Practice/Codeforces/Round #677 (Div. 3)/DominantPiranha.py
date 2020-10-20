import sys

""" sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")
 """
""" sys.stdin = open("shell.in", "r")
sys.stdout = open("shell.out", "w") """

""" piranha can eat an adjacent piranha of smaller size
if it eats a piranha, its own size grows by 1 """

""" if all piranhas start same size, none can be dominant: print -1
if there is more than 1 number i.e. size of set>1: print max(list)"""

n = int(input())
for i in range(n):
    a = int(input())
    b = list(map(int, input().split()))
    c = set(b)
    if len(set(b)) == 1:
        print(-1)
    else:
        d = max(b)
        for j in range(a):
            if b[j] == d and j == 0 and b[j] > b[j + 1]:
                print(j + 1)
                break
            elif b[j] == d and j == a - 1 and b[j] > b[j - 1]:
                print(j + 1)
                break
            elif b[j] == d and (b[j] > b[j + 1] or b[j] > b[j - 1]) and j != 0 and j != a - 1:
                print(j + 1)
                break
