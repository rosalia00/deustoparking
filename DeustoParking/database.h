#include "sqlite3.h"
#include "reserva.h"
#include "usuario.h"

#ifndef DATABASE_H_
#define DATABASE_H_

int cuentaReservas(sqlite3 *db);
int administrarBono(sqlite3 *db, float precio, int opcion);
void recogeReservas(Reserva*, sqlite3 *db, int tamanyo);
int guardarTicket(sqlite3 *db, Reserva *res);
int baseDatosUsuarioRegistrar(sqlite3 *db, Usuario *u);

#endif /* DATABASE_H_ */
