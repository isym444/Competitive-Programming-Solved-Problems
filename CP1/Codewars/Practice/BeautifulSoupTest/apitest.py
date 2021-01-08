from pandas.core.computation import pytables

import threading

import sys
import os

""" sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")
 """
""" sys.stdin = open("shell.in", "r")
sys.stdout = open("shell.out", "w") """

import requests


codeforces = requests.get("https://codeforces.com/api/user.status?handle=isym444")
cf_test = codeforces.json()
counter = 0
for i in cf_test["result"]:
    if i["verdict"] == "OK":
        counter += 1
# print("Codeforces accepted problems:", counter)
""" print(test)
print(test["result"]) """

codewars = requests.get("https://www.codewars.com/api/v1/users/isym444")
cw_test = codewars.json()
# print("Codewars completed problems:", cw_test["codeChallenges"]["totalCompleted"])

path = "/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/USACO_Bronze"
usaco = os.listdir(path)
""" usaco_counter = 0
for i in usaco:
    usaco_counter += 1
print(usaco_counter) """

usaco_counter = 0
for i in usaco:
    if "FAIL" in i:
        pass
    elif "INCOMPLETE" in i:
        pass
    else:
        usaco_counter += 1
# print("USACO solved problems:", usaco_counter)


from github import Github

# First create a Github instance:

# using username and password
g = Github("isym444", "Mindstorms1996")

# or using an access token
# g = Github("access_token")

# Github Enterprise with custom hostname
# g = Github(base_url="https://{hostname}/api/v3", login_or_token="access_token")

# Then play with your Github objects:
# for repo in g.get_user().get_repos():
# print(repo.name)

# repo = g.get_dir_contents("Competitive-Programming-Solved-Problems/CP1/Codewars/Practice/USACO Bronze/", ref=NotSet)

repo = g.get_repo("isym444/Competitive-Programming-Solved-Problems")
contents = repo.get_contents("/CP1/Codewars/Practice/USACO Bronze/")
github_usaco_counter = 0
for content_file in contents:
    github_usaco_counter += 1
    if "FAIL" in content_file.path:
        github_usaco_counter -= 1
    elif "INCOMPLETE" in content_file.path:
        github_usaco_counter -= 1
    # print(content_file)
# print(github_usaco_counter)

""" for i in usaco:
    if "FAIL" in i:
        pass
    elif "INCOMPLETE" in i:
        pass
    else:
        usaco_counter += 1 """

HackerRankCounter = 18

LeetcodeCounter = 13

# add hackerrank and leetcode local folders to update counters when solve new problems

# all print statements
""" print("USACO solved problems:", usaco_counter)
print("Codeforces accepted problems:", counter)
print("Codewars completed problems:", cw_test["codeChallenges"]["totalCompleted"])
print("HackerRank solved problems:", HackerRankCounter)
print("LeetCode solved problems:", LeetcodeCounter)
total = usaco_counter + cw_test["codeChallenges"]["totalCompleted"] + counter + HackerRankCounter + LeetcodeCounter
print("Total problems solved:", total)
 """
total = (
    github_usaco_counter + cw_test["codeChallenges"]["totalCompleted"] + counter + HackerRankCounter + LeetcodeCounter
)

# from prettytable import PrettyTable

""" t = PrettyTable(['Name', 'Age'])
t.add_row(['Alice', 24])
t.add_row(['Bob', 19])
print(t) """


def testfunc():
    # threading.Timer(5.0, testfunc).start()
    a = "USACO: %s <br/>Codeforces: %s <br/>Codewars: %s <br/>HackerRank: %s <br/>LeetCode: %s <br/>Total: %s" % (
        github_usaco_counter,
        counter,
        cw_test["codeChallenges"]["totalCompleted"],
        HackerRankCounter,
        LeetcodeCounter,
        total,
    )
    return a


from flask import Flask

# flask
apitest = Flask(__name__)


@apitest.route("/")
def index():
    return testfunc()


if __name__ == "__main__":
    apitest.run(debug=True)