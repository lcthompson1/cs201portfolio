#include "menu.h"
#include "db_create.h"
#include "movie_log.h"
#include "log_create.h"
#include <stdlib.h>
#include <ncurses.h>







int main()
{

/*
	clear();
	char completeMsg1[] = "Completed! Please select an option from below.\n";
	char completeMsg2[] = "(1) Create a new record\n(2) Update an existing record.\n";
	char completeMsg3[] = "(2) Update an existing record.\n";

	mvprintw(row/2,(col-strlen(completeMsg1))/2,"%s",completeMsg1);
	mvprintw(row/2+1,(col-strlen(completeMsg2))/2,"%s",completeMsg2);
	mvprintw(row/2+2,(col-strlen(completeMsg3))/2,"%s",completeMsg3);
	refresh();



	getch();
	endwin();
*/

//	inOrder(lookupTree,stdout);


/*
		char fName[50];
		char searchTitle[50] = "Avengers";
		printf("Enter log file name.");
		tree *test = newTree(begMatch,printMovieLog,logTitleLessThan,logTitleGreaterThan);
		fgets(fName,50,stdin);
		printf("Title Search?\n");
		fgets(searchTitle,50,stdin);
		searchTitle[strlen(searchTitle)-1] = 0;
		MovieEntry *x = newMovieEntry("", "",searchTitle, "", 0, 0, 0, 0, "");
		tree *results = search(lookupTree, x);
		inOrder(results,stdout);
		insert(test,newNode(newMovieLog(results->root->key)));

		printf("Title Search?\n");
		fgets(searchTitle,50,stdin);
		searchTitle[strlen(searchTitle)-1] = 0;
		x = newMovieEntry("", "",searchTitle, "", 0, 0, 0, 0, "");
		results = search(lookupTree, x);
		inOrder(results,stdout);
		insert(test,newNode(newMovieLog(results->root->key)));

		printf("Title Search?\n");
		fgets(searchTitle,50,stdin);
		searchTitle[strlen(searchTitle)-1] = 0;
		x = newMovieEntry("", "",searchTitle, "", 0, 0, 0, 0, "");
		results = search(lookupTree, x);
		inOrder(results,stdout);
		insert(test,newNode(newMovieLog(results->root->key)));

		printf("Title Search?\n");
		fgets(searchTitle,50,stdin);
		searchTitle[strlen(searchTitle)-1] = 0;
		x = newMovieEntry("", "",searchTitle, "", 0, 0, 0, 0, "");
		results = search(lookupTree, x);
		inOrder(results,stdout);
		insert(test,newNode(newMovieLog(results->root->key)));

		inOrder(test,stdout);


		exportLogFile(test,fName);
*/
/*

	tree *z = importLogFile("test.log");
	inOrder(z,stdout);
*/

//	int cont = 1;

	printStart();
	tree *lookupTree = importFile("movie_records");
	clear();
	printw("Completed! ");
	refresh();
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

/*
	char *fName = "test.log";
	tree *test = newTree(begMatch,printMovieLog,logTitleLessThan,logTitleGreaterThan);
	MovieEntry *x = newMovieEntry("", "","Avengers", "", 0, 0, 0, 0, "");
	tree *results = search(lookupTree, x);
	inOrder(test,stdout);
	insert(test,newNode(newMovieLog(results->root->key)));

	x = newMovieEntry("", "","Final", "", 0, 0, 0, 0, "");
	results = search(lookupTree, x);
	inOrder(test,stdout);
	insert(test,newNode(newMovieLog(results->root->key)));

	x = newMovieEntry("", "","Nightmare", "", 0, 0, 0, 0, "");
	results = search(lookupTree, x);
	inOrder(test,stdout);
	insert(test,newNode(newMovieLog(results->root->key)));

	x = newMovieEntry("", "","John", "", 0, 0, 0, 0, "");
	results = search(lookupTree, x);
	inOrder(test,stdout);
	insert(test,newNode(newMovieLog(results->root->key)));

	inOrder(test,stdout);


	exportLogFile(test,fName);


*/






	return 1;
}













/*
 * inOrder(lookupTree);
	MovieEntry *x = newMovieEntry("", "", "Avengers:", "Avengers", 0, 0, 0, 0, "");
	MovieEntry *y = newMovieEntry("", "", "Avengersasdfghjkiuytfd", "Avengers", 0, 0, 0, 0, "");

	node *xn = newNode(x);
	node *yn = newNode(y);

	int found = lookupTree->begMatch(xn->key,yn->key);

	printf("found = %d\n",found);

	node *Found = searchAux(lookupTree,lookupTree->root,x);

	printMovieEntry(Found->key);


	tree *results = search(lookupTree, x);
	inOrder(results);
	inOrder(lookupTree);

*/
