
from googleapiclient.discovery import build

api_key = "AIzaSyAPBT6CZzDdYonECB_T_ERE7h6OB4nFC7Y"

import googleapiclient.discovery


service = googleapiclient.discovery.build("calendar", "v3", developerKey=api_key)


youtube = build("youtube", "v3", developerKey=api_key)

request = youtube.channels().list(part="statistics", forUsername="schafer5")

response = request.execute()

print(response)
