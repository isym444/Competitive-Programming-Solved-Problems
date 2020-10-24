import sys
import pandas as pd
from io import StringIO


sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")

""" sys.stdin = open("shell.in", "r")
sys.stdout = open("shell.out", "w") """

from bs4 import BeautifulSoup
import requests

""" source = requests.get("https://codeforces.com/problemset/standings?friendsEnabled=on")

soup = BeautifulSoup(source.text, features="lxml")

# print(soup.prettify())
# page = soup.find("body")
table = soup.table

href = "/profile/legendary"
print(table)
 """

""" dfs = pd.read_html("https://codeforces.com/problemset/standings?friendsEnabled=on", header=0)
print(dfs) """


""" dfs = pd.read_html("https://www.hackerrank.com/submissions/all", header=0)
print(dfs) """


# source = requests.get("https://www.hackerrank.com/submissions/all")

url = "https://leetcode.com/isym444/"
""" headers = {
    "User-Agent": "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_6) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/86.0.4240.80 Safari/537.36",
    "Referer": "https://www.hackerrank.com/",
} """
source = requests.get(url)
# print(source.content.decode())

soup = BeautifulSoup(source.text, features="lxml")
print(soup.find("div", {"id": "profile-root"}))
solved = soup.find("div", attrs={"class", "total-solved-count__2El1"})
print(solved)

# print(soup)


# print(soup)
# print(soup.prettify())
# page = soup.find("body")
# table = soup.table

# href = "/profile/legendary"
# print(table)

""" data = StringIO(source.text)

df = pd.read_html(data)
print(df)
 """

""" dfs = pd.read_html("https://www.hackerrank.com/submissions/all", header=0)
print(dfs) """