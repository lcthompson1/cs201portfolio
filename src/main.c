#include "menu.h"
#include "db_create.h"
#include "movie_log.h"
#include "log_create.h"
#include <stdlib.h>
#include <ncurses.h>

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

int main()
{
	printStart();
	tree *lookupTree = importFile("movie_records");
	clear();
	printw("Completed!\n");

	int menuChoice = 0;
	menuChoice = retrieveMenuOption();

	while(!(menuChoice == 3))
	{
		if(menuChoice == 2)
		{
			menuChoice = printNewLogMenu(lookupTree);
		}
		else if(menuChoice == 1)
		{
			menuChoice = printExistingLogMenu(lookupTree);
		}
		else
		{
			menuChoice = retrieveMenuOption();
		}
	}

	endwin();

	return 1;
}










