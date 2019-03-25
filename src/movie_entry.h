#ifndef DB_H_
#define DB_H_
#include <stdlib.h>
#include <string.h>

typedef struct _MovieEntry MovieEntry;

//Structure to represent Movies/TV Shows with all retrieved data
typedef struct _MovieEntry
{
	char tconst[9];
	char titleType[10];
	char primaryTitle[50];
	char originalTitle[50];
	int isAdult;
	int startYear;
	int endYear;
	int runtimeMinutes;
	char genres[5][10];
}MovieEntry;

MovieEntry * newMovieEntry(char tc[], char tt[], char pt[], char ot[], int ia, int sy, int ey, int rm, char g[]);
int titleLessThan(MovieEntry *x, MovieEntry *y);
int titleGreaterThan(MovieEntry *x, MovieEntry *y);
int titleEqualTo(MovieEntry *x, MovieEntry *y);



#endif
