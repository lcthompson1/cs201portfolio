#include <db.h>
#include <stdio.h>

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



//RB Tree structure containing pointers for root and nil
struct tree
{
	struct node *root;

};

//Node structure for red black tree.
//Red = 0
//Black = 0
struct node
{
	struct MovieEntry *key;
	struct node *left, *right, *p;
	int color;
};



void left_rotate(Tree, x)
{
	struct node *y;
	y = x.right;

	x.right = y.left;

	if(y.left != Tree.nil)
	{
		y.left.p = x;
	}

	y.p = x.p;

	if(x.p == T.nil)
	{
		T.root = y;
	}
	else if(x == x.p.left)
	{
		x.p.left = y;
	}
	else
	{
		x.p.right = y;
	}

	y.left = x;

	x.p = y;
}


void right_rotate(Tree, x)
{
	struct node *y;
	y = x.left;

	x.left = y.right;

	if(y.right != Tree.nil)
	{
		y.right.p = x;
	}

	y.p = x.p;

	if(x.p == Tree.nil)
	{
		Tree.root = y;
	}
	else if(x == x.p.right)
	{
		x.p.right = y;
	}
	else
	{
		x.p.left = y;
	}

	y.right = x;

	x.p = y;
}

void insert(Tree, z)
{
	struct node *y, *x;

	y = Tree.nil;
	x = Tree.root;

	while( x != Tree.nil)
	{
		y = x;

		if(z.key < x.key)
		{
			x = x.left;
		}
		else
		{
			x = x.right;
		}
	}

	z.p = y;

	if(y == Tree.nil)
	{
		Tree.root = z;
	}
	elseif(z.key < y.key)
	{
		y.left = z;
	}
	else
	{
		y.right = z;
	}

	z.left = Tree.nil;
	z.right = Tree.nil;
	z.color = 0;

	insert_fixup(Tree, z);
}









