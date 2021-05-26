#ifndef INICIO_H_
#define INICIO_H_

#include "sqlite3.h"

void cleanStdIn(char *str, int max_line);
void inicio(sqlite3 *db);

#endif /* INICIO_H_ */
