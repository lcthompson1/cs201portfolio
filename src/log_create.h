#ifndef LOG_CREATE_H_
#define LOG_CREATE_H_
#include <stdlib.h>
#include <string.h>
#include "db.h"
#include "movie_log.h"
#include <stdio.h>


MovieLog * readLogEntry(char *line);
tree * importLogFile(char *fname);
void exportLogFile(tree *Tree, char *fname);

#endif
