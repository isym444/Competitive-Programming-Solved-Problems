import sys

""" sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w") """

""" sys.stdin = open("shell.in", "r")
sys.stdout = open("shell.out", "w") """

n = int(input())
a = set(map(int, input().split()))
print(len(a))