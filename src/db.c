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
	sentinel->p = sentinel;
	sentinel->left = sentinel;
	sentinel->right = sentinel;
	sentinel->color = BLACK;

	x->nil = sentinel;
	x->root = x->nil;
	return x;
}


void leftRotate(tree *Tree, node *x)
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



void rightRotate(tree *Tree, node *x)
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

	if(y == Tree->nil)
	{
		Tree->root = z;
	}
	else if(z->key < y->key)
	{
		y->left = z;
	}
	else
	{
		y->right = z;
	}

	z->left = Tree->nil;
	z->right = Tree->nil;
	z->color = RED;
	insertFixup(Tree, z);
}


void insertFixup(tree *Tree, node *z)
{
	node *y;

	while(z->p->color == RED)
	{
		if(z->p == z->p->p->left)
		{
			y = z->p->p->right;

			if(y->color == RED)
			{
				z->p->color = BLACK;
				y->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
			}
			else if(z == z->p->right)
			{
				z = z->p;
				leftRotate(Tree,z);
			}
			else
			{
				z->p->color = BLACK;
				z->p->p->color = RED;
				rightRotate(Tree,z->p->p);
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
				rightRotate(Tree,z);
			}
			else
			{
				z->p->color = BLACK;
				z->p->p->color = RED;
				leftRotate(Tree,z->p->p);
			}
		}

	}

	Tree->root->color = BLACK;

}

void rbTransplant(tree *Tree, node *u, node *v)
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


void rbDelete(tree *Tree, node *z)
{
	node *y = z;
	node *x;

	int yOrigColor = y->color;

	if(z->left == Tree->nil)
	{
		x = z->right;
		rbTransplant(Tree, z, z->right);
	}
	else if(z->right == Tree->nil)
	{
		x = z->left;
		rbTransplant(Tree, z, z->left);
	}
	else
	{
		y = treeMinimum(Tree, z->right);
		yOrigColor = y->color;
		x = y->right;

		if(y->p == z)
		{
			x->p = y;
		}
		else
		{
			rbTransplant(Tree, y, y->right);
			y->right = z->right;
			y->right->p = y;
		}

		rbTransplant(Tree, z, y);
		y->left = z->left;
		y->left->p = y;
		y->color = z->color;
	}

	if(yOrigColor == BLACK)
	{
		rbDeleteFixup(Tree, x);
	}
}



node * treeMinimum(tree *Tree, node *x)
{
	node *current = x;

	while(current->left != Tree->nil)
	{
		current = current->left;
	}

	return current;
}

void rbDeleteFixup(tree *Tree, node *x)
{
	while(x != x->p->left)
	{
		if(x == x->p->left)
		{
			node *w = x->p->right;
			if(w->color == RED)
			{
				w->color = BLACK;
				x->p->color = RED;
				leftRotate(Tree, x->p);
				w = x->p->right;
			}
			if((w->left->color == BLACK) & (w->right->color == BLACK))
			{
				w->color = RED;
				x = x->p;
			}
			else if(w->right->color == BLACK)
			{
				w->left->color = BLACK;
				w->color = RED;
				rightRotate(Tree,w);
				w = x->p->right;
			}
			else
			{
				w->color = x->p->color;
				x->p->color = BLACK;
				w->right->color = BLACK;
				leftRotate(Tree,x->p);
				x = Tree->root;
			}
		}
		else
		{
			node *w = x->p->left;
			if(w->color == RED)
			{
				w->color = BLACK;
				x->p->color = RED;
				rightRotate(Tree, x->p);
				w = x->p->left;
			}
			if((w->right->color == BLACK) & (w->left->color == BLACK))
			{
				w->color = RED;
				x = x->p;
			}
			else if(w->left->color == BLACK)
			{
				w->right->color = BLACK;
				w->color = RED;
				leftRotate(Tree,w);
				w = x->p->left;
			}
			else
			{
				w->color = x->p->color;
				x->p->color = BLACK;
				w->left->color = BLACK;
				rightRotate(Tree,x->p);
				x = Tree->root;
			}
		}
	}
	x->color = BLACK;
}

node * search(tree *Tree, node *x, int key)
{
	if((x == Tree->nil) | (key == x->key))
	{
		return x;
	}
	if(key < x->key)
	{
		return search(Tree,x->left,key);
	}
	else
	{
		return search(Tree,x->right,key);
	}
}

void inOrder(tree *Tree)
{
	inOrderAux(Tree, Tree->root);
	printf("\n");
}

void inOrderAux(tree *Tree, node *x)
{
	if(x == Tree->nil)
		return;

	inOrderAux(Tree, x->left);
	printf("%d ",x->key);
	inOrderAux(Tree, x->right);
}
