#include "ll.h"


LL * newLL()
{
	LL *ret = malloc(sizeof(LL));

	ret->head = NULL;
	ret->tail = NULL;

	return ret;
}

LLNode * newLLNode(MovieLog *data)
{
	LLNode *ret = malloc(sizeof(LLNode));
	ret->data = data;
	ret->next = NULL;
	ret->prev = NULL;

	return ret;
}


void insertLL(LL *list, LLNode *x)
{

	if(list->head == NULL)
	{
		list->head = x;
		list->tail = x;
	}
	else
	{
		x->next = list->head;
		list->head->prev = x;
		list->head = x;
	}

	list->size++;
}

void printLL(LL *list)
{
	int current = 1;
	LLNode *x = list->tail;
	while(x != NULL)
	{
		printw("%d)\t",current);
		printMovieLogScreen(x->data);
		x = x->prev;
		current++;
	}
}

MovieLog * getLog(LL *list, int sel)
{
	int x = sel - 1;
	LLNode *y = list->tail;

	while(x != 0)
	{
		y = y->prev;
		x--;
	}

	return y->data;
}
