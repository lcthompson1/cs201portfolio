#include "ll.h"

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
 * Function: newLL
 * Input: None
 * Output: Pointer to new LinkedList structure
 *
 * Sets head and tail pointer to NULL for initialization
 *
 * ToDo: Nothing
 */
LL * newLL()
{
	LL *ret = malloc(sizeof(LL));

	ret->head = NULL;
	ret->tail = NULL;

	return ret;
}

/*
 * Function: newLLNode
 * Input: Pointer to MovieLog structure
 * Output: Pointer to LinkedList Node
 *
 * Returns a pointer to a LinkedList Node containing the MovieLog pointer passed to it
 *
 * ToDo: Nothing
 */
LLNode * newLLNode(MovieLog *data)
{
	LLNode *ret = malloc(sizeof(LLNode));
	ret->data = data;
	ret->next = NULL;
	ret->prev = NULL;

	return ret;
}

/*
 * Function: inserLL
 * Input: Pointer to LinkedList, Pointer to LinkedList node
 * Output: None
 *
 * Inserts the LinkedList node pointer into the LinkedList
 *
 * ToDo: Nothing
 */
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

/*
 * Function: printLL
 * Input: LinkedList node pointer
 * Output: None
 *
 * Prints the LinkedList from the tail to the head
 * Uses the MovieLog print method for printing individual MovieLog entries
 *
 * ToDo:
 */
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

/*
 * Function: getLog
 * Input: LinkedList pointer, selection integer
 * Output: MovieLog pointer
 *
 * Uses selection integer to retrieve te desired MovieLog entry
 *
 * ToDo: Nothing
 */
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
