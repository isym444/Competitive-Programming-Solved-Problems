import sys
import re
from bs4 import BeautifulSoup
import requests
import config

import werkzeug

werkzeug.cached_property = werkzeug.utils.cached_property
from robobrowser import RoboBrowser

sys.stdin = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/input.txt", "r")
sys.stdout = open("/Users/isym444/Desktop/PythonCP/CP1/Codewars/Practice/output.txt", "w")

""" sys.stdin = open("shell.in", "r")
sys.stdout = open("shell.out", "w") """

br = RoboBrowser()
br.open("https://leetcode.com/accounts/login/")
form = br.get_form()

form["id_login"] = config.DATACOUP_USERNAME  # "isym444"
form["id_password"] = config.DATACOUP_PASSWORD  # "/5LafnJ,xN=Fwp$"
br.submit_form(form)
br.open("https://leetcode.com/isym444/")

src = str(br.parsed())
start = '<div class="total-solved-count__2El1">'
end = "</div>"

result = re.search("%s(.*)%s" % (start, end), src).group(1)
print(result)