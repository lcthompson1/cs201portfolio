#ifndef LOG_CREATE_H_
#define LOG_CREATE_H_
#include <stdlib.h>
#include <string.h>
#include "db.h"
#include "movie_log.h"
#include <stdio.h>

/* log_create.h
 *
 * Header file containing function declarations for log_create.c
 *
 * Author: Logan Thompson
 * Date: 03/29/2019
 *
 *
 * ToDo: Nothing
 */

//function declarations for log_create.c
MovieLog * readLogEntry(char *line);
tree * importLogFile(char *fname);
void exportLogFile(tree *Tree, char *fname);

#endif
