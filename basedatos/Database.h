/*
 * Database.h
 *
 *  Created on: 1 jun. 2021
 *      Author: Tyler de Mier
 */

#ifndef BASEDATOS_DATABASE_H_
#define BASEDATOS_DATABASE_H_

#include "Sqlite3.h"
#include "../reserva/Reserva.h"
#include "../persona/Usuario.h"

int cuentaReservas(sqlite3 *db);
int administrarBono(sqlite3 *db, float precio, int opcion);
void recogeReservas(int *listaNum, sqlite3 *db, int tamanyo);
int guardarTicket(sqlite3 *db, Reserva *res);
float recogerPrecioBono(sqlite3 *db, int num);
int baseDatosUsuarioRegistrar(sqlite3 *db, Usuario *u);
int inicioSesion(sqlite3 *db, char *dni, Usuario *usuario);

#endif /* BASEDATOS_DATABASE_H_ */
