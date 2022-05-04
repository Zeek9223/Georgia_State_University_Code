import requests
import os
from dotenv import find_dotenv, load_dotenv



load_dotenv(find_dotenv())
API_KEY = os.getenv('API_KEY')
API_key = "84e0dabf84e4d9643b17972c39e173e2"


kind = 'movie'
weekly = 'week'

BASE_URL = 'https://api.themoviedb.org/3/trending/{kind}/{weekly}}?api_key=<<API_key>>={API_key}&callback=test'

response = requests.get(BASE_URL).json()
print('Results for {kind} by {weekly} is \n')
for each in range(len(response['results'])):
    print(response['results'][each]['original_title'])

   