import sys

sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")

""" sys.stdin = open("shell.in", "r")
sys.stdout = open("shell.out", "w") """

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
print(github_usaco_counter)

""" for i in usaco:
    if "FAIL" in i:
        pass
    elif "INCOMPLETE" in i:
        pass
    else:
        usaco_counter += 1 """