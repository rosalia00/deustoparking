#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "registrarse.h"

char* quitadorContrabarraN(char *s) {
	char *n = malloc(strlen(s ? s : "\n"));
	if (s) {
		strcpy(n, s);
	}
	n[strlen(n) - 1] = '\0';
	return n;
}

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
	nombre = quitadorContrabarraN(nombre);

	printf("Insertar Apellido: ");
	fflush(stdout);
	fgets(apellido, 20, stdin);
	apellido = quitadorContrabarraN(apellido);

	printf("Insertar DNI: ");
	fflush(stdout);
	fgets(dni, 10, stdin);

	printf("Insertar Nº Telefono: ");
	fflush(stdout);
	scanf("%i", &telefono);

	printf("Insertar Nº Tarjeta: ");
	fflush(stdout);
	scanf("%i", &numTarj);

	printf("Insertar Contraseña Numerica: ");
	fflush(stdout);
	scanf("%i", &contrasenya);
}
