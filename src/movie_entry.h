#ifndef MOVIE_ENTRY_H_
#define MOVIE_ENTRY_H_
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* movie_entry.h
 *
 * Contains a MovieEntry structure and declarations for related functions
 *
 * Author: Logan Thompson
 * Date: 03/29/2019
 *
 *
 * ToDo: Nothing
 */

//Structure declaration for MovieEntry
typedef struct _MovieEntry MovieEntry;

//Structure to represent Movies/TV Shows with all retrieved data from file
typedef struct _MovieEntry
{
	char *tconst;
	char *titleType;
	char *primaryTitle;
	char *originalTitle;
	int isAdult;
	int startYear;
	int endYear;
	int runtimeMinutes;
	char *genres;
}MovieEntry;

//Function declarations for all MovieEntry related functions
MovieEntry * newMovieEntry(char *tc, char *tt, char *pt, char *ot, int ia, int sy, int ey, int rm, char *g);
MovieEntry * newMovieEntrySearch(char *title);
char * toLowerString(char *s);
int titleLessThan(void *x, void *y);
int titleGreaterThan(void *x, void *y);
int titleEqualTo(MovieEntry *x, MovieEntry *y);
void printMovieEntry(void *x, void *outSel);
void printMovieEntryScreen(void *x);
int begMatchAux(const char *s1, const char *s2);
int begMatch(void *x, void *y);

#endif
