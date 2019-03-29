#include "db.h"
#include <stdio.h>
#include <stdlib.h>

/*
 *
 *
 *
 * Author: Logan Thompson
 * Date: 03/29/2019
 *
 *
 * ToDo:
 */

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
node * newNode(void *key)
{
	node *x = malloc(sizeof(node));

	x->key = key;
	x->p = NULL;
	x->left = NULL;
	x->right = NULL;
	x->color = RED;
	return x;
}

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
tree * newTree(int (*begMatch)(void *a, void *b), void (*print)(void *entry, void *outSel), int (*titleLessThan)(void *a, void *b), int (*titleGreaterThan)(void *a, void *b), void (*printScreen)(void *entry))
{
	tree *x = malloc(sizeof(tree));
	node *sentinel = malloc(sizeof(node));
	sentinel->p = sentinel;
	sentinel->left = sentinel;
	sentinel->right = sentinel;
	sentinel->color = BLACK;

	x->nil = sentinel;
	x->root = x->nil;
	x->begMatch = begMatch;
	x->print = print;
	x->printScreen = printScreen;
	x->titleGreaterThan = titleGreaterThan;
	x->titleLessThan = titleLessThan;
	return x;
}

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
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


/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
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


/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
void insert(tree *Tree, node *z)
{
	node *y = Tree->nil;
	node *x = Tree->root;

	while( x != Tree->nil)
	{
		y = x;

		if(Tree->titleLessThan(z->key ,x->key))
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
	else if(Tree->titleLessThan(z->key ,y->key))
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

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
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

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
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

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
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


/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
node * treeMinimum(tree *Tree, node *x)
{
	node *current = x;

	while(current->left != Tree->nil)
	{
		current = current->left;
	}

	return current;
}

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
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


/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
tree * search(tree *Tree, void *key)
{
	tree *ret = newTree(Tree->begMatch,Tree->print, Tree->titleLessThan, Tree->titleGreaterThan, Tree->printScreen);

	searchAux(Tree,ret,Tree->root,key);

	return ret;


}

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
void searchAux(tree *lookupTree, tree *ret, node *x, void *key)
{
	if((x == lookupTree->nil))
	{
		return;
	}
	else if(lookupTree->begMatch(key,x->key))
	{
		node *y = newNode(x->key);
		insert(ret,y);


		searchAux(lookupTree,ret,x->left,key);
		searchAux(lookupTree,ret,x->right,key);

	}
	else if(lookupTree->titleLessThan(key ,x->key))
	{
		searchAux(lookupTree,ret,x->left,key);
	}
	else if(lookupTree->titleGreaterThan(key,x->key))
	{
		searchAux(lookupTree,ret,x->right,key);
	}
}

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
void inOrder(tree *Tree, void *outSel)
{
	inOrderAux(Tree, Tree->root, outSel);
}

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
void inOrderAux(tree *Tree, node *x, void *outSel)
{
	if(x == Tree->nil)
		return;

	inOrderAux(Tree, x->left, (FILE*)(outSel));
//	printMovieEntry(x->key);
	Tree->print(x->key, outSel);
	inOrderAux(Tree, x->right, (FILE*)(outSel));
}

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
void inOrderScreen(tree *Tree)
{
	inOrderAuxScreen(Tree, Tree->root);
}

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
void inOrderAuxScreen(tree *Tree, node *x)
{
	if(x == Tree->nil)
		return;

	inOrderAuxScreen(Tree, x->left);
	Tree->printScreen(x->key);
	inOrderAuxScreen(Tree, x->right);
}

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
LL * toLL(tree *Tree)
{
	LL *ret = newLL();

	toLLAux(Tree, Tree->root,ret);
	return ret;
}

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
void toLLAux(tree *Tree, node *x, LL *ret)
{
	if(x == Tree->nil)
		return;



	toLLAux(Tree, x->left, ret);
	insertLL(ret,newLLNode(newMovieLog(x->key,"03-28-2019")));
	toLLAux(Tree, x->right, ret);
}

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
LL * toLLLog(tree *Tree)
{
	LL *ret = newLL();

	toLLLogAux(Tree, Tree->root,ret);
	return ret;
}

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
void toLLLogAux(tree *Tree, node *x, LL *ret)
{
	if(x == Tree->nil)
		return;



	toLLLogAux(Tree, x->left, ret);
	insertLL(ret,newLLNode(x->key));
	toLLLogAux(Tree, x->right, ret);
}

node * exactSearch(tree *Tree, node *x)
{
	return exactSearchAux(Tree, Tree->root, x);
}

node * exactSearchAux(tree *Tree, node *next, node *search)
{
	if((next == Tree->nil) || (strcmp(((MovieLog*)next->key)->title,((MovieLog*)search->key)->title) == 0))
	{
		return next;
	}


	if((strcmp(((MovieLog*)next->key)->title,((MovieLog*)search->key)->title) > 0))
	{
		return exactSearchAux(Tree,next->left,search);
	}

		return exactSearchAux(Tree,next->right,search);
}










