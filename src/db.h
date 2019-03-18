#ifndef DB_H_
#define DB_H_

//Structure to represent Movies/TV Shows with all retrieved data
struct MovieEntry
{
	char tconst[9];
	char titleType[10];
	char primaryTitle[50];
	char originalTitle[50];
	int isAdult;
	int startYear;
	int endYear;
	int runtimeMinutes;
	char genres[5][10];
};



//RB Tree structure containing pointers for root and nil
struct tree
{
	struct node *root;
	struct node *nil;
};


//Node structure for red black tree.
//Red = 0
//Black = 1
struct node
{
	struct MovieEntry *key;
	struct node *left, *right, *p;
	int color;
};


void left_rotate(struct tree Tree, struct node *x);
void right_rotate(struct tree Tree, struct node *x);
void insert(struct tree Tree, struct node *z);
void insert_fixup(struct tree Tree, struct node *z);
void rb_transplant(struct tree Tree, struct node *u, struct node *v);
struct node * tree_minimum(struct node *x);
void rb_delete_fixup(struct tree Tree, struct node *x);


#endif
