/*
 * reserva.h
 *
 *  Created on: 1 jun. 2021
 *      Author: Tyler de Mier
 */

#ifndef RESERVA_RESERVA_H_
#define RESERVA_RESERVA_H_

#include "../basedatos/Sqlite3.h"
#include "../persona/Usuario.h"

typedef struct {
	char *nombre;
	char *apellido;
	const char *dni;
	int tarjeta;
	char *datainicio;
	char *datafin;
	float precio;
	char *matricula;
	int plaza;
} Reserva;

float tipoBono();
void ticket(Reserva *res, sqlite3 *db);
Reserva reservacion(Usuario *u, sqlite3 *db);

#endif /* RESERVA_RESERVA_H_ */
