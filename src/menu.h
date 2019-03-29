#ifndef MENU_H_
#define MENU_H_
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include "db_create.h"
#include "log_create.h"
#include "ll.h"

/* menu.h
 *
 * Header file for menu implementation
 *
 * Author: Logan Thompson
 * Date: 03/29/2019
 *
 * ToDo: Nothing
 */

//Declarations for all functions used in menu implementation
void printStart();
int modifyLogMenu(tree *userTree, char *searchTerm, char *fName);
int displayLogMenu(tree *userTree);
int retrieveMenuOption();
int printNewLogMenu(tree *lookupTree);
int printExistingLogMenu(tree *lookupTree);
void searchAdd(char *searchTerm, tree *lookupTree, char *fName, tree *temp);

#endif
