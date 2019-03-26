#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie_entry.h"

MovieEntry * newMovieEntry(char *tc, char *tt, char *pt, char *ot, int ia, int sy, int ey, int rm, char *g)
{
	MovieEntry *x = malloc(sizeof(MovieEntry));

	x->tconst = strdup(tc);
	x->titleType = strdup(tt);
	x->primaryTitle = strdup(pt);
	x->originalTitle = strdup(ot);
	x->isAdult = ia;
	x->startYear = sy;
	x->endYear = ey;
	x->runtimeMinutes = rm;
	x->genres = strdup(g);

	return x;
}

MovieEntry * newMovieEntrySearch(char *title)
{
	MovieEntry *x = malloc(sizeof(MovieEntry));

	x->tconst = "";
	x->titleType = "";
	x->primaryTitle = strdup(title);
	x->originalTitle = "";
	x->isAdult = 0;
	x->startYear = 0;
	x->endYear = 0;
	x->runtimeMinutes = 0;
	x->genres = "";

	return x;
}

int titleLessThan(MovieEntry *x, MovieEntry *y)
{
	if(strcmp(x->primaryTitle, y->primaryTitle) < 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int titleGreaterThan(MovieEntry *x, MovieEntry *y)
{
	if(strcmp(x->primaryTitle, y->primaryTitle) > 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int titleEqualTo(MovieEntry *x, MovieEntry *y)
{
	if(strcmp(x->primaryTitle, y->primaryTitle) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void printTconst(MovieEntry *x)
{
	printf("%s",x->tconst);
}

void printTitleType(MovieEntry *x)
{
	printf("%s",x->titleType);
}

void printPrimaryTitle(MovieEntry *x)
{
	printf("%s",x->primaryTitle);
}

void printOriginalTitle(MovieEntry *x)
{
	printf("%s",x->originalTitle);
}

void printIsAdult(MovieEntry *x)
{
	printf("%d",x->isAdult);
}

void printStartYear(MovieEntry *x)
{
	printf("%s",x->tconst);
}

void printEndYear(MovieEntry *x)
{
	printf("%d",x->endYear);
}

void printRuntimeMinutes(MovieEntry *x)
{
	printf("%d",x->runtimeMinutes);
}

void printGenres(MovieEntry *x)
{
	printf("%s",x->genres);
}

void printMovieEntry(MovieEntry *x)
{


	printTconst(x);
	printf("     ");
	printTitleType(x);
	printf("     ");
	printPrimaryTitle(x);
	printf("     ");
	printOriginalTitle(x);
	printf("     ");
	printIsAdult(x);
	printf("     ");
	printStartYear(x);
	printf("     ");
	printEndYear(x);
	printf("     ");
	printRuntimeMinutes(x);
	printf("     ");
	printGenres(x);
	printf("\n");
}
