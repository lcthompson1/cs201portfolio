#include "menu.h"

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
 * Function: printStart
 * Input:none
 * Output:none
 *
 * Displays opening message
 *
 * ToDo:
 */
void printStart()
{
	initscr();
	printw("Loading lookup database, please wait.");
	refresh();
}

/*
 * Function: retrieveMenuOption
 * Input:None
 * Output:Integer to determine next menu
 *
 * Displays menu options and returns integer to move to desired menu
 *
 * ToDo:
 */
int retrieveMenuOption()
{
	clear();
	printw("MAIN MENU\nPlease select an option below.\n(1) Select an existing log file\n(2) Create a new log file\n(3) Exit application\n");
	refresh();
	char menuChoice[2] = "";
	getnstr(menuChoice,1);

	while(!(((strcmp("1",menuChoice)) == 0) | ((strcmp("2",menuChoice)) == 0) | ((strcmp("3",menuChoice)) == 0)))
	{
		clear();
		printw("MAIN MENU\nPlease select a correct option below. *note: Only a single digit(1, 2, or 3) is considered valid input\n(1) Select an existing log file\n(2) Create a new log file\n(3) Exit application\n");
		refresh();
		getnstr(menuChoice,1);
	}

	return atoi(menuChoice);
}

/*
 * Function: printNewLogMenu
 * Input: lookup tree
 * Output: integer to determine next menu
 *
 * Allows user to create a new log file and add a new entry.
 * Returns an integer to determine next menu state
 *
 * ToDo:
 */
int printNewLogMenu(tree *lookupTree)
{
	clear();
	printw("NEW LOG MENU\nPlease enter a name for the file(Less than 50 characters)\n");
	refresh();
	char fName[50] = "";
	getnstr(fName,50);
	strcat(fName,".log");

	while(ifExists(fName))
	{
		clear();
		printw("NEW LOG MENU\nThat file already exists, please enter a new file name\n");
		refresh();
		getnstr(fName,50);
		strcat(fName,".log");
	}

	clear();
	printw("NEW LOG MENU\nPlease enter the title you want to search for.\n");
	refresh();
	char searchTerm[300] = "";
	getstr(searchTerm);

	tree *temp = newTree(begMatch,printMovieLog,logTitleLessThan,logTitleGreaterThan,printMovieLogScreen);
	searchAdd(searchTerm, lookupTree, fName, temp);

	clear();
	printw("Log file created and entry added successfully! Would you like to create another log? ('y' for yes, 'n' to return to main menu)");
	refresh();
	char choice[2] = "";
	getnstr(choice,1);

	while(1)
	{
		if((strcmp(choice,"y") == 0))
		{
			return 2;
		}
		else if((strcmp(choice,"n") == 0))
		{
			return 0;
		}
		else
		{
			clear();
			printw("Incorrect input, please enter 'y' or 'n'.\nWould you like to continue editing this log? ('y' for yes, 'n' to return to main menu)");
			refresh();
			getnstr(choice,1);
		}
	}



//	getch();
}

/*
 * Function: printExistingLogMenu
 * Input:lookup tree
 * Output:integer
 *
 * Displays the available options for an existing log.
 * Returns an integer to choose next menu choice
 *
 * ToDo:
 */
int printExistingLogMenu(tree *lookupTree)
{
	clear();
	printw("EXISTING LOG MENU\nPlease enter the name of the user file you want to modify.\n");
	refresh();
	char fName[54] = "";
	getstr(fName);
	strcat(fName,".log");
	clear();

	while(!ifExists(fName))
	{
		clear();
		printw("EXISTING LOG MENU\nThat file does not exists, please enter a new file name\n");
		refresh();
		getnstr(fName,50);
		strcat(fName,".log");
	}

	tree *userTreeTitle = importLogFile(fName);

	char sel[10] = "";
	printw("Select an operation to perform.\n(1)\tView user log\n(2)\tAdd a new entry to the log\n(3)\tModify an existing entry in the log\n");
	refresh();
	getnstr(sel,1);

	int selectMode = atoi(sel);

	while(1)
	{

		if(selectMode == 0)
		{
			return 0;
		}
		else if(selectMode == 1)
		{
			selectMode = displayLogMenu(userTreeTitle);

		}
		else if(selectMode == 2)
		{
			clear();
			printw("EXISTING LOG MENU -- Add Entry\nPlease enter the title you want to search for.\n");
			refresh();
			char searchTerm[300] = "";
			getnstr(searchTerm,300);

			searchAdd(searchTerm, lookupTree, fName, userTreeTitle);

			clear();
			printw("EXISTING LOG MENU -- Add Entry\nEntry successfully added.\nChoose which operation to perform next.\n(1)\tView this log\n(2)\tModify an existing entry in this log\n(3)\tAdd another entry to this log\n(4)\tReturn to main menu\n");
			refresh();
			char select[2] = "";
			getnstr(select,1);

			while(1)
			{
				int selectM = atoi(select);
				if(selectM == 1)
				{
					selectMode = 1;
					break;
				}
				else if(selectM == 2)
				{
					selectMode = 3;
					break;
				}
				else if(selectM == 3)
				{
					selectMode = 2;
					break;
				}
				else if(selectM == 4)
				{
					selectMode = 0;
					break;
				}
				else
				{
					printw("Invalid Option.\nChoose which operation to perform next.\n(1)\tView this log\n(2)\tModify an existing entry in this log\n(3)\tAdd another entry to this log\n(4)\tReturn to main menu\n");
					refresh();
					getnstr(select,1);
				}
			}
		}
		else if(selectMode == 3)
		{
			clear();
			printw("EXISTING LOG MENU -- Modify Entry\nPlease enter the title you want to search for to modify.\n");
			refresh();
			char searchTerm[300] = "";
			getstr(searchTerm);

			selectMode = modifyLogMenu(userTreeTitle, searchTerm, fName);
		}
		else
		{
			clear();
			printw("Select an operation to perform.\n(1)\tView user log\n(2)\tAdd a new entry to the log\n(3)\tModify an existing entry in the log\n");
			refresh();
			getnstr(sel,1);
			selectMode = atoi(sel);
		}


	}

//	exportLogFile(userTreeTitle,fName);

}

/*
 * Function: searchAdd
 * Input: char pointer to search title, search tree , filename, and tree to modify
 * Output: N/A
 *
 * Searches for and adds entry to user tree with desired media types and date
 *
 *
 * ToDo:
 */
void searchAdd(char *searchTerm, tree *lookupTree, char *fName, tree *temp)
{
	MovieEntry *x;
	tree *results;
	LL *resultsLL;

//	if(!(strcmp(searchTerm,"") == 0))
	//{
	x = newMovieEntry("", "",searchTerm, "", 0, 0, 0, 0, "");
	results = search(lookupTree, x);
	resultsLL = toLL(results);
	//}

//	char searchT[300] = "";

	while(1)
	{
		/*
		if((strcmp(searchT,"") == 0))
		{
			clear();
			printw("No results found for that search, please refine your search. Enter the title you want to search for.\n");
			refresh();
//			searchT[300] = "";
			getnstr(searchT,300);
		}
		*/
		if((results->root == results->nil))
		{
			clear();
			printw("No results found for that search, please refine your search. Enter the title you want to search for.\n");
			refresh();
			char searchT[300] = "";
			getnstr(searchT,300);
			x = newMovieEntry("", "",searchT, "", 0, 0, 0, 0, "");
			results = search(lookupTree, x);
			resultsLL = toLL(results);
		}
		else if(resultsLL->size > 20)
		{
			clear();
			printw("Too many results found for that search, please refine your search. Enter the title you want to search for.\n");
			refresh();
			char searchT[300] = "";
			getnstr(searchT,300);
			x = newMovieEntry("", "",searchT, "", 0, 0, 0, 0, "");
			results = search(lookupTree, x);
			resultsLL = toLL(results);
		}
		else
		{
			break;
		}
	}


	clear();
	printw("Please select the number of the movie you want to add.\n");
	printLL(resultsLL);
	refresh();
	char sel[10] = "";
	getstr(sel);
	MovieLog *add = getLog(resultsLL,atoi(sel));

	int media = 0;
	while((media < 1) || (media > 3))
	{
		clear();
		printw("Please select the media option you wish to add.\n(1)\tAdd DVD\n(2)\tAdd BluRay\n(3)\tAdd Digital\n");
		refresh();
		char mediaChoice[10] = "";
		getstr(mediaChoice);
		media = atoi(mediaChoice);

		if(media == 1)
		{
			addDvd(add);
		}
		else if(media == 2)
		{
			addBluray(add);
		}
		else if(media == 3)
		{
			addDigital(add);
		}
	}

	clear();
	printw("Please enter the date that this media was added to your collection. (Format: 03-19-2019)\n");
	refresh();
	char date[10] = "";
	getnstr(date,10);
	changeDate(add,date);

	insert(temp,newNode(add));
	exportLogFile(temp,fName);



}

/*
 * Function: modifyLogMenu
 * Input: red black tree of user log, char pointer to search title, char pointer to filename
 * Output:integer to determine next menu
 *
 * Allows the user to search for an entry in the user log and modify it.
 * Returns an int that determines next menu
 *
 * ToDo:
 */
int modifyLogMenu(tree *userTree, char *searchTerm, char *fName)
{
	MovieLog *x = newMovieLogSearch(searchTerm);
	tree *results = search(userTree, x);
	LL *resultsLL = toLLLog(results);

	while(1)
	{
		if((results->root == results->nil))
		{
			clear();
			printw("No results found for that search, please refine your search. Enter the title you want to search for.\n");
			refresh();
			char searchT[300] = "";
			getnstr(searchT,300);
			x = newMovieLogSearch(searchT);
			results = search(userTree, x);
			resultsLL = toLLLog(results);
		}
		else if(resultsLL->size > 20)
		{
			clear();
			printw("Too many results found for that search, please refine your search. Enter the title you want to search for.\n");
			refresh();
			char searchT[300] = "";
			getnstr(searchT,300);
			x = newMovieLogSearch(searchT);
			results = search(userTree, x);
			resultsLL = toLLLog(results);
		}
		else
		{
			break;
		}
	}



	clear();
	printw("Please select the number of the movie you want to modify.\n");
	printLL(resultsLL);
	refresh();
	char sel[10] = "";
	getstr(sel);
	MovieLog *searchLog = getLog(resultsLL,atoi(sel));

	node *retNode = exactSearch(userTree,newNode(searchLog));


	int media = 0;
	while((media < 1) || (media > 6))
	{
		clear();
		printw("Please select the media option you wish to modify.\n(1)\tAdd DVD\n(2)\tRemove DVD\n(3)\tAdd BluRay\n(4)\tRemove BluRay\n(5)\tAdd Digital\n(6)\tRemove Digital\n");
		refresh();
		char mediaChoice[10] = "";
		getstr(mediaChoice);
		media = atoi(mediaChoice);

		if(media == 1)
		{
			addDvd(((MovieLog*)retNode->key));
		}
		else if(media == 2)
		{
			removeDvd(((MovieLog*)retNode->key));
		}
		else if(media == 3)
		{
			addBluray(((MovieLog*)retNode->key));
		}
		else if(media == 4)
		{
			removeBluray(((MovieLog*)retNode->key));
		}
		else if(media == 5)
		{
			addDigital(((MovieLog*)retNode->key));
		}
		else if(media == 6)
		{
			removeDigital(((MovieLog*)retNode->key));
		}
	}

	if((((MovieLog*)retNode->key)->dvd == 0) && (((MovieLog*)retNode->key)->bluray == 0) && (((MovieLog*)retNode->key)->digital == 0))
	{
		rbDelete(userTree,retNode);
		printw("All media was removed, the entry has been deleted\n");
		refresh();
	}
	else
	{
		clear();
		printw("Please enter the date that this media was added to your collection. (Format: 03-19-2019)\n");
		refresh();
		char date[10] = "";
		getstr(date);
		changeDate(((MovieLog*)retNode),date);
	}



	exportLogFile(userTree,fName);

	printw("\nChoose which operation to perform next.\n(1)\tAdd a new entry to this log\n(2)\tView the contents of this log\n(3)\tModify another log\n(4)\tReturn to main menu\n");
	refresh();
	char select[2] = "";
	getnstr(select,1);

	while(1)
	{
		int selectMode = atoi(select);
		if(selectMode == 1)
		{
			return 2;
		}
		else if(selectMode == 2)
		{
			return 1;
		}
		else if(selectMode == 3)
		{
			return 3;
		}
		else if(selectMode == 4)
		{
			return 0;
		}
		else
		{
			printw("Invalid Option.\nChoose which operation to perform next.\n(1)\tAdd a new entry to this log\n(2)\tModify an existing entry in this log\n(3)\tReturn to main menu\n");
			refresh();
			getnstr(select,1);
		}
	}

}

/*
 * Function: displayLogMenu
 * Input: red black tree
 * Output: int
 *
 * Displays a menu to list the entries inside a user log. Returns an int that determines next menu to go to.
 *
 * ToDo:
 */
int displayLogMenu(tree *userTree)
{
	clear();
	inOrderScreen(userTree);
	printw("\nChoose which operation to perform next.\n(1)\tAdd a new entry to this log\n(2)\tModify an existing entry in this log\n(3)\tReturn to main menu\n");
	refresh();
	char sel[2] = "";
	getnstr(sel,1);



	while(1)
	{
		int selectMode = atoi(sel);
		if(selectMode == 1)
		{
			return 2;
		}
		else if(selectMode == 2)
		{
			return 3;
		}
		else if(selectMode == 3)
		{
			return 0;
		}
		else
		{
			printw("Invalid Option.\nChoose which operation to perform next.\n(1)\tAdd a new entry to this log\n(2)\tModify an existing entry in this log\n(3)\tReturn to main menu\n");
			refresh();
			getnstr(sel,1);
		}
	}


	return 0;
}







