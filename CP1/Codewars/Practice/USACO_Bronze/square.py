import sys

sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")

""" sys.stdin = open("square.in", "r")
sys.stdout = open("square.out", "w") """


class Pasture:
    def __init__(self):
        self.x1, self.y1, self.x2, self.y2 = map(int, input().split())


def max_x():
    return max(squares[0].x1, squares[0].x2, squares[1].x1, squares[1].x2)


""" x1, y1, x2, y2 = map(int, input().split())
x3, y3, x4, y4 = map(int, input().split()) """
""" max of (dif between highest x and lowest x) & (dif between highest y and lowest y) """
squares = []
for i in range(2):
    squares.append(Pasture())
print(squares[0].x1)
""" a = max(x1, x2, x3, x4) - min(x1, x2, x3, x4)
b = max(y1, y2, y3, y4) - min(y1, y2, y3, y4)
print(max(a, b) ** 2)
 """