#ifndef DB_CREATE_H_
#define DB_CREATE_H_
#include "db.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

MovieEntry * readEntry(char *line);
tree * importFile(char *fname);

#endif
