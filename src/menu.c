#include "menu.h"




void printStart()
{
	initscr();
	printw("Loading lookup database, please wait.");
	refresh();
}

void retrieveMenuOption(char *menuChoice)
{
	clear();
	printw("MAIN MENU\nPlease select an option below.\n(1) Select an existing log file\n(2) Create a new log file\n(3) Exit application\n");
	refresh();
	getstr(menuChoice);

	while(!(((strcmp("1",menuChoice)) == 0) | ((strcmp("2",menuChoice)) == 0) | ((strcmp("3",menuChoice)) == 0)))
	{
		menuChoice = strdup("");
		clear();
		printw("MAIN MENU\nPlease select a correct option below. *note: Only a single digit(1, 2, or 3) is considered valid input\n(1) Select an existing log file\n(2) Create a new log file\n(3) Exit application\n");
		refresh();
		getstr(menuChoice);
	}
}

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

	searchAdd(searchTerm, lookupTree, fName);


	getch();
}

void printExistingLogMenu(char *menuChoice, tree *lookupTree)
{
	clear();
	printw("EXISTING LOG MENU\n");
	refresh();
	getch();
}

void searchAdd(char *searchTerm, tree *lookupTree, char *fName)
{
	tree *temp = newTree(begMatch,printMovieLog,logTitleLessThan,logTitleGreaterThan,printMovieLogScreen);
	MovieEntry *x = newMovieEntry("", "",searchTerm, "", 0, 0, 0, 0, "");
	tree *results = search(lookupTree, x);
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
	char date[15] = "";
	getstr(date);
	changeDate(add,date);

	insert(temp,newNode(add));

	exportLogFile(temp,fName);

	clear();
	printw("Log file created and entry added successfully! Would you like to continue editing this log? ('y' for yes, 'n' to return to main menu)");
	refresh();
	getch();
}








