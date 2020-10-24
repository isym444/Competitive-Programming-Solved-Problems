import sys

""" sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")
 """
""" sys.stdin = open("shell.in", "r")
sys.stdout = open("shell.out", "w") """

n = int(input())
for i in range(n):
    d = int(input())
    g = list(map(int, input().split()))
    dic = {}
    index = 0
    for j in range(1, d + 1):
        dic[j] = g[j - 1]
    if len(set(dic.values())) == 1:
        print("NO")
    else:
        for k in range(1, d):
            if g[k] != g[0]:
                print("YES")
                print(1, k + 1)
                index = k
                break
        for k in range(1, d):
            if k != index:
                if g[k] != g[0]:
                    print(1, k + 1)
                else:
                    print(index + 1, k + 1)
            else:
                pass
