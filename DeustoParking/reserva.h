#include "registrarse.h"
#include "sqlite3.h"

#ifndef RESERVA_H_
#define RESERVA_H_

typedef struct {
	char *nombre;
	char *apellido;
	char *dni;
	int tarjeta;
	char *datainicio;
	char *datafin;
	float precio;
	char *matricula;
	int plaza;

} Reserva;

Reserva reservacion(Usuario u, sqlite3 *db);
void ticket(Reserva *res, sqlite3 *db);
void imprimidorArray(char cadena[]);

#endif
