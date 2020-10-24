import sys


""" sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")
 """
sys.stdin = open("tttt.in", "r")
sys.stdout = open("tttt.out", "w")


""" get inputs as 1 array of 3 strings
cycle through array in all winning combinations:
    wintestarr=[0,0,0]
    for i in a
    for i
calculate individual wins (if all 3 consecutive letters are the same):
calculate group wins (if only 2 letters found in 3 consecutive letters i.e. not all same AND not all different): """

a = [0, 0, 0]


def sumascii(x):
    total = 0
    for i in x:
        total += ord(i)
    return total


for i in range(3):
    a[i] = input()
testarr = [0, 0, 0]
doublesset = set()
indset = set()
teamset = set()
for i in a:  # horizontal wins
    if len(set(i)) == 1:
        indset.add(i)
    elif len(set(i)) == 2:
        teamset.add(sumascii("".join(set(i))))
        """ teamset.add("".join(set(i))) """
# vertical wins
for j in range(3):
    for i in range(3):
        testarr[i] = a[i][j]
    if len(set(testarr)) == 1:
        indset.add("".join(testarr))
    elif len(set(testarr)) == 2:
        teamset.add(sumascii("".join(set(testarr))))
        """ teamset.add(("".join(set(testarr)))) """
    testarr = [0, 0, 0]
for i in range(3):  # R diagonal win
    testarr[i] = a[i][i]
if len(set(testarr)) == 1:
    indset.add("".join(testarr))
elif len(set(testarr)) == 2:
    teamset.add(sumascii("".join(set(testarr))))
    """ teamset.add(("".join(set(testarr)))) """
testarr = [0, 0, 0]
for i in range(3):  # L diagonal win
    testarr[i] = a[i][2 - i]
if len(set(testarr)) == 1:
    indset.add("".join(testarr))
elif len(set(testarr)) == 2:
    teamset.add(sumascii("".join(set(testarr))))
    """ teamset.add(("".join(set(testarr)))) """
testarr = [0, 0, 0]

""" print(indset)
print(teamset) """
print(len(indset))
print(len(teamset))