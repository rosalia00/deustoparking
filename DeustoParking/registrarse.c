#include "registrarse.h"
#include <stdio.h>

void registrarse (void){

	char *nombre = malloc(20 * sizeof(char));
	char *apellido = malloc(20 * sizeof(char));;
	char *dni = malloc(9 * sizeof(char));;
	int telefono = 0;
	int numTarj = 0;
	int contrasenya = 0;

	printf("\n---------REGISTRARSE---------\n");fflush(stdout);

	printf("Insertar Nombre: ");fflush(stdout);
	scanf("%c%*c", nombre);

	printf("\nInsertar Apellido: ");fflush(stdout);
	scanf("%c%*c", apellido);

	printf("\nInsertar DNI: ");fflush(stdout);
	scanf("%c%*c", dni);


	printf("\nInsertar Nº Telefono: ");fflush(stdout);
	scanf("%i%", telefono);


	printf("\nInsertar Nº Tarjeta: ");fflush(stdout);
	scanf("%i%", numTarj);


	printf("\nInsertar Contraseña Numerica: ");fflush(stdout);
	scanf("%i%", contrasenya);

}
