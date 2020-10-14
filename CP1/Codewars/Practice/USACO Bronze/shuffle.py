import sys

""" sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w") """

sys.stdin = open("shuffle.in", "r")
sys.stdout = open("shuffle.out", "w")

N = int(input())
shuffled = list(map(int, input().split()))
cowids = list(map(int, input().split()))
shuffledlist = []

for x in range(3):
    for i in shuffled:
        shuffledlist.append(cowids[i - 1])
    for j in range(N):
        cowids[j] = shuffledlist[j]
    shuffledlist = []

for i in cowids:
    print(i)
