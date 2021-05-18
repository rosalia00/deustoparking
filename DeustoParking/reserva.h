#include "registrarse.h"

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

Reserva reservacion(Usuario u);
void ticket(Reserva *res);
void imprimidorArray(char cadena[]);

#endif
