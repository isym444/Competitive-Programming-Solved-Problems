import sys

sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")

""" sys.stdin = open("shell.in", "r")
sys.stdout = open("shell.out", "w") """


import requests
import json


user_agent = "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_2) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.130 Safari/537.36"
url = "https://leetcode.com/api/problems/all/"

headers = {"User-Agent": user_agent, "Connection": "keep-alive"}
resp = session.get(url, headers=headers, timeout=10)

question_list = json.loads(resp.content.decode("utf-8"))

for question in question_list["stat_status_pairs"]:
    if question["status"] == "ac":
        print("Solved problems: {}".format(question["stat"]["frontend_question_id"]))
