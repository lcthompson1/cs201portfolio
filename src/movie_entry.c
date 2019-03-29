#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <ncurses.h>
#include "movie_entry.h"

/* movie_entry.c
 *
 * Contains all functions related to the MovieEntry structure
 *
 *
 * Author: Logan Thompson
 * Date: 03/29/2019
 *
 *
 * ToDo: Nothing
 */

/*
 * Function: newMovieEntry
 * Input: char pointers and integers containing MovieEntry variables
 * Output: MovieEntry pointer
 *
 * ToDo: Nothing
 */
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

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
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

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
char * toLowerString(char *string)
{
	char *s = strdup(string);

	for(int i = 0; s[i] != '\0';i++)
	{
		s[i] = tolower(s[i]);
	}

	return s;
}

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
int titleLessThan(void *x, void *y)
{
	if(strcmp(toLowerString(((MovieEntry*)x)->primaryTitle), toLowerString(((MovieEntry*)y)->primaryTitle)) < 0)
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

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
int titleGreaterThan(void *x, void *y)
{
	if(strcmp(toLowerString(((MovieEntry*)x)->primaryTitle), toLowerString(((MovieEntry*)y)->primaryTitle)) > 0)
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
int titleEqualTo(MovieEntry *x, MovieEntry *y)
{
	if(strcmp(toLowerString(x->primaryTitle), toLowerString(y->primaryTitle)) == 0)
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
void printMovieEntry(void *x, void *outSel)
{
	fprintf((FILE*)(outSel),"%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%s\n",((MovieEntry*)x)->tconst,((MovieEntry*)x)->titleType,((MovieEntry*)x)->primaryTitle,((MovieEntry*)x)->originalTitle,((MovieEntry*)x)->isAdult,((MovieEntry*)x)->startYear,((MovieEntry*)x)->endYear,((MovieEntry*)x)->runtimeMinutes,((MovieEntry*)x)->genres);
}

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
void printMovieEntryScreen(void *x)
{
	printw("%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%s\n",((MovieEntry*)x)->tconst,((MovieEntry*)x)->titleType,((MovieEntry*)x)->primaryTitle,((MovieEntry*)x)->originalTitle,((MovieEntry*)x)->isAdult,((MovieEntry*)x)->startYear,((MovieEntry*)x)->endYear,((MovieEntry*)x)->runtimeMinutes,((MovieEntry*)x)->genres);
}

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
int begMatchAux(const char *searchTerm, const char *full)
{
	char st;
	char f;
	int ret = 1;

	for(int x = 0; searchTerm[x] != '\0'; x++)
	{
		st = searchTerm[x];
		f = full[x];

		st = tolower(st);
		f = tolower(f);

		if(st != f)
		{
			ret = 0;
			break;
		}
	}
	return ret;
}

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
int begMatch(void *x, void *y)
{
	int found;
	found = begMatchAux(((MovieEntry*)x)->primaryTitle,((MovieEntry*)y)->primaryTitle);
	return found;
}






