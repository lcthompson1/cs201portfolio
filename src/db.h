#ifndef DB_H_
#define DB_H_
#include "movie_entry.h"
#include <stdlib.h>


#define BLACK 1
#define RED 0

typedef struct _Node node;
typedef struct _Tree tree;

//Node structure for red black tree.
//Red = 0
//Black = 1
typedef struct _Node
{
	MovieEntry *key;
//	MovieEntry *key;
	node *left, *right, *p;
	int color;
}node;

//RB Tree structure containing pointers for root and nil
typedef struct _Tree
{
	node *root;
	node *nil;
}tree;




node * newNode(MovieEntry *key);
tree * newTree();
void leftRotate(tree *Tree, node *x);
void rightRotate( tree *Tree,  node *x);
void insert( tree *Tree,  node *z);
void insertFixup( tree *Tree,  node *z);
void rbTransplant( tree *Tree,  node *u,  node *v);
node * treeMinimum(tree *Tree, node *x);
void rbDelete(tree *Tree, node *z);
void rbDeleteFixup( tree *Tree,  node *x);
void inOrder(tree *Tree);
void inOrderAux(tree *Tree, node *x);
node * search(tree *Tree, node *x, MovieEntry *key);

#endif
