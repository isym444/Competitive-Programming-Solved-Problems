import sys

""" sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")
 """
""" sys.stdin = open("shell.in", "r")
sys.stdout = open("shell.out", "w") """

""" go from L to R in array
find index of first 1 and index of last 1
go from L to R from index of first 1 to index of last 1:
    count 0's -> output the count """

n = int(input())

for i in range(n):
    counter = 0
    length = int(input())
    array = list(map(int, input().split()))
    for j in range(length):
        if array[j] == 1:
            firstindex = j
            break
    for j in range(length - 1, -1, -1):
        if array[j] == 1:
            lastindex = j
            break
    for j in range(firstindex, lastindex + 1, 1):
        if array[j] == 0:
            counter += 1
    print(counter)
