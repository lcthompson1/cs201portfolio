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

	char menuChoice[5] = "";
	retrieveMenuOption(menuChoice);

	while(!(strcmp(menuChoice,"3") == 0))
	{
		if(strcmp(menuChoice,"2") == 0)
		{
			printNewLogMenu(menuChoice,lookupTree);
		}
		else if(strcmp(menuChoice,"1") == 0)
		{
			printExistingLogMenu(menuChoice, lookupTree);
		}
	}

	endwin();

	return 1;
}










