#include "db.h"
#include <stdio.h>
#include <stdlib.h>

struct node * newNode(int key)
{
	struct node *x = malloc(sizeof(struct node));

	x->key = key;
	x->p = NULL;
	x->left = NULL;
	x->right = NULL;
	x->color = 0;

	return x;
}

struct tree newTree()
{
	struct tree x;
	x.nil = newNode(0);
	x.root = NULL;
	return x;
}


void left_rotate(struct tree Tree, struct node *x)
{
	struct node *y;
	y = x->right;

	x->right = y->left;

	if(y->left != Tree.nil)
	{
		y->left->p = x;
	}

	y->p = x->p;

	if(x->p == Tree.nil)
	{
		Tree.root = y;
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



void right_rotate(struct tree Tree, struct node *x)
{
	struct node *y;
	y = x->left;

	x->left = y->right;

	if(y->right != Tree.nil)
	{
		y->right->p = x;
	}

	y->p = x->p;

	if(x->p == Tree.nil)
	{
		Tree.root = y;
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



void insert(struct tree Tree, struct node *z)
{
	struct node *y, *x;

	y = Tree.nil;
	x = Tree.root;

	while( x != Tree.nil)
	{
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

	z->p = y;

	if(y == Tree.nil)
	{
		Tree.root = z;
	}
	else if(z->key < y->key)
	{
		y->left = z;
	}
	else
	{
		y->right = z;
	}

	z->left = Tree.nil;
	z->right = Tree.nil;
	z->color = 0;

	insert_fixup(Tree, z);
}


void insert_fixup(struct tree Tree, struct node *z)
{
	struct node *y;

	while(z->p->color == 0)
	{
		if(z->p == z->p->p->left)
		{
			y = z->p->p->right;

			if(y->color == 0)
			{
				z->p->color = 1;
				y->color = 1;
				z->p->p->color = 0;
				z = z->p->p;
			}

			else if(z == z->p->right)
			{
				z = z->p;
				left_rotate(Tree,z);
			}

			z->p->color = 1;
			z->p->p->color = 0;
			right_rotate(Tree,z->p->p);
		}
		else
		{
			y = z->p->p->left;

			if(y->color == 0)
			{
				z->p->color = 1;
				y->color = 1;
				z->p->p->color = 0;
				z = z->p->p;
			}

			else if(z == z->p->left)
			{
				z = z->p;
				right_rotate(Tree,z);
			}

			z->p->color = 1;
			z->p->p->color = 0;
			left_rotate(Tree,z->p->p);
		}

	}

	Tree.root->color = 1;
}

void rb_transplant(struct tree Tree, struct node *u, struct node *v)
{
	if(u->p == Tree.nil)
	{
		Tree.root = v;
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

	if(z->left == Tree.nil)
	{
		x = z->right;
		rb_transplant(Tree, z, z->right);
	}
	else if(z->right == Tree.nil)
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

