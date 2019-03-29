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
 * Function:
 * Input:
 * Output:
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
 * Function:
 * Input:
 * Output:
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
 * Function:
 * Input:
 * Output:
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
 * Function:
 * Input:
 * Output:
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
 * Function:
 * Input:
 * Output:
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
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
void printMovieLog(void *x, void *outSel)
{
	fprintf((FILE*)(outSel),"%s\t%d\t%d\t%s\t%d\t%d\t%d\t%s\n",((MovieLog*)x)->title,((MovieLog*)x)->releaseYear,((MovieLog*)x)->runtime,((MovieLog*)x)->genres,((MovieLog*)x)->dvd,((MovieLog*)x)->bluray,((MovieLog*)x)->digital,((MovieLog*)x)->date);
}

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
void printMovieLogScreen(void *x)
{
	printw("%s\t%d\t%d\t%s\t%d\t%d\t%d\t%s\n",((MovieLog*)x)->title,((MovieLog*)x)->releaseYear,((MovieLog*)x)->runtime,((MovieLog*)x)->genres,((MovieLog*)x)->dvd,((MovieLog*)x)->bluray,((MovieLog*)x)->digital,((MovieLog*)x)->date);
//	refresh();
}

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
void addDvd(MovieLog *x)
{
	x->dvd = 1;
}

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
void addBluray(MovieLog *x)
{
	x->bluray = 1;
}

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
void addDigital(MovieLog *x)
{
	x->digital = 1;
}

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
void removeDvd(MovieLog *x)
{
	x->dvd = 0;
}

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
void removeBluray(MovieLog *x)
{
	x->bluray = 0;
}

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
void removeDigital(MovieLog *x)
{
	x->digital = 0;
}

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
void changeDate(MovieLog *x, char *date)
{
	x->date = strdup(date);
}

/*
 * Function:
 * Input:
 * Output:
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
 * Function:
 * Input:
 * Output:
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


