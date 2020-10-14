import sys

sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")

""" sys.stdin = open("shell.in", "r")
sys.stdout = open("shell.out", "w") """

""" if sum of overlapping areas >= white paper area print "NO" else print "YES" """


class rect:
    def __init__(self):
        self.x1, self.y1, self.x2, self.y2 = map(int, input().split())

    def area(self):
        return (self.x2 - self.x1) * (self.y2 - self.y1)


rects = []
for i in range(3):
    rects.append(rect())


def overlap(a, b):
    return [max(a.x1, b.x1), max(a.y1, b.y1), min(a.x2, b.x2), min(a.y2, b.y2)]


x1, y1, x2, y2 = overlap(rects[0], rects[1])
x3, y3, x4, y4 = overlap(rects[0], rects[2])
x5, y5, x6, y6 = overlap(rects[1], rects[2])

area1 = (x2 - x1) * (y2 - y1)
area2 = (x4 - x3) * (y4 - y3)
if x5 < x6 and y5 < y6:
    area3 = (x6 - x5) * (y6 - y5)
else:
    area3 = 0
""" print(x5, y5, x6, y6)
print(area1, area2, area3) """
""" print(area1 + area2 - area3) """
if area1 + area2 - area3 >= rects[0].area():
    print("NO")
else:
    print("YES")