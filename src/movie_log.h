#ifndef MOVIE_LOG_H_
#define MOVIE_LOG_H_
#include <stdlib.h>
#include <string.h>

typedef struct _MovieLog MovieLog;

//Structure to represent Movies/TV Shows with all retrieved data
typedef struct _MovieLog
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
}MovieLog;

MovieLog * newMovieLog(char *tc, char *tt, char *pt, char *ot, int ia, int sy, int ey, int rm, char *g);
MovieLog * newMovieLogSearch(char *title);
int titleLessThan(MovieLog *x, MovieLog *y);
int titleGreaterThan(MovieLog *x, MovieLog *y);
int titleEqualTo(MovieLog *x, MovieLog *y);
void printTconst(MovieLog *x);
void printTitleType(MovieLog *x);
void printPrimaryTitle(MovieLog *x);
void printOriginalTitle(MovieLog *x);
void printIsAdult(MovieLog *x);
void printStartYear(MovieLog *x);
void printEndYear(MovieLog *x);
void printRuntimeMinutes(MovieLog *x);
void printGenres(MovieLog *x);
void printMovieLog(MovieLog *x);

#endif
