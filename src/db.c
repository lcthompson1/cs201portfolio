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
 * Function: newNode
 * Input: void pointer
 * Output:node pointer
 *
 * Creates a new node with the key passed to it and returns a pointer to it
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
 * Function: newTree
 * Input: comparison and print function pointers
 * Output: tree pointer
 *
 * Creates a tree using passed function pointers and returns a pointer to it
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
 * Function: leftRotate
 * Input: tree, node
 * Output: none
 *
 * performs a BST left rotate
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
 * Function: rightRotate
 * Input:tree, node
 * Output: none
 *
 * Performs a BST right rotate
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
 * Function: insert
 * Input:tree, node
 * Output:none
 *
 * inserts the passed node into the tree then performs an RB fixup
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
 * Function: insertFixup
 * Input: tree, node
 * Output: none
 *
 * Performs a RB fixup, repairing RBTree violations in the passed tree
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
 * Function: rbDelete
 * Input:tree, node
 * Output:none
 *
 * Performs a BST node delete and then calls a RB fixup
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
	free(z);
}


/*
 * Function: treeMinimum
 * Input:tree, node
 * Output:node pointer
 *
 * Recursively searches for lowest value in tree and returns a pointer to it
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
 * Function: rbDeleteFixup
 * Input:tree, node
 * Output:none
 *
 * Performs a RBTree fixup to repair any tree violations
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
 * Function: search
 * Input:tree, void pointer
 * Output: tree pointer
 *
 * Returns a tree with all entries that match the desired key(substring based)
 *
 * ToDo:
 */
tree * search(tree *Tree, void *key, void *a, void *the)
{
	tree *ret = newTree(Tree->begMatch,Tree->print, Tree->titleLessThan, Tree->titleGreaterThan, Tree->printScreen);

	searchAux(Tree, ret, Tree->root,a);
	searchAux(Tree,ret,Tree->root,key);
	searchAux(Tree, ret, Tree->root,the);


	return ret;


}

/*
 * Function: searchAux
 * Input:tree, tree, node ,void pointer
 * Output:none
 *
 * Auxillary function to search for recursion
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
 * Function: inOrder
 * Input:tree, void pointer
 * Output:none
 *
 * Performs an inorder traversal of provided key and prints it to specified file pointer
 *
 * ToDo:
 */
void inOrder(tree *Tree, void *outSel)
{
	inOrderAux(Tree, Tree->root, outSel);
}

/*
 * Function: inOderAux
 * Input:tree, void pointer
 * Output:none
 *
 * Auxillary function to inOrder
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
 * Function: inOrderScreen
 * Input: tree
 * Output:none
 *
 * Performs inorder traversal of tree and prints to screen using ncurses
 *
 * ToDo:
 */
void inOrderScreen(tree *Tree)
{
	inOrderAuxScreen(Tree, Tree->root);
}

/*
 * Function: inOrderScreenAux
 * Input: tree, node
 * Output: none
 *
 * Auxillary function to inOrderScreen for recursion
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
 * Function: toLL
 * Input: tree
 * Output: linkedlist
 *
 * Inserts tree entries in order into a new linkedlist and returns a pointer to it
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
 * Function: toLLAux
 * Input:tree, node, linkedlist
 * Output:none
 *
 * Auxillary function for toLL for recursion
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
 * Function: toLLLog
 * Input: tree
 * Output: LinkedList pointer
 *
 * Inserts tree entries in order into a new linkedlist and returns a pointer to it
 *
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
 * Function:toLLLogAux
 * Input:tree, node, linked list
 * Output:none
 *
 * Auxillary function to toLLLogAux for recursion
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

/*
 * Function: exactSearch
 * Input:tree, node
 * Output:none
 *
 * searches for an exact match between the provided node and all nodes in tree
 * Returns found node or Tree->nil if not found
 *
 * ToDo:
 */
node * exactSearch(tree *Tree, node *x)
{
	return exactSearchAux(Tree, Tree->root, x);
}

/*
 * Function: exactSearchAux
 * Input:tree, node, node
 * Output:none
 *
 * Auxillary function to exactSearch for recursion
 * searches for an exact match between the provided node and all nodes in tree
 * Returns found node or Tree->nil if not found
 *
 * ToDo:
 */
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










