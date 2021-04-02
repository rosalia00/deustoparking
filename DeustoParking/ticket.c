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
struct reserva{
	char nombre[30];
	char apellido[40];
	char dni[9];
	int tarjeta;
	char datainicio[10];
	char datafin[10];
	float precio;
	char matricula[12];
	int plaza;
};

struct reserva reserva_t;


/*
 * Guarda en fichero
 */
main(){

void ticket(struct reserva *r){
	FILE *freserva;
	freserva = fopen("ticket.dat", "a");
	if (freserva == NULL){
		printf("No se puede abrir el fichero");
	}
	else {

	}
}

}
