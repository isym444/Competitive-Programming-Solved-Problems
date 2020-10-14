import sys
import itertools

sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")

""" sys.stdin = open("shell.in", "r")
sys.stdout = open("shell.out", "w") """

""" number of people = 2n
tandems = n-1
singles = 2
instability = 0
sort weights
calculate dif between wi & wi+1 -> store values as a & b and dif as max dif
iterate through list
if next dif is bigger, instability += b-a set new values for a & b & max dif
"""

n = int(input())
people = 2 * n
sinlges = 2
instability = 0
weights = list(map(int, input().split()))
weights.sort()
for i in range(0, people):
    for j in range(0, people):
        if i == j:
            pass
        else:
            abs(i - j)
print(weights)
print(instability)