#ifndef MENU_H_
#define MENU_H_
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include "db_create.h"
#include "log_create.h"
#include "ll.h"


void printStart();
void retrieveMenuOption(char *menuChoice);
void printNewLogMenu(char *menuChoice, tree *lookupTree);
void printExistingLogMenu(char *menuChoice, tree *lookupTree);
void searchAdd(char *searchTerm, tree *lookupTree, char *fName);












#endif
