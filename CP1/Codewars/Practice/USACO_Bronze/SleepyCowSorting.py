import sys

""" sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")
 """
sys.stdin = open("sleepy.in", "r")
sys.stdout = open("sleepy.out", "w")

n = int(input())
a = list(map(int, input().split()))
counter = 1

for i in range(-1, -n, -1):
    if a[i - 1] < a[i]:
        counter += 1
    else:
        break
print(n - counter)


""" 4 total
last 1 sorted
3 rearrangements
4231
2314
3124
1234


4 total
last 3 sorted
1 rearrangement
2134
1234

1243
2413
4123
1234

1432
4312
3124
1234
4# out of position
3 rearr

4123
1234 """