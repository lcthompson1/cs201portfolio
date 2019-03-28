#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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

int titleLessThan(void *x, void *y)
{
	if(strcmp(((MovieEntry*)x)->primaryTitle, ((MovieEntry*)y)->primaryTitle) < 0)
	{
//		printf("%s less than %s = 1\n",x->primaryTitle,y->primaryTitle);
		return 1;
	}
	else
	{
//		printf("%s less than %s = 0\n",x->primaryTitle,y->primaryTitle);
		return 0;
	}
}

int titleGreaterThan(void *x, void *y)
{
	if(strcmp(((MovieEntry*)x)->primaryTitle, ((MovieEntry*)y)->primaryTitle) > 0)
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



void printMovieEntry(void *x, void *outSel)
{
	fprintf((FILE*)(outSel),"%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%s\n",((MovieEntry*)x)->tconst,((MovieEntry*)x)->titleType,((MovieEntry*)x)->primaryTitle,((MovieEntry*)x)->originalTitle,((MovieEntry*)x)->isAdult,((MovieEntry*)x)->startYear,((MovieEntry*)x)->endYear,((MovieEntry*)x)->runtimeMinutes,((MovieEntry*)x)->genres);
}

int begMatchAux(const char *s1, const char *s2)
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

int begMatch(void *x, void *y)
{
	int found;
	found = begMatchAux(((MovieEntry*)x)->primaryTitle,((MovieEntry*)y)->primaryTitle);
	return found;
}






