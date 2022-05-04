
# Milestone #2 Updated movie web app
Milestone 2 project

Adding ot our Web app "Movie run"

Will be adding data base to connect login/registration and will be coonect data base to append our comments and rating on specific movie


## Ruberic

[![Screen-Shot-2022-05-04-at-9-06-28-AM.png](https://i.postimg.cc/tTSSb9w0/Screen-Shot-2022-05-04-at-9-06-28-AM.png)](https://postimg.cc/CB8HHpwJ)
[![Screen-Shot-2022-05-04-at-9-05-21-AM.png](https://i.postimg.cc/B6kzDqgT/Screen-Shot-2022-05-04-at-9-05-21-AM.png)](https://postimg.cc/MM0tJJgH)
[![Screen-Shot-2022-05-04-at-9-05-32-AM.png](https://i.postimg.cc/fRCgC7CT/Screen-Shot-2022-05-04-at-9-05-32-AM.png)](https://postimg.cc/yDJPYZ2w)


## Tech Stack

-Pyhton

-flask

-heroku

-html

-css

-pylint

-API(TMBD, Wikiapp)

-env(database postgres secretkey, wikipedia key, TMBD key)

-postgres

-SQLAlchemy

-app route


## Tech Issue

One of the things i had trouble with is connect to postgres database. The easy way i fixed was realizing the admin and password had to be correct for me to get acesss to it. 

Another issue i had was append my commments i created in the html file and saving it to database for view later. I fixed by Creating form that saved the comment to the database. Now the hard part was making sure the comment was appended to that specific movie and making sure flasked had show what was saved in the database.


## Difference between this milestone and milestone 1

Same file was used, just added app route to  direct correctly between the correct files. The using the login and registration was easy to add. The rrick part that was very different with me was creating form on html file that lets you input comments and ratings into the data base so it can render back to the movie it was saved too.