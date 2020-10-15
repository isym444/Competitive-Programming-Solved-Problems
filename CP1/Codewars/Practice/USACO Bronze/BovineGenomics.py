import sys

""" sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w") """

sys.stdin = open("cownomics.in", "r")
sys.stdout = open("cownomics.out", "w")

""" location predicts spotiness if all letters at particular column for n cows do not appear in n+1->2n cows """

n, m = map(int, input().split())
spotted = [input() for _ in range(n)]
plain = [input() for _ in range(n)]
""" print(spotted) """
ans = 0
for i in range(m):
    a = []
    b = []
    for j in range(n):
        a.append(spotted[j][i])
        b.append(plain[j][i])
        """ print(len(set(a) & set(b))) """
    if len(set(a) & set(b)) == 0:
        ans += 1
print(ans)
