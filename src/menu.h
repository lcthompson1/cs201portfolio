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
void modifyLogMenu(tree *userTree, char *searchTerm, char *fName);
int displayLogMenu(tree *userTree);
void retrieveMenuOption(char *menuChoice);
void printNewLogMenu(char *menuChoice, tree *lookupTree);
void printExistingLogMenu(char *menuChoice, tree *lookupTree);
void searchAdd(char *searchTerm, tree *lookupTree, char *fName, tree *temp);

#endif
