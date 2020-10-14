import sys

""" sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w") """

sys.stdin = open("notlast.in", "r")
sys.stdout = open("notlast.out", "w")

""" On a single line of output, please print the name of the cow that produces the second-smallest amount of milk. 
More precisely, if M is the minimum total amount of milk produced by any cow, please output the name of the cow 
whose total production is minimal among all cows that produce more than M units of milk. If several cows tie 
for this designation, or if no cow has this designation (i.e., if all cows have production equal to M), please 
output the word "Tie". Don't forget to add a newline character at the end of your line of output. Note that M=0 
if one of the seven cows is completely absent from the milking log, since this cow would have produced no milk. """

""" 
find M = minimum milk production value
find second minimum milk production value

if one of cows absent, M=0

M = cows with minimum milk production array 
if size(M)>1: print("Tie")"""

""" 7 cows: Bessie, Elsie, Daisy, Gertie, Annabelle, Maggie, and Henrietta """

n = int(input())
cows = {"Bessie": 0, "Elsie": 0, "Daisy": 0, "Gertie": 0, "Annabelle": 0, "Maggie": 0, "Henrietta": 0}
keys = list(cows.keys())
""" print(keys) """
for i in range(n):
    a = input().split()
    a[1] = int(a[1])
    cows[a[0]] += a[1]
""" print(cows) """
values = list(cows.values())
""" print(values) """
""" if 0 in values:
    M = 0
else: """
M = min(values)

penmin = M

b = sorted(values)
for i in b:
    if i != M:
        penmin = i
        break

if values.count(0) == 7 or values.count(penmin) > 1:
    print("Tie")
else:
    d = values.index(penmin)
    print(keys[d])
