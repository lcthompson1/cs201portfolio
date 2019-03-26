#include "db_create.h"
#include <stdio.h>
#include <stdlib.h>



MovieEntry * readEntry(char *line)
{
//	char *token = strtok(line,"")
//	char tc[9], tt[10], pt[50], ot[50], g[50];
//	int *ia, *sy, *ey, *rm;
//	sscanf(line, "%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%s\n",tc,tt,pt,ot,ia,sy,ey,rm,g);

	char *tc = strtok(line,"\t");
	char *tt = strtok(NULL,"\t");
	char *pt = strtok(NULL,"\t");
	char *ot = strtok(NULL,"\t");
	char *ia = strtok(NULL,"\t");
	char *sy = strtok(NULL,"\t");
	char *ey = strtok(NULL,"\t");
	char *rm = strtok(NULL,"\t");
	char *g = strtok(NULL,"\t");
/*
	printf("tc:%s  ",tc);
	printf("tt:%s  ",tt);
	printf("pt:%s  ",pt);
	printf("ot:%s  ",ot);
	printf("ia:%s  ",ia);
	printf("sy:%s  ",sy);
	printf("ey:%s  ",ey);
	printf("rm:%s  ",rm);
	printf("g:%s\n",g);
*/
//	MovieEntry *ret = newMovieEntry(tc,tt,pt,ot,*ia,*sy,*ey,*rm,g);
	MovieEntry *ret = newMovieEntry(tc,tt,pt,ot,1,1,1,1,g);
	return ret;
}


tree * importFile(char *fname)
{
	FILE *fp;
	char buf[460];
	tree *ret = newTree();

	fp = fopen(fname,"r");

	while(fgets(buf,460,fp) != NULL)
	{


//		printf("String is: %s\n", buf);

		MovieEntry *entry = readEntry(buf);
		insert(ret,newNode(entry));


	}

	fclose(fp);

	return ret;
}

void testRead(char *fname)
{
	FILE *fp;
	char buf[255];

	fp = fopen(fname,"r");

	while(fgets(buf, 255, fp))
	{
		printf("String is: %s\n", buf);
	}

	fclose(fp);

}
