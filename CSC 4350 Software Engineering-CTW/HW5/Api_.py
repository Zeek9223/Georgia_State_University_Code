import requests
import os
from dotenv import find_dotenv, load_dotenv


load_dotenv(find_dotenv())
API_key = "84e0dabf84e4d9643b17972c39e173e2"

BASE_URL = "https://api.themoviedb.org/3/trending/all/day?api_key=<<API_key>>={API_key}&callback=test"
API_KEY = os.getenv("TMDB_KEY")

query_params = {
    "q": "election",
    "api-key": API_KEY
}

response = requests.get(
    BASE_URL,
    query_params=query_params
)

response_json = response.json()

try:
    articles = response_json["response"]["page"][10]["object"]["total_results"]
    for movie in movies: 
       print(movie)
except KeyError:
    print("Couldn't fetch movies")
