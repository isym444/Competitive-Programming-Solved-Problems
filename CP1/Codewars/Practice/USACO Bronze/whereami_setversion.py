import sys

""" sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w") """

sys.stdin = open("whereami.in", "r")
sys.stdout = open("whereami.out", "w")

n = int(input())
s = input()
myset = set()


def checker(x):
    for i in range(len(s) - x + 1):
        a = s[i : i + x]
        if a in myset:
            return True
        else:
            myset.add(a)
    return False


ans = 1
while checker(ans):
    ans += 1
print(ans)
