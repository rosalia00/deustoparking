#include <stdio.h>
#include "reserva.h"

/*
 * Guarda en fichero
 */

void ticket(Reserva *res){
	FILE *freserva;
	freserva = fopen("ticket.dat", "a");
	if (freserva != NULL){
		fwrite(&res, sizeof(Reserva), 1, freserva);
		close(freserva);
		//si no functiona co sizeof(reserva) probar sizeof(res)
	}
	//res = &res_t;
	printf("******DATOS DE LA RESERVA****** \n");
	printf("Nombre: %s \n", res->nombre);
	printf("Apellido: %s \n", res->apellido);
	printf("DNI: %s \n", res->dni);
	printf("Tarjeta: %i \n", res->tarjeta);
	printf("Fecha de Inicio: %s \n", res->datainicio);
	printf("Fecha de Fin: %s \n", res->datafin);
	printf("Precio: %.2f \n", res->precio);
	printf("Matricula: %s \n", res->matricula);
	printf("Plaza: %i \n", res->plaza);
}
