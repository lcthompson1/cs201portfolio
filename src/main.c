//#include "movie_entry.h"
//#include "db_create.h"
#include "db.h"
#include <stdio.h>
#include <stdlib.h>



int main()
{



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


	return 1;
}
