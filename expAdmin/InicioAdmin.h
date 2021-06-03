#include <iostream>
extern "C" {
#include "../basedatos/Sqlite3.h"
}
#include "../basedatos/Database.h"
#include "../persona/Usuario.h"
#include "Estadisticas.h"
#include "Administrar.h"
using namespace std;

#ifndef EXPADMIN_INICIOADMIN_H_
#define EXPADMIN_INICIOADMIN_H_

void inicioAdmin(Administrador *a, sqlite3 *db);

#endif /* EXPADMIN_INICIOADMIN_H_ */
