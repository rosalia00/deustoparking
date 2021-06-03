#include "Sqlite3.h"
#include <iostream>
#include "Sqlite3.h"
#include "../persona/Usuario.h"
#include "../persona/Administrador.h"
#include "../reserva/Reserva.h"
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

#ifndef BASEDATOS_DATABASE_H_
#define BASEDATOS_DATABASE_H_

int cuentaReservas(sqlite3 *db);
int administrarBono(sqlite3 *db, float precio, int opcion);
void recogeReservas(int *listaNum, sqlite3 *db, int tamanyo);
int guardarTicket(sqlite3 *db, Reserva *res);
float recogerPrecioBono(sqlite3 *db, int num);
int baseDatosUsuarioRegistrar(sqlite3 *db, Usuario *u);
int inicioSesion(sqlite3 *db, char *dni, Usuario *usuario);
int inicioSesionAdmin(sqlite3 *db, char *dni, Administrador *admin);
void printReservas(sqlite3 *db, Usuario *u);

#endif /* BASEDATOS_DATABASE_H_ */
