#include <iostream>
extern "C" {
#include "basedatos/Sqlite3.h"
}

using namespace std;

#ifndef INICIO_H_
#define INICIO_H_

#include "basedatos/Sqlite3.h"

void inicio(sqlite3 *db, char *tipo);
void admin(sqlite3 *db, char *tipo);

#endif /* INICIO_H_ */
