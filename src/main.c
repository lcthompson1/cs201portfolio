#include "db_create.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	tree *lookupTree = importFile("movie_records");


	inOrder(lookupTree);

	return 1;
}
