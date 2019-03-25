#include "db.h"
#include <stdio.h>
#include <stdlib.h>

node * newNode(int key)
{
	node *x = malloc(sizeof(node));

	x->key = key;
	x->p = NULL;
	x->left = NULL;
	x->right = NULL;
	x->color = RED;
	return x;
}

tree * newTree()
{
	tree *x = malloc(sizeof(tree));
	node *sentinel = malloc(sizeof(node));
	sentinel->key = (int)NULL;
	sentinel->p = sentinel;
	sentinel->left = sentinel;
	sentinel->right = sentinel;
	sentinel->color = BLACK;

	x->nil = sentinel;
	x->root = x->nil;
	return x;
}


void left_rotate(tree *Tree, node *x)
{
	node *y = x->right;

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
	node *y = Tree->nil;
	node *x = Tree->root;

	while( x != Tree->nil)
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

	//This case works
	if(y == Tree->nil)
	{
		Tree->root = z;
	}
	//This case works
	else if(z->key < y->key)
	{
		y->left = z;
	}
	//This case works
	else
	{
		y->right = z;
	}

	z->left = Tree->nil;
	z->right = Tree->nil;
	z->color = RED;
//	inOrder(Tree);
	insert_fixup(Tree, z);
}


void insert_fixup(tree *Tree, node *z)
{
	node *y;

	while(z->p->color == RED)
	{
		if(z->p == z->p->p->left)
		{
			y = z->p->p->right;
//			inOrder(Tree);

			if(y->color == RED)
			{
				z->p->color = BLACK;
				y->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
//				inOrder(Tree);
			}
			else if(z == z->p->right)
			{
				z = z->p;
				left_rotate(Tree,z);
			}
			else
			{
/*
			printf("Root:%d  Nil:%d   ",Tree->root, Tree->nil);
			printf("z:%d   z color:%d   ",z,z->color);
			printf("z->p:%d   z->p color:%d   ",z->p,z->p->color);
//			printf("z->p->p:%d  z->p->p->color:%d\n",z->p->p,z->p->p->color);
			printf("z->p->p:%d",z->p->p);
*/
				z->p->color = BLACK;
				z->p->p->color = RED;
				right_rotate(Tree,z->p->p);
			}
		}
		else
		{
			y = z->p->p->left;

			if(y->color == RED)
			{
				z->p->color = BLACK;
				y->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
			}
			else if(z == z->p->left)
			{
				z = z->p;
				right_rotate(Tree,z);
			}
			else
			{
				z->p->color = BLACK;
				z->p->p->color = RED;
				left_rotate(Tree,z->p->p);
			}
		}

	}

	Tree->root->color = BLACK;

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
//	printf("Root:%d\n",Tree->root);
	inOrderAux(Tree, Tree->root);
	printf("\n");
}

void inOrderAux(tree *Tree, node *x)
{
	if(x == Tree->nil)
		return;

	inOrderAux(Tree, x->left);
	printf("(key:%d color:%d parent:%d left:%d right:%d)\n",x->key,x->color,x->p->key,x->left->key,x->right->key);
	//	printf("Key:%d  Color:%d  location:%d  parent loc:%d  left loc:%d  right loc:%d\n",x->key, x->color, x, x->p, x->left, x->right);
	inOrderAux(Tree, x->right);
}





