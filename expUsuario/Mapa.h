#ifndef EXPUSUARIO_MAPA_H_
#define EXPUSUARIO_MAPA_H_

#include "../basedatos/Sqlite3.h"
#include "../persona/Usuario.h"

bool checkReserva(int plaza, sqlite3 *db);
void printMapa(int piso, sqlite3 *db);
void ventanaMapa(int piso, sqlite3 *db, Usuario *u);

#endif /* EXPUSUARIO_MAPA_H_ */
