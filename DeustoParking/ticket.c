#include <stdio.h>
#include "reserva.h"

void ticket(Reserva *res) {
	FILE *freserva;
	freserva = fopen("ticket.dat", "a");
	if (freserva != NULL) {
		fprintf(freserva, "Nombre: %s; ", res->nombre);
		fprintf(freserva, "Apellido: %s; ", res->apellido);
		fprintf(freserva, "DNI: %s; ", res->dni);
		fprintf(freserva, "Tarjeta: %i; ", res->tarjeta);
		fprintf(freserva, "Fecha de Inicio: %s; ", res->datainicio);
		fprintf(freserva, "Fecha de Fin: %s; ", res->datafin);
		fprintf(freserva, "Precio: %.2f; ", res->precio);
		fprintf(freserva, "Matricula: %s; ", res->matricula);
		fprintf(freserva, "Plaza: %i; ", res->plaza);

		fclose(freserva);
	}
	printf("\n======DATOS DE LA RESERVA======\n");
	printf("Nombre: %s\n", res->nombre);
	printf("Apellido: %s\n", res->apellido);
	printf("DNI: %s\n", res->dni);
	printf("Tarjeta: %i\n", res->tarjeta);
	printf("Fecha de Inicio: %s\n", res->datainicio);
	printf("Fecha de Fin: %s\n", res->datafin);
	printf("Precio: %.2f\n", res->precio);
	printf("Matricula: %s\n", res->matricula);
	printf("Plaza: %i\n", res->plaza);
	fflush(stdout);
}
