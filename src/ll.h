#ifndef LL_H_
#define LL_H_
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ncurses.h>
#include "movie_log.h"

/* ll.h
 *
 * Header file for linked list. Used for search results.
 *
 * Author: Logan Thompson
 * Date: 03/29/2019
 *
 *
 * ToDo: Nothing
 */

//struct declarations
typedef struct _LLNode LLNode;
typedef struct _LL LL;

/* Linked List node structure that holds a MovieLog pointer as its data
 * and pointers to the next and previous nodes for doubly linked functionality
 *
 */
typedef struct _LLNode
{
	MovieLog *data;
	LLNode *next, *prev;
}LLNode;

/* Linked list structure that contains pointers to head and tail nodes
 *
 */
typedef struct _LL
{
	int size;
	LLNode *head, *tail;
}LL;

//Function declarations for implementation
LL * newLL();
LLNode * newLLNode(MovieLog *data);
void insertLL(LL *list, LLNode *x);
void printLL(LL *list);
MovieLog * getLog(LL *list, int sel);


#endif
