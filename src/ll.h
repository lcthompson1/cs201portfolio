#ifndef LL_H_
#define LL_H_
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ncurses.h>
#include "movie_log.h"


typedef struct _LLNode LLNode;
typedef struct _LL LL;

typedef struct _LLNode
{
	MovieLog *data;
	LLNode *next, *prev;
}LLNode;

typedef struct _LL
{
	int size;
	LLNode *head, *tail;
}LL;

LL * newLL();
LLNode * newLLNode(MovieLog *data);
void insertLL(LL *list, LLNode *x);
void printLL(LL *list);
MovieLog * getLog(LL *list, int sel);


#endif
