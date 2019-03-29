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
 * Function:
 * Input:
 * Output:
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
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
void retrieveMenuOption(char *menuChoice)
{
	clear();
	printw("MAIN MENU\nPlease select an option below.\n(1) Select an existing log file\n(2) Create a new log file\n(3) Exit application\n");
	refresh();
	getnstr(menuChoice,1);

	while(!(((strcmp("1",menuChoice)) == 0) | ((strcmp("2",menuChoice)) == 0) | ((strcmp("3",menuChoice)) == 0)))
	{
		menuChoice = strdup("");
		clear();
		printw("MAIN MENU\nPlease select a correct option below. *note: Only a single digit(1, 2, or 3) is considered valid input\n(1) Select an existing log file\n(2) Create a new log file\n(3) Exit application\n");
		refresh();
		getnstr(menuChoice,1);
	}
}

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
void printNewLogMenu(char *menuChoice, tree *lookupTree)
{
	clear();
	printw("NEW LOG MENU\nPlease enter a name for the file(Less than 50 characters)\n");
	refresh();
	char fName[54] = "";
	getstr(fName);
	strcat(fName,".log");
	clear();
	printw("NEW LOG MENU\nPlease enter the title you want to search for.\n");
	refresh();
	char searchTerm[300] = "";
	getstr(searchTerm);

	tree *temp = newTree(begMatch,printMovieLog,logTitleLessThan,logTitleGreaterThan,printMovieLogScreen);
	searchAdd(searchTerm, lookupTree, fName, temp);

	clear();
	printw("Log file created and entry added successfully! Would you like to continue editing this log? ('y' for yes, 'n' to return to main menu)");
	refresh();
	getch();

	getch();
}

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
void printExistingLogMenu(char *menuChoice, tree *lookupTree)
{
	clear();
	printw("EXISTING LOG MENU\nPlease enter the name of the user file you want to modify.\n");
	refresh();
	char fName[54] = "";
	getstr(fName);
	strcat(fName,".log");
	clear();

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
			break;
		}
		else if(selectMode == 1)
		{
			selectMode = displayLogMenu(userTreeTitle);

		}
		else if(selectMode == 2)
		{
			clear();
			printw("EXISTING LOG MENU\nPlease enter the title you want to search for.\n");
			refresh();
			char searchTerm[300] = "";
			getstr(searchTerm);

			searchAdd(searchTerm, lookupTree, fName, userTreeTitle);

			clear();
			printw("\nChoose which operation to perform next.\n(1)\tView this log\n(2)\tModify an existing entry in this log\n");
			refresh();
			char tempSel[10] = "";
			getstr(tempSel);
			int selectModeTemp = atoi(tempSel);
			if(selectModeTemp == 1)
			{
				selectMode = 1;
			}
			else if(selectModeTemp == 2)
			{
				selectMode = 3;
			}
			else
			{
				selectMode = 0;
			}
		}
		else if(selectMode == 3)
		{
			clear();
			printw("EXISTING LOG MENU\nPlease enter the title you want to search for to modify.\n");
			refresh();
			char searchTerm[300] = "";
			getstr(searchTerm);

			modifyLogMenu(userTreeTitle, searchTerm, fName);
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
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
void searchAdd(char *searchTerm, tree *lookupTree, char *fName, tree *temp)
{
	MovieEntry *x = newMovieEntry("", "",searchTerm, "", 0, 0, 0, 0, "");
	tree *results = search(lookupTree, x);


	while(results->root == results->nil)
	{
		clear();
		printw("No results found for that search, please refine your search. Enter the title you want to search for.\n");
		refresh();
		char searchT[300] = "";
		getstr(searchT);
		x = newMovieEntry("", "",searchT, "", 0, 0, 0, 0, "");
		results = search(lookupTree, x);
	}

	LL *resultsLL = toLL(results);


	clear();
	printw("Please select the number of the movie you want to add.\n");
	printLL(resultsLL);
	refresh();
	char sel[10] = "";
	getstr(sel);
	MovieLog *add = getLog(resultsLL,atoi(sel));

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
			addDvd(add);
		}
		else if(media == 2)
		{
			removeDvd(add);
		}
		else if(media == 3)
		{
			addBluray(add);
		}
		else if(media == 4)
		{
			removeBluray(add);
		}
		else if(media == 5)
		{
			addDigital(add);
		}
		else if(media == 6)
		{
			removeDigital(add);
		}
	}

	clear();
	printw("Please enter the date that this media was added to your collection. (Format: 03-19-2019)\n");
	refresh();
	char date[10] = "";
	getstr(date);
	changeDate(add,date);

	insert(temp,newNode(add));
	exportLogFile(temp,fName);



}

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
void modifyLogMenu(tree *userTree, char *searchTerm, char *fName)
{
	MovieLog *x = newMovieLogSearch(searchTerm);
	tree *results = search(userTree, x);


	while(results->root == results->nil)
	{
		clear();
		printw("No results found for that search, please refine your search. Enter the title you want to search for.\n");
		refresh();
		char searchT[300] = "";
		getstr(searchT);
		x = newMovieLogSearch(searchT);
		results = search(userTree, x);
	}

	LL *resultsLL = toLLLog(results);


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

	clear();
	printw("Please enter the date that this media was added to your collection. (Format: 03-19-2019)\n");
	refresh();
	char date[10] = "";
	getstr(date);
	changeDate(((MovieLog*)retNode),date);

//	insert(temp,newNode(add));
	exportLogFile(userTree,fName);
}

/*
 * Function:
 * Input:
 * Output:
 *
 * ToDo:
 */
int displayLogMenu(tree *userTree)
{
	clear();
	inOrderScreen(userTree);
	printw("\nChoose which operation to perform next.\n(1)\tAdd a new entry to this log\n(2)\tModify an existing entry in this log\n");
	refresh();
	char sel[10] = "";
	getstr(sel);
	int selectMode = atoi(sel);
	if(selectMode == 1)
	{
		return 2;
	}
	else if(selectMode == 2)
	{
		return 3;
	}
	else
	{
		return 0;
	}



	return 0;
}







