#ifndef DB_CREATE_H_
#define DB_CREATE_H_
#include "db.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* db_create.h
 *
 * Header file containing declarations for db_create.c
 *
 * Author: Logan Thompson
 * Date: 03/29/2019
 *
 *
 * ToDo: Nothing
 */

//Function declarations for db_create.c
MovieEntry * readEntry(char *line);
tree * importFile(char *fname);

#endif
