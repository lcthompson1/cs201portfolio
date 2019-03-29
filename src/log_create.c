#include "log_create.h"
#include <stdio.h>
#include <stdlib.h>

/*
 *
 *
 *
 * Author: Logan Thompson
 * Date: 03/29/2019
 *
 *
 * ToDo:
 */

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
MovieLog * readUserLogEntry(char *line)
{
	char *title = strtok(line,"\t");
	char *genres = strtok(NULL,"\t");
	char *runtime = strtok(NULL,"\t");
	char *releaseYear = strtok(NULL,"\t");
	char *dvd = strtok(NULL,"\t");
	char *bluray = strtok(NULL,"\t");
	char *digital = strtok(NULL,"\t");
	char *date = strtok(NULL,"\t");



	MovieLog *ret = newMovieLogFile(title, atoi(releaseYear), atoi(runtime), genres, atoi(dvd), atoi(bluray), atoi(digital), date);
	return ret;
}

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
tree * importLogFile(char *fname)
{
	FILE *fp;
	char buf[460];
	tree *ret = newTree(begLogMatch, printMovieLog, logTitleLessThan, logTitleGreaterThan, printMovieLogScreen);

	fp = fopen(fname,"r");

	while(fgets(buf,460,fp) != NULL)
	{
		if(!(strcmp(buf,"\n") == 0))
		{
			MovieLog *entry = readUserLogEntry(buf);
			insert(ret,newNode(entry));
		}
	}

	fclose(fp);
	return ret;
}

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
void exportLogFile(tree *Tree, char *fname)
{
	FILE *fp;

	fp = fopen(fname,"w");

	inOrder(Tree,fp);

	fclose(fp);
}
