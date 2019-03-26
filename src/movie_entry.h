#ifndef MOVIE_ENTRY_H_
#define MOVIE_ENTRY_H_
#include <stdlib.h>
#include <string.h>

typedef struct _MovieEntry MovieEntry;

//Structure to represent Movies/TV Shows with all retrieved data
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

MovieEntry * newMovieEntry(char tc[], char tt[], char pt[], char ot[], int ia, int sy, int ey, int rm, char g[]);
MovieEntry * newMovieEntrySearch(char *title);
int titleLessThan(MovieEntry *x, MovieEntry *y);
int titleGreaterThan(MovieEntry *x, MovieEntry *y);
int titleEqualTo(MovieEntry *x, MovieEntry *y);
void printTconst(MovieEntry *x);
void printTitleType(MovieEntry *x);
void printPrimaryTitle(MovieEntry *x);
void printOriginalTitle(MovieEntry *x);
void printIsAdult(MovieEntry *x);
void printStartYear(MovieEntry *x);
void printEndYear(MovieEntry *x);
void printRuntimeMinutes(MovieEntry *x);
void printGenres(MovieEntry *x);
void printMovieEntry(MovieEntry *x);

#endif
