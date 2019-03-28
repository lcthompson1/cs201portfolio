#ifndef MOVIE_LOG_H_
#define MOVIE_LOG_H_
#include <stdlib.h>
#include <string.h>
#include "movie_entry.h"

typedef struct _MovieLog MovieLog;

//Structure to represent Movies/TV Shows with all retrieved data
typedef struct _MovieLog
{
	char *title;
	int releaseYear;
	int runtime;
	char *genres;
	int dvd;
	int bluray;
	int digital;
	char *date;
}MovieLog;

MovieLog * newMovieLog(MovieEntry *orig);
MovieLog * newMovieLogFile(char *title, int releaseYear, int runtime, char *genres, int dvd, int bluray, int digital, char *date);
MovieLog * newMovieLogSearch(char *title);

int logTitleLessThan(void *x, void *y);
int logTitleGreaterThan(void *x, void *y);
int logTitleEqualTo(MovieLog *x, MovieLog *y);
void printMovieLog(void *x, void *outSel);
void addDvd(MovieLog *x);
void addBluray(MovieLog *x);
void addDigital(MovieLog *x);
void removeDvd(MovieLog *x);
void removeBluray(MovieLog *x);
void removeDigital(MovieLog *x);
int begLogMatch(void *x, void *y);
int begLogMatchAux(const char *s1, const char *s2);


#endif
