#include "db_create.h"
#include <stdio.h>
#include <stdlib.h>
/*db_create.c
 * This file implements functions meant to retrieve MovieEntry items from a text file
 * and load them into a red black tree
 *
 * Author: Logan Thompson
 * Date: 03/29/2019
 *
 *
 * ToDo: implement incorrect file name handling
 */



/*
 * Function: readEntry
 * Input: String containing a line read from the text file
 * Output: Pointer to MovieEntry struct to be loaded into red black tree
 *
 * ToDo: Nothing
 */
MovieEntry * readEntry(char *line)
{
	char *tc = strtok(line,"\t");
	char *tt = strtok(NULL,"\t");
	char *pt = strtok(NULL,"\t");
	char *ot = strtok(NULL,"\t");
	char *ia = strtok(NULL,"\t");
	char *sy = strtok(NULL,"\t");
	char *ey = strtok(NULL,"\t");
	char *rm = strtok(NULL,"\t");
	char *g = strtok(NULL,"\t");

	g[strlen(g)-1] = 0;

	MovieEntry *ret = newMovieEntry(tc,tt,pt,ot,atoi(ia),atoi(sy),atoi(ey),atoi(rm),g);
	return ret;
}

/*
 * Function: importFile
 * Input:char pointer representing file name
 * Output: Red black tree containing a sorted database of MovieEntries retrieved from text file
 *
 * ToDo: Implement incorrect file name handling
 */
tree * importFile(char *fname)
{
	FILE *fp;
	char buf[460];
	tree *ret = newTree(begMatch,printMovieEntry, titleLessThan, titleGreaterThan, printMovieEntryScreen);

	fp = fopen(fname,"r");

	while(fgets(buf,460,fp) != NULL)
	{
		if(!(strcmp(buf,"\n") == 0))
		{
			MovieEntry *entry = readEntry(buf);
			insert(ret,newNode(entry));
		}
	}

	fclose(fp);
	return ret;
}
