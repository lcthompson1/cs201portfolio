//#include "movie_entry.h"
//#include "db_create.h"
#include "db.h"
#include <stdio.h>
#include <stdlib.h>



int main()
{



	tree *x = newTree();
//	tree x;
	int  y[] = {48, 72, 38, 85, 53, 90, 14, 89, 86, 93, 42, 33, 23, 55, 16, 80, 40, 64, 68, 87};


//	for(int i = 0; i < 20; i++)
//	{
//		printf("%d",y[i]);
//		insert(x,newNode(y[i]));
//		inOrder(x);
//	}

	insert(x,newNode(48));
	insert(x,newNode(72));
	insert(x,newNode(38));
	insert(x,newNode(85));
	insert(x,newNode(53));
	insert(x,newNode(90));
	insert(x,newNode(14));
	insert(x,newNode(89));
	insert(x,newNode(86));
	insert(x,newNode(93));
	insert(x,newNode(42));
	insert(x,newNode(33));
	insert(x,newNode(23));
	insert(x,newNode(55));
	insert(x,newNode(16));
	insert(x,newNode(80));
	insert(x,newNode(40));
	insert(x,newNode(64));
	insert(x,newNode(68));
	insert(x,newNode(87));


	inOrder(x);



	return 1;
}
