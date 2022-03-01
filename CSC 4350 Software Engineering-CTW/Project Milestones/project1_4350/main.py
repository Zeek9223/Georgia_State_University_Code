import os
import random
import requests
import flask

from dotenv import find_dotenv, load_dotenv
load_dotenv(find_dotenv())

app = flask.Flask(__name__)
API_KEY = os.getenv('TMBD_KEY')

@app.route('/')
def main():
    movies = ['Wild Indian', 'Swim', 'Spider-Man', 'Seperation']  
    ran_movie = random.choice(movies)
    load_dotenv(find_dotenv()) 
    url= f'https://api.themoviedb.org/3/search/movie?api_key={API_KEY}&language=en-US&query={ran_movie}&page=1&include_adult=false'
    response = requests.get(url).json()
    g_url = 'https://api.themoviedb.org/3/genre/movie/list?api_key={API_KEY}&language=en-US&query={ran_movie}&page=1&include_adult=false'
    genre_response = requests.get(g_url).json()
    ran_movie_id = response['results'][0]['id']
    t_url = f'https://api.themoviedb.org/3/movie/{ran_movie_id}?api_key={API_KEY}&language=en-US'
    res_t = requests.get(t_url).json()
    tg = res_t['tagline']
    wikipedia_result = wikipedia(ran_movie)
    gen_list = []
    genres = (response['results'][0]['genre_ids'])
    for each in genres:
        for gen in genre_response['genres']:
            if each == gen['id']:
                gen_list.append(gen['name'])
                r_gen = ', '.join(gen_list)
                pathimg = response['results'][0]['poster_path']
                img_ = f'https://image.tmdb.org/t/p/w500{pathimg}'
    return flask.render_template("main.html", mov=ran_movie, genres=r_gen,tagline=tg , image_url=img_, wiki_res=wikipedia_result)

def wikipedia(movie_name):
    wiki_url = "https://en.wikipedia.org/w/api.php"
    wiki_params = {
    "action": "query",
    "titles":movie_name,
    "format":"json", }
    output = requests.get(wiki_url, wiki_params)
    page_id= list(output.json()['query']['pages'])[0]
    if page_id != -1:
        return f"http://en.wikipedia.org/?curid={page_id}"
    return flask.render_template
if __name__ == '__main__':     
    app.run(use_reloader = True, debug = True)
