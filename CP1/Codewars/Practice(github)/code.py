from itertools import groupby
import sys


""" sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")
sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r") """

""" input the matrix
make a dictionary with keys 1->5 and each value as a list of input
find where 1 is letter[num]
number of moves to get it to c[2] """

a = {}
row = 0
column = 0
for i in range(1, 6):
    a[i] = list(map(int, input().split()))
for i in range(1, 6):
    if 1 in a[i]:
        row = i
        b = a[i]
counter = 0
for i in b:
    counter += 1
    if i == 1:
        column = counter
result = abs(3 - row) + abs(3 - column)
print(result)