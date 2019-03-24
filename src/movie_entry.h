#ifndef DB_H_
#define DB_H_
#include <stdlib.h>

//Structure to represent Movies/TV Shows with all retrieved data
struct MovieEntry
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
};




#endif
