#include "../persona/Usuario.h"
#include "../persona/Administrador.h"
#include "../reserva/Reserva.h"
#include "Sqlite3.h"

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

//Estadisticas
void bonosNum(sqlite3 *db, int idBonos);
void horasEntrada(sqlite3 *db, int hora1, int hora2);
void tipoUsuario(sqlite3 *db, char* tipo);
void reservasPisos(sqlite3 *db);


#endif /* BASEDATOS_DATABASE_H_ */

