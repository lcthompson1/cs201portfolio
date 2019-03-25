#ifndef DB_H_
#define DB_H_
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
	int key;
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




node * newNode(int key);
tree * newTree();
void left_rotate(tree *Tree, node *x);
void right_rotate( tree *Tree,  node *x);
void insert( tree *Tree,  node *z);
void insert_fixup( tree *Tree,  node *z);
void rb_transplant( tree *Tree,  node *u,  node *v);
 node * tree_minimum( node *x);
void rb_delete_fixup( tree *Tree,  node *x);
void inOrder(tree *Tree);
void inOrderAux(tree *Tree, node *x);

#endif
