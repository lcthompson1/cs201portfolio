#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "movie_log.h"

MovieLog * newMovieLog(MovieEntry *orig)
{
	MovieLog *x = malloc(sizeof(MovieLog));

	x->title = strdup(orig->primaryTitle);
	x->releaseYear = orig->startYear;
	x->runtime = orig->runtimeMinutes;
	x->genres = strdup(orig->genres);
	x->dvd = 0;
	x->bluray = 0;
	x->digital = 0;
	x->date = "";


	return x;
}

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

int logTitleLessThan(void *x, void *y)
{
	if(strcmp(((MovieLog*)x)->title, ((MovieLog*)y)->title) < 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int logTitleGreaterThan(void *x, void *y)
{
	if(strcmp(((MovieLog*)x)->title, ((MovieLog*)y)->title) > 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int logTitleEqualTo(MovieLog *x, MovieLog *y)
{
	if(strcmp(x->title, y->title) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void printMovieLog(void *x, void *outSel)
{
	fprintf((FILE*)(outSel),"%s\t%d\t%d\t%s\t%d\t%d\t%d\t%s\n",((MovieLog*)x)->title,((MovieLog*)x)->releaseYear,((MovieLog*)x)->runtime,((MovieLog*)x)->genres,((MovieLog*)x)->dvd,((MovieLog*)x)->bluray,((MovieLog*)x)->digital,((MovieLog*)x)->date);
}

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

int begLogMatch(void *x, void *y)
{
	int found;
	found = begMatchAux(((MovieEntry*)x)->primaryTitle,((MovieEntry*)y)->primaryTitle);
	return found;
}

int begLogMatchAux(const char *s1, const char *s2)
{
	char cs1;
	char cs2;

	if(!*s1)
	{
		return 1;
	}

	while((cs1 = *s1++) && (cs2 = *s2++))
	{
		if(tolower(cs1) != tolower(cs2))
			return 0;
	}

	if(!cs2)
		return 0;

	return 1;
}


