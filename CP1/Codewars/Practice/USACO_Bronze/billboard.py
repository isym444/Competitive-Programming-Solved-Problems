import sys

""" sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w") """

sys.stdin = open("billboard.in", "r")
sys.stdout = open("billboard.out", "w")

""" if no overlap: print area of first rectangle
if only overlap part of x length or part of y length of first rectangle: print area of first rectangle
if overlap all of x length or all of y length of first rectangle: print area of first rectangle - overlapping area
if overlap all of x length and all of y length of first rectangle: print 0 """

""" to check if all of x length or all of y length of first rectangle is being overlapped:
first challenge is to output botom left corner and top right corner of rectangle formed by overlap
 """


class Rectangle:
    """
    docstring
    """

    def __init__(self):
        self.x1, self.y1, self.x2, self.y2 = map(int, input().split())

    def area(self):
        return (self.x2 - self.x1) * (self.y2 - self.y1)


def intersect(a, b):
    return [max(a.x1, b.x1), max(a.y1, b.y1), min(a.x2, b.x2), min(a.y2, b.y2)]


# a and b are same rectangle
def test_same_triangle(a, b):
    if a.x1 == b.x1 and a.y1 == b.y1 and a.x2 == b.x2 and a.y2 == b.y2:
        return 4


def test_intersect(a, b):
    x_range_a = []
    x_range_b = []
    y_range_a = []
    y_range_b = []
    for i in range(a.x1, a.x2):
        x_range_a.append(i)
    for i in range(b.x1, b.x2):
        x_range_b.append(i)
    for i in range(a.y1, a.y2):
        y_range_a.append(i)
    for i in range(b.y1, b.y2):
        y_range_b.append(i)
    if bool(set(x_range_a) & set(x_range_b)) and bool(set(y_range_a) & set(y_range_b)):
        return 1
    else:
        return 0


def a_in_b(a, b):
    if b.x1 <= a.x1 and b.y1 <= a.y1 and b.x2 >= a.x2 and b.y2 >= a.y2:
        return 7


# b overlaps a such that a becomes a smaller rectangle
def test_full_intersect(a, b):
    if (b.x1 <= a.x1 and b.x2 >= a.x2 and b.y1 >= a.y1 and b.y2 <= a.y2) or (
        b.y1 <= a.y1 and b.y2 >= a.y2 and b.x1 >= a.x1 and b.x2 <= a.x2
    ):
        return 0
    elif (b.x1 <= a.x1 and b.x2 >= a.x2) or (b.y1 <= a.y1 and b.y2 >= a.y2):
        return 3


rects = []
for i in range(2):
    rects.append(Rectangle())

ix1, iy1, ix2, iy2 = intersect(rects[0], rects[1])
intarea = (ix2 - ix1) * (iy2 - iy1)

h = test_same_triangle(rects[0], rects[1])
d = a_in_b(rects[0], rects[1])
f = test_intersect(rects[0], rects[1])
g = test_full_intersect(rects[0], rects[1])


""" print(rects[0].area())
print(ix1, iy1, ix2, iy2)
print(intarea)
print(rects[0].area() - intarea) """

if h == 4:
    print(0)
elif d == 7:
    print(0)
# elif f == 0:
# print(rects[0].area())
elif g == 3:
    print(rects[0].area() - intarea)
else:
    print(rects[0].area())
