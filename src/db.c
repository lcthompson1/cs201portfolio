#include "db.h"
#include <stdio.h>
#include <stdlib.h>

node * newNode(int key)
{
	printf("6\n");
	node *x = malloc(sizeof(node));

	x->key = key;
	x->p = NULL;
	x->left = NULL;
	x->right = NULL;
	x->color = RED;
	printf("7\n");
	return x;
}

tree * newTree()
{
	printf("1\n");
	tree *x;
	printf("2\n");
	x->nil = newNode(0);
	printf("3\n");
	x->nil->color = BLACK;
	printf("4\n");
	x->root = x->nil;
	printf("5\n");
	return x;
}


void left_rotate(tree *Tree, node *x)
{
	printf("LR\n");
	node *y;
	y = x->right;

	x->right = y->left;

	if(y->left != Tree->nil)
	{
		y->left->p = x;
	}

	y->p = x->p;

	if(x->p == Tree->nil)
	{
		Tree->root = y;
	}
	else if(x == x->p->left)
	{
		x->p->left = y;
	}
	else
	{
		x->p->right = y;
	}

	y->left = x;

	x->p = y;
}



void right_rotate(tree *Tree, node *x)
{
	printf("RR\n");
	node *y;
	y = x->left;

	x->left = y->right;

	if(y->right != Tree->nil)
	{
		y->right->p = x;
	}

	y->p = x->p;

	if(x->p == Tree->nil)
	{
		Tree->root = y;
	}
	else if(x == x->p->right)
	{
		x->p->right = y;
	}
	else
	{
		x->p->left = y;
	}

	y->right = x;

	x->p = y;
}



void insert(tree *Tree, node *z)
{
	printf("Insert Start\n");

	node *y = Tree->nil;
	node *x = Tree->root;

	while( x != Tree->nil)
	{
		printf("Loop 1: x=%d    y=%d\n",x,y);
		printf("Loop 1\n");
		y = x;

		if(z->key < x->key)
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}

	printf("End: x=%d    y=%d\n",x,y);
	z->p = y;

	if(y == Tree->nil)
	{
		printf("1 Before  root:%d    y:%d\n",Tree->root,y);
		Tree->root = z;
		printf("1 After  root:%d    y:%d\n",Tree->root,y);
	}
	else if(z->key < y->key)
	{
		printf("2\n");
		y->left = z;
	}
	else
	{
		printf("3\n");
		y->right = z;
	}

	printf("End\n");
	z->left = Tree->nil;
	z->right = Tree->nil;
	z->color = RED;

	printf("End: z=%d  zKey=%d  root=%d  root->left:%d   root->right:%d  nil=%d\n",z,z->key,Tree->root,Tree->root->left,Tree->root->right,Tree->nil);

	printf("End of insert  root:%d    y:%d\n",Tree->root,y);
	insert_fixup(Tree, z);
}


void insert_fixup(tree *Tree, node *z)
{
	printf("Insert Fixup\n");
	node *y;

	printf("z->p->color: %d\n",z->p->color);
	while(z->p->color == RED)
	{
		printf("Step 1\n");
		if(z->p == z->p->p->left)
		{
			printf("Step 2\n");
			y = z->p->p->right;

			if(y->color == RED)
			{
				printf("Step 3\n");
				z->p->color = BLACK;
				y->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
			}
			else if(z == z->p->right)
			{
				printf("Step 4\n");
				z = z->p;
				left_rotate(Tree,z);
			}

			z->p->color = BLACK;
			z->p->p->color = RED;
			right_rotate(Tree,z->p->p);
		}
		else
		{
			printf("Step 5\n");
			y = z->p->p->left;

			if(y->color == RED)
			{
				printf("Step 6\n");
				z->p->color = BLACK;
				y->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
			}
			else if(z == z->p->left)
			{
				printf("Step 7\n");
				z = z->p;
				right_rotate(Tree,z);
			}

			z->p->color = BLACK;
			z->p->p->color = RED;
			left_rotate(Tree,z->p->p);
		}

	}

	printf("Step 8\n");
	Tree->root->color = BLACK;

	printf("End of fixup  root:%d    z:%d\n",Tree->root,z);
}

void rb_transplant(tree *Tree, node *u, node *v)
{
	if(u->p == Tree->nil)
	{
		Tree->root = v;
	}
	else if(u == u->p->left)
	{
		u->p->left = v;
	}
	else
	{
		u->p->right = v;
	}

	v->p = u->p;
}

/*
void rb_delete(struct tree Tree, struct node *z)
{
	struct node *y = z;
	struct node *x;

	int yColor = y->color;

	if(z->left == Tree->nil)
	{
		x = z->right;
		rb_transplant(Tree, z, z->right);
	}
	else if(z->right == Tree->nil)
	{
		x = z->left;
		rb_transplant(Tree, z, z->left);
	}
	else
	{
		y = tree_minimum(z->right);
		yColor = y->color;
		x = y->right;

		if(y->p == z)
		{
			x->p = y;
		}
		else
		{
			rb_transplant(Tree, y, y->right);
			y->right = z->right;
			y->right->p = y;
		}

		rb_transplant(Tree, z, y);
		y->left = z->left;
		y->left->p = y;
		y->color = z->color;
	}

	if(yColor == 1);
	{
		rb_delete_fixup(Tree, x);
	}
}



struct node * tree_minimum(struct node *x)
{

}
void rb_delete_fixup(struct tree Tree, struct node *x)
{

}
*/


void inOrder(tree *Tree)
{
	inOrderAux(Tree->root);
	printf("\n");
}

void inOrderAux(node *x)
{
	if(x == NULL)
		return;

	inOrderAux(x->left);
	printf("%d ",x->key);
	inOrderAux(x->right);
}





