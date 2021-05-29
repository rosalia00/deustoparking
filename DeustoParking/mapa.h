#include "reserva.h"
#include "sqlite3.h"

#ifndef MAPA_H_
#define MAPA_H_

bool checkReserva(int plaza, sqlite3 *db);
void printMapa(int piso, sqlite3 *db);
void ventanaMapa(int piso, sqlite3 *db, Usuario *u);

#endif
