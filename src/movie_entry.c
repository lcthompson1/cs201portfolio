#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie_entry.h"

MovieEntry * newMovieEntry(char tc[], char tt[], char pt[], char ot[], int ia, int sy, int ey, int rm, char g[])
{
	MovieEntry *x = malloc(sizeof(MovieEntry));

	strcpy(x->tconst, tc);
	strcpy(x->titleType, tt);
	strcpy(x->primaryTitle, pt);
	strcpy(x->originalTitle, ot);
	x->isAdult = ia;
	x->startYear = sy;
	x->endYear = ey;
	x->runtimeMinutes = rm;
//	x->genres[5][10] = g;

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
