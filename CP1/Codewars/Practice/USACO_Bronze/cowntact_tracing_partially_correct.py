import sys

""" sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")
 """
sys.stdin = open("tracing.in", "r")
sys.stdout = open("tracing.out", "w")

""" output x,y,z number of possible patient 0's, smallest k, largest k """

n, T = map(int, input().split())

actual_infected = list(map(int, input()))
""" print(actual_infected) """

a = []
for i in range(T):
    a.append(list(map(int, input().split())))

a.sort()
""" print(a) """

final_x = 0
final_min_k = T
final_max_k = 0
all_xs = []
all_ks = []


for k in range(1, T + 1):
    for pt0 in range(1, n + 1):
        sim_infected = [0 for _ in range(n)]
        counter_array = [0 for _ in range(n)]
        spec_counter = 0
        for i in range(T):
            if (a[i][1] == pt0 or a[i][2] == pt0) and counter_array[pt0 - 1] < 1:
                sim_infected[a[i][1] - 1] = 1
                sim_infected[a[i][2] - 1] = 1
                counter_array[pt0 - 1] += 1
            if 1 in sim_infected:
                spec_counter += 1
            if (
                (sim_infected[a[i][1] - 1] == 1 and counter_array[a[i][1] - 1] < k)
                or (sim_infected[a[i][2] - 1] == 1 and counter_array[a[i][2] - 1] < k)
            ) and spec_counter > 1:
                sim_infected[a[i][1] - 1] = 1
                sim_infected[a[i][2] - 1] = 1
                counter_array[a[i][1] - 1] += 1
                counter_array[a[i][2] - 1] += 1
        if sim_infected == actual_infected:
            all_xs.append(pt0)
            all_ks.append(k)
q = len(list(set(all_xs)))
w = min(all_ks)
final_kmax = 0
if max(all_ks) == T:
    final_kmax = "Infinity"
else:
    final_kmax = max(all_ks)
e = final_kmax
print(" ".join(map(str, [q, w, e])))
""" print(all_ks) """