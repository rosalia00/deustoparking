#include <stdio.h>
#include <stdlib.h>
#include "registrarse.h"

void registrarse() {

	char *nombre = malloc(20 * sizeof(char));
	char *apellido = malloc(20 * sizeof(char));
	char *dni = malloc(9 * sizeof(char));
	int telefono = 0;
	int numTarj = 0;
	int contrasenya = 0;

	printf("\n---------REGISTRARSE---------\n");
	fflush(stdout);

	printf("Insertar Nombre: ");
	fflush(stdout);
	fgets(nombre, 20, stdin);
	printf("%s", nombre);

	printf("Insertar Apellido: ");
	fflush(stdout);
	fgets(apellido, 20, stdin);
	printf("%s", apellido);

	printf("Insertar DNI: ");
	fflush(stdout);
	fgets(dni, 10, stdin);
	printf("%s", dni);

	printf("Insertar N� Telefono: ");
	fflush(stdout);
	scanf("%i", &telefono);

	printf("Insertar N� Tarjeta: ");
	fflush(stdout);
	scanf("%i", &numTarj);

	printf("Insertar Contrase�a Numerica: ");
	fflush(stdout);
	scanf("%i", &contrasenya);
}
