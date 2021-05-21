#include "reserva.h"
#include "sqlite3.h"

#ifndef MAPA_H_
#define MAPA_H_

void mapa(Reserva arRsv[], Usuario u, sqlite3 *db);
char cambiador(char cosos[], char cosoacambiar);
void imprimirMapa(char **mapa, int tamanyoMapa);
void inicioMapa(int piso, char **map, int tamanyoMapa, Usuario u, sqlite3 *db);

#endif
