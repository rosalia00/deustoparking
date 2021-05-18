#include <stdio.h>
#include "registrarse.h"
#include "login.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

void cleanStdIn(char *str, int max_line) {
	if ((strlen(str) == max_line - 1) && (str[max_line - 2] != '\n'))
		while (getchar() != '\n')
			;
}

void inicio() {
	bool valido = true;
	system("cls");
	fflush(stdout);
	printf("\n == BIENVENIDO A DEUSTOPARKING == \n");
	printf("\n");
	printf("r -> Registrarse.\n");
	printf("i -> Iniciar sesion.\n");
	printf("s -> Salir del programa. \n");
	printf("\n");
	printf("INTRODUZCA LA LETRA: ");
	fflush(stdout);

	do {

		char letra;
		char linea[5];
		cleanStdIn(linea, 5);
		fgets(linea, 5, stdin);
		sscanf(linea, "%c", &letra);
		letra = tolower(letra);
		switch (letra) {
		case 'i':
			loggearse();
			valido = false;
			break;
		case 'r':
			registrarse();
			valido = false;
			break;
		case 's':
			printf("\nSaliendo del programa en 3 segundos...");
			fflush(stdout);
			Sleep(3000);
			exit(1);
		default:
			printf("\nLETRA INVALIDA INSERTE UNO NUEVO: ");
			fflush(stdout);
			sscanf(linea, "%c", &letra);
			letra = tolower(letra);
			valido = true;
			break;
		}
	} while (valido);
	system("cls");
}
