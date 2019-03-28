#ifndef DB_H_
#define DB_H_
#include "movie_entry.h"
#include <stdlib.h>


#define BLACK 1
#define RED 0

typedef struct _Node node;
typedef struct _Tree tree;

//Node structure for red black tree.
typedef struct _Node
{
	void *key;
	node *left, *right, *p;
	int color;
}node;

//RB Tree structure containing pointers for root, sentinel node, and matching function
typedef struct _Tree
{
	node *root;
	node *nil;
	int (*begMatch)(void *a, void *b);
	void (*print)(void *entry, void *outSel);
	int (*titleLessThan)(void *a, void *b);
	int (*titleGreaterThan)(void *a, void *b);
}tree;

node * newNode(void *key);
tree * newTree(int (*begMatch)(void *a, void *b), void (*print)(void *entry, void *outSel), int (*titleLessThan)(void *a, void *b), int (*titleGreaterThan)(void *a, void *b));
void leftRotate(tree *Tree, node *x);
void rightRotate( tree *Tree,  node *x);
void insert( tree *Tree,  node *z);
void insertFixup( tree *Tree,  node *z);
void rbTransplant( tree *Tree,  node *u,  node *v);
node * treeMinimum(tree *Tree, node *x);
void rbDelete(tree *Tree, node *z);
void rbDeleteFixup( tree *Tree,  node *x);
void inOrder(tree *Tree, void *outSel);
void inOrderAux(tree *Tree, node *x, void *outSel);
//tree * searchMain(tree *Tree, node *x, void *key);
tree * search(tree *Tree, void *key);
void searchAux(tree *Tree,tree *ret, node *x, void *key);




#endif
