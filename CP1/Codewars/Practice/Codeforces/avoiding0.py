import sys
from itertools import permutations

""" sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w") """

n = int(input())
for i in range(n):
    num = int(input())
    arr = list(map(int, input().split()))
    a = permutations(arr, num)
    breaker = 0
    forbreak = 0
    bbreak = 0
    if sum(arr) == 0:
        print("NO")
    elif sum(arr) > 0:
        print("YES")
        arr.sort(reverse=True)
        """ print(arr) """
        print(" ".join(map(str, arr)))
    elif sum(arr) < 0:
        print("YES")
        arr.sort()
        """ print(arr) """
        print(" ".join(map(str, arr)))
    """ else:
        while breaker != 1:
            try:
                b = next(a)
                summ = 0
                forbreak = 0
                for k in range(num):
                    summ += b[k]
                    if summ == 0:
                        forbreak = 1
                    elif k == num - 1 and forbreak == 0:
                        print("YES")
                        print(" ".join(map(str, b)))
                        breaker = 1
            except StopIteration:
                break
        if breaker == 0:
            print("NO")
    breaker = 0
    arr = [] """
