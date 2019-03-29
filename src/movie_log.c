#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <ncurses.h>
#include "movie_log.h"

/*
 *
 *
 *
 * Author: Logan Thompson
 * Date: 03/29/2019
 *
 *
 * ToDo:
 */

/*
 * Function: newMovieLog
 * Input: MovieEntry pointer, string
 * Output: MovieLog pointer
 *
 * Copies applicable data from MovieEntry object and provided date to new MovieLog
 * and returns a pointer to that MovieLog
 *
 * ToDo:
 */
MovieLog * newMovieLog(MovieEntry *orig, char *date)
{
	MovieLog *x = malloc(sizeof(MovieLog));

	x->title = strdup(orig->primaryTitle);
	x->releaseYear = orig->startYear;
	x->runtime = orig->runtimeMinutes;
	x->genres = strdup(orig->genres);
	x->dvd = 0;
	x->bluray = 0;
	x->digital = 0;
	x->date = date;


	return x;
}

/*
 * Function: newMovieLogFile
 * Input: char pointers and integers representing structure variables
 * Output: MovieLog pointer
 *
 * Creates a MovieLog pointer to object with all variables passed to it
 * Used for log importing
 *
 * ToDo:
 */
MovieLog * newMovieLogFile(char *title, int releaseYear, int runtime, char *genres, int dvd, int bluray, int digital, char *date)
{
	MovieLog *x = malloc(sizeof(MovieLog));

	x->title = strdup(title);
	x->releaseYear = releaseYear;
	x->runtime = runtime;
	x->genres = strdup(genres);
	x->dvd = dvd;
	x->bluray = bluray;
	x->digital = digital;
	x->date = strdup(date);


	return x;
}

/*
 * Function: newMovieLogSearch
 * Input: char pointer
 * Output:MovieLog pointer
 *
 * Creates a Movielog with only a valid title to be used for searching and returns a pointer to it
 *
 * ToDo:
 */
MovieLog * newMovieLogSearch(char *title)
{
	MovieLog *x = malloc(sizeof(MovieLog));

	x->title = strdup(title);
	x->releaseYear = 0;
	x->runtime = 0;
	x->genres = "";
	x->dvd = 0;
	x->bluray = 0;
	x->digital = 0;
	x->date = "";

	return x;
}

/*
 * Function: logTitleLessThan
 * Input:void pointers
 * Output: integer
 *
 * Returns 1 if first MovieLog title is less than second
 *
 * ToDo:
 */
int logTitleLessThan(void *x, void *y)
{
	if(strcmp(toLowerString(((MovieLog*)x)->title), toLowerString(((MovieLog*)y)->title)) < 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
 * Function: logTitleGreaterThan
 * Input:two void pointers
 * Output: integer
 * Returns 1 if first MovieLog title is greater than second
 *
 * ToDo:
 */
int logTitleGreaterThan(void *x, void *y)
{
	if(strcmp(toLowerString(((MovieLog*)x)->title), toLowerString(((MovieLog*)y)->title)) > 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
 * Function: logTitleEqualTo
 * Input: two MovieLog pointers
 * Output: integer
 *
 * Returns 1 if first MovieLog title is equal to the second
 *
 * ToDo:
 */
int logTitleEqualTo(MovieLog *x, MovieLog *y)
{
	if(strcmp(toLowerString(x->title), toLowerString(y->title)) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
 * Function: printMovieLog
 * Input: void pointer and void pointer
 * Output: none
 *
 * prints MovieLog to file pointer specified
 *
 * ToDo:
 */
void printMovieLog(void *x, void *outSel)
{
	fprintf((FILE*)(outSel),"%s\t%d\t%d\t%s\t%d\t%d\t%d\t%s\n",((MovieLog*)x)->title,((MovieLog*)x)->releaseYear,((MovieLog*)x)->runtime,((MovieLog*)x)->genres,((MovieLog*)x)->dvd,((MovieLog*)x)->bluray,((MovieLog*)x)->digital,((MovieLog*)x)->date);
}

/*
 * Function: printMovieLogScreen
 * Input: void pointer
 * Output:none
 *
 * prints movielog to screen using ncurses
 *
 * ToDo:
 */
void printMovieLogScreen(void *x)
{
	printw("%-50s%-12d%-7d%-25s%-6d%-9d%-10d%-10s\n",((MovieLog*)x)->title,((MovieLog*)x)->releaseYear,((MovieLog*)x)->runtime,((MovieLog*)x)->genres,((MovieLog*)x)->dvd,((MovieLog*)x)->bluray,((MovieLog*)x)->digital,((MovieLog*)x)->date);
//	refresh();
}

/*
 * All below functions modify their respective(in function name) variable to modify the
 * media type of a MovieLog
 */
void addDvd(MovieLog *x)
{
	x->dvd = 1;
}

void addBluray(MovieLog *x)
{
	x->bluray = 1;
}

void addDigital(MovieLog *x)
{
	x->digital = 1;
}

void removeDvd(MovieLog *x)
{
	x->dvd = 0;
}

void removeBluray(MovieLog *x)
{
	x->bluray = 0;
}

void removeDigital(MovieLog *x)
{
	x->digital = 0;
}

void changeDate(MovieLog *x, char *date)
{
	x->date = strdup(date);
}

/*
 * Function: begLogMatch
 * Input:two void pointers
 * Output: integer
 *
 * Returns 1 if first string is substring of second string
 *
 * ToDo:
 */
int begLogMatch(void *x, void *y)
{
	int found;
	found = begLogMatchAux(((MovieLog*)x)->title,((MovieLog*)y)->title);
	return found;
}

/*
 * Function: begLogMatchAux
 * Input: search term and full string
 * Output: int
 *
 * Auxillary function to begLogMatch
 *
 * ToDo:
 */
int begLogMatchAux(const char *searchTerm, const char *full)
{
	printw("%s\n",searchTerm);


	char st;
	char f;
	int ret = 1;

	for(int x = 0; searchTerm[x] != '\0'; x++)
	{
		st = searchTerm[x];
		f = full[x];

		st = tolower(st);
		f = tolower(f);

		printw("%c = %c :%d\n",st,f,(st == f));

		if(st != f)
		{
			ret = 0;
			break;
		}
	}
	printw("ret: %d",ret);
	return ret;
}


