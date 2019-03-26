#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie_log.h"

MovieLog * newMovieLog(char *tc, char *tt, char *pt, char *ot, int ia, int sy, int ey, int rm, char *g)
{
	MovieLog *x = malloc(sizeof(MovieLog));

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

MovieLog * newMovieLogSearch(char *title)
{
	MovieLog *x = malloc(sizeof(MovieLog));

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

int titleLessThan(MovieLog *x, MovieLog *y)
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

int titleGreaterThan(MovieLog *x, MovieLog *y)
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

int titleEqualTo(MovieLog *x, MovieLog *y)
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

void printTconst(MovieLog *x)
{
	printf("%s",x->tconst);
}

void printTitleType(MovieLog *x)
{
	printf("%s",x->titleType);
}

void printPrimaryTitle(MovieLog *x)
{
	printf("%s",x->primaryTitle);
}

void printOriginalTitle(MovieLog *x)
{
	printf("%s",x->originalTitle);
}

void printIsAdult(MovieLog *x)
{
	printf("%d",x->isAdult);
}

void printStartYear(MovieLog *x)
{
	printf("%s",x->tconst);
}

void printEndYear(MovieLog *x)
{
	printf("%d",x->endYear);
}

void printRuntimeMinutes(MovieLog *x)
{
	printf("%d",x->runtimeMinutes);
}

void printGenres(MovieLog *x)
{
	printf("%s",x->genres);
}

void printMovieLog(MovieLog *x)
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
