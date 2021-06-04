extern "C" {
#include "../basedatos/Sqlite3.h"
}
#include "../persona/Administrador.h"

#ifndef EXPADMIN_INICIOADMIN_H_
#define EXPADMIN_INICIOADMIN_H_

void inicioAdmin(Administrador *a, sqlite3 *db);

#endif /* EXPADMIN_INICIOADMIN_H_ */
