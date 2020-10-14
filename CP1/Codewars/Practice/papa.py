import sys

""" sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")
 """


def fact(x):
    """
    docstring
    """
    result = 1
    for i in range(1, x + 1):
        result = result * i
    return result


a = list(map(int, input().split()))
print(fact(min(a)))
