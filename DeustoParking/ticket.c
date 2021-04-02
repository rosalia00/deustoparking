/*
 * ticket.c
 *
 *  Created on: 2 abr. 2021
 *      Author: rosal
 */
#include <stdio.h>
/*
 * Creamos una estructura que recibira los datos
 * para meter los datos esta clase tendrá que ser llamada en las que esten los dato s
 */
typedef struct{
	char nombre[30];
	char apellido[40];
	char dni[9];
	int tarjeta;
	char datainicio[10];
	char datafin[10];
	float precio;
	char matricula[12];
	int plaza;
}reserva;

reserva reserva_t;


/*
 * Guarda en fichero
 */

void ticket(reserva *res){
	FILE *freserva;
	freserva = fopen("ticket.dat", "a");
	if (freserva != NULL){
		fwrite(&res, sizeof(reserva), 1, freserva);
		close(freserva);
		//si no functiona co sizeof(reserva) probar sizeof(res)
	}
	//res = &res_t;
	printf("******DATOS DE LA RESERVA****** \n");
	printf("Nombre: %s \n", res->nombre);
	printf("Apellido: %s \n", res->apellido);
	printf("DNI: %i \n", res->dni);
	printf("Tarjeta: %i \n", res->tarjeta);
	printf("Fecha de Inicio: %s \n", res->datainicio);
	printf("Fecha de Fin: %s \n", res->datafin);
	printf("Precio: %.2f \n", res->precio);
	printf("Matricula: %s \n", res->matricula);
	printf("Plaza: %i \n", res->plaza);
}
