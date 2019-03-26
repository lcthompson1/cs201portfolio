//#include "movie_entry.h"
//#include "db.h"
#include "db_create.h"
#include <stdio.h>
#include <stdlib.h>


//#include "db_create.h"





int main()
{


/*
	tree *x = newTree();
	int  y[] = {48, 72, 38, 85, 53, 90, 14, 89, 86, 93, 42, 33, 23, 55, 16, 80, 40, 64, 68, 87};


	for(int i = 0; i < 20; i++)
	{
		insert(x,newNode(y[i]));
	}

	inOrder(x);

//	rbDelete(x,x->root);
//	inOrder(x);


	node *result = search(x,x->root,86);
	printf("Found node value:%d   location:%d\n",result->key,result);


	for(int i = 0; i < 20; i++)
		{
			node *z = search(x,x->root,y[i]);
			rbDelete(x,z);
			inOrder(x);
		}

		inOrder(x);

	insert(x, newNode(100));
	inOrder(x);

*/

	/*

	char *g[5] = {"Action","Comedy","Drama","Romantic","Suspense"};
	MovieEntry *z1 = newMovieEntry("t001", "movie", "aTest Movie", "Early Test Movie", 0, 1998, 2000, 120, g);
	MovieEntry *z2 = newMovieEntry("t001", "movie", "bTest Movie", "Early Test Movie", 0, 1998, 2000, 120, g);
	MovieEntry *z3 = newMovieEntry("t001", "movie", "cTest Movie", "Early Test Movie", 0, 1998, 2000, 120, g);
	MovieEntry *z4 = newMovieEntry("t001", "movie", "dTest Movie", "Early Test Movie", 0, 1998, 2000, 120, g);
	MovieEntry *z5 = newMovieEntry("t001", "movie", "eTest Movie", "Early Test Movie", 0, 1998, 2000, 120, g);
	MovieEntry *z6 = newMovieEntry("t001", "movie", "fTest Movie", "Early Test Movie", 0, 1998, 2000, 120, g);
	MovieEntry *z7 = newMovieEntry("t001", "movie", "jTest Movie", "Early Test Movie", 0, 1998, 2000, 120, g);
	MovieEntry *z8 = newMovieEntry("t001", "movie", "gTest Movie", "Early Test Movie", 0, 1998, 2000, 120, g);
	MovieEntry *z9 = newMovieEntry("t001", "movie", "hTest Movie", "Early Test Movie", 0, 1998, 2000, 120, g);
	MovieEntry *z10 = newMovieEntry("t001", "movie", "1Test Movie", "Early Test Movie", 0, 1998, 2000, 120, g);
	MovieEntry *z11= newMovieEntry("t001", "movie", "4Test Movie", "Early Test Movie", 0, 1998, 2000, 120, g);
	MovieEntry *z12 = newMovieEntry("t001", "movie", "lTest Movie", "Early Test Movie", 0, 1998, 2000, 120, g);
	MovieEntry *z13 = newMovieEntry("t001", "movie", "pTest Movie", "Early Test Movie", 0, 1998, 2000, 120, g);
	MovieEntry *z14 = newMovieEntry("t001", "movie", "oTest Movie", "Early Test Movie", 0, 1998, 2000, 120, g);
	MovieEntry *z15 = newMovieEntry("t001", "movie", "yTest Movie", "Early Test Movie", 0, 1998, 2000, 120, g);
	MovieEntry *z16 = newMovieEntry("t001", "movie", "zTest Movie", "Early Test Movie", 0, 1998, 2000, 120, g);
	MovieEntry *z17 = newMovieEntry("t001", "movie", "rTest Movie", "Early Test Movie", 0, 1998, 2000, 120, g);
	MovieEntry *z18 = newMovieEntry("t001", "movie", "mTest Movie", "Early Test Movie", 0, 1998, 2000, 120, g);
	MovieEntry *z19 = newMovieEntry("t001", "movie", "qTest Movie", "Early Test Movie", 0, 1998, 2000, 120, g);
	MovieEntry *z20 = newMovieEntry("t001", "movie", "wTest Movie", "Early Test Movie", 0, 1998, 2000, 120, g);


	tree *x = newTree();


	insert(x,newNode(z1));
	insert(x,newNode(z2));
	insert(x,newNode(z3));
	insert(x,newNode(z4));
	insert(x,newNode(z5));
	insert(x,newNode(z6));
	insert(x,newNode(z7));
	insert(x,newNode(z8));
	insert(x,newNode(z9));
	insert(x,newNode(z10));
	insert(x,newNode(z11));
	insert(x,newNode(z12));
	insert(x,newNode(z13));
	insert(x,newNode(z14));
	insert(x,newNode(z15));
	insert(x,newNode(z16));
	insert(x,newNode(z17));
	insert(x,newNode(z18));
	insert(x,newNode(z19));
	insert(x,newNode(z20));

	inOrder(x);
*/

//	testRead("test_file");


	tree *x = importFile("movie_records");
/*	MovieEntry *y = newMovieEntrySearch("impetu");
	node *result = search(x,x->root,y);
	rbDelete(x,result);



	printf("Size of tree:%d",x->size);

	for(int i = 0; i < 513850; i++)
		{

			printf("i:%d   size of tree:%d   ",i,x->size);
			rbDelete(x,x->root);
			printf("Size after delete:%d\n",x->size);
		}
	*/

	inOrder(x);

	return 1;
}
