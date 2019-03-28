#include "db_create.h"
#include <stdio.h>
#include <stdlib.h>

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


tree * importFile(char *fname)
{
	FILE *fp;
	char buf[460];
	tree *ret = newTree(begMatch,printMovieEntry, titleLessThan, titleGreaterThan);

	fp = fopen(fname,"r");

	while(fgets(buf,460,fp) != NULL)
	{
		MovieEntry *entry = readEntry(buf);
		insert(ret,newNode(entry));
	}

	fclose(fp);
	return ret;
}
