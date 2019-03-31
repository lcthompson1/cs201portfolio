#ifndef DB_H_
#define DB_H_
#include "movie_entry.h"
#include "movie_log.h"
#include "ll.h"
#include <stdlib.h>

/* db.h
 *
 * Header file for red black tree implementation
 *
 * Author: Logan Thompson
 * Date: 03/29/2019
 *
 *
 * ToDo: Nothing
 */

//Constants defined for easier node color identification
#define BLACK 1
#define RED 0

//struct declarations
typedef struct _Node node;
typedef struct _Tree tree;

/* Node structure for red black tree.
 *
 * Contains void pointer to hold any data type needed along with
 * node pointers to parent node, left child node, and right child node
 */
typedef struct _Node
{
	void *key;
	node *left, *right, *p;
	int color;
}node;

/* RB Tree structure containing pointers for root, sentinel node,
 * matching function pointer, file print function pointer,
 * screen print function, and comparison function pointers
 *
 */
typedef struct _Tree
{
	node *root;
	node *nil;
	int (*begMatch)(void *a, void *b);
	void (*print)(void *entry, void *outSel);
	void (*printScreen)(void *entry);
	int (*titleLessThan)(void *a, void *b);
	int (*titleGreaterThan)(void *a, void *b);
}tree;

//function declarations for red black tree
node * newNode(void *key);
tree * newTree(int (*begMatch)(void *a, void *b), void (*print)(void *entry, void *outSel), int (*titleLessThan)(void *a, void *b), int (*titleGreaterThan)(void *a, void *b), void (*printScreen)(void *entry));
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
void inOrderScreen(tree *Tree);
void inOrderAuxScreen(tree *Tree, node *x);
tree * search(tree *Tree, void *key, void *a, void *the);
void searchAux(tree *Tree,tree *ret, node *x, void *key);
LL * toLL(tree *Tree);
void toLLAux(tree *Tree, node *x, LL *ret);
node * exactSearch(tree *Tree, node *x);
node * exactSearchAux(tree *Tree, node *next, node *search);
LL * toLLLog(tree *Tree);
void toLLLogAux(tree *Tree, node *x, LL *ret);
void deleteTree(tree *Tree);
void deleteTreeAux(tree *Tree, node *Node);
tree * searchLog(tree *Tree, void *key);

#endif
