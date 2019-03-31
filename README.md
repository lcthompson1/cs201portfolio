# IMDB CRUD Application

This application allows for the IMDB database to be downloaded, parsed, and loaded into a datastructure. This allows for movies to be searched and added to a specified user log. The program allows for both log creation and modification, with the resulting logs being imported and exported to text files to allow for future use. The user logs allow for movie information as well as the type of media owned for that particular movie and the date it was purchased.

## Getting Started

To set up this program initially, all one needs to do is run "./setup" in a terminal located within the /src folder. After this initial set up, the program can be ran by running "./program" in that same location.

If permission errors are thrown, the script can be made executable by running "chmod 755 setup"

## Prerequisites

This project will require gcc(sudo apt-get install gcc),ncurses(sudo apt-get install libncurses5-dev), and make(sudo apt-get install make) libraries to be installed for compilation
Resolution used is 1680x1050, smaller window sizes may cause issues

## Usage

Upon launch, this program will notify that the database is being loaded and will notify when it is completed. It will then display a main menu allowing you to choose to either exit the program, create a new log file, or edit an existing file.The create a new log menu will allow you to choose a file name, search for a movie to add, and allow you to edit the media type and date. Upon completion, you can either create another new log, or return to te new main menu. The existing log menu will allow you to add a new entry, modify an existing entry, display the user log, or return to te main menu.

When searching for titles, the search entry must be what the title begins with, not what it contains.


## Notes

The data structure used for both the lookup database and user log is a red black tree. This allows for very fast insertions, deletions, and searches. An AVL or B tree could have been used, but since the data structuer is used for both the lookup tree and user log, modifications were as important as searches. Due to this, a red black tree allows for better average performance. When the lookup tree is created, the titles are converted to lowercase for comparison, but inserted as they originally were. This is to allow for more accurate and faster searching at the cost of initial creation (~3 seconds vs. ~7 seconds). A linked list is used to return search results to allow for easy user selection and retrieval when adding to the user log.

## Links
* [GitHub link]((https://github.com/lcthompson1)
* [tsv file](https://datasets.imdbws.com/title.basics.tsv.gz)
* [Video Demonstration](https://youtu.be/Y9M0fxnXO7g)

## Authors

* **Logan Thompson** - [lcthompson1](https://github.com/lcthompson1)

## Acknowledgments

* Dr. Anderson for the assignment of this project
