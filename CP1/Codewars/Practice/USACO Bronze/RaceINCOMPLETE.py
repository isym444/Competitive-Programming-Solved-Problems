import sys
import math

sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")

""" sys.stdin = open("race.in", "r")
sys.stdout = open("race.out", "w") """

k, n = map(int, input().split())
x = []
for i in range(0, n, 1):
    x.append(int(input()))
""" for i in range(n):
    speed = 0
    time = 0
    dist = 0
    for j in range(k):
        time += 1
        remaindist = k - dist
        if speed >= remaindist and speed > x[i]:
            speed -= 1
        elif speed >= remaindist and speed <= x[i]:
            speed += 0
        elif speed + 1 == remaindist and speed + 1 > x[i]:
            speed += 0
        elif speed == x[i] + 1:
            speed += 0
        elif speed + 1 == remaindist and speed + 1 <= x[i]:
            speed += 1
        elif speed + 1 < remaindist:
            speed += 1
        dist += speed
        if dist >= k:
            print(time)
            break
 """
for i in range(n):
    N = math.sqrt(k + (x[i] ** 2 - x[i]) / 2)
    N = int(N)
    totalarea = N ** 2 - x[i] ** 2 / 2 + x[i] / 2
    totalarea = int(totalarea)
    remainderarea = k - totalarea
    pt = remainderarea / x[i]
    pt = int(pt)
    z = k - N * (N + 1) / 2
    z = int(z)
    p = 2 * z / (x[i] + N)
    p = int(p)
    print(N + p + pt)
    """ if z == 0:
        print(N)
    elif z < N:
        print(N + 1)
    elif z > N:
        remainder=z-
        print(N + N - x[i] + x[i]*remainder)
 """
