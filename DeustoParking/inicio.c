#include <stdio.h>
#include "registrarse.h"
#include "login.h"
#include <stdlib.h>

void cleanStdIn(char *str, int max_line) {
	if ((strlen(str) == max_line - 1) && (str[max_line - 2] != '\n'))
		while (getchar() != '\n')
			;
}

void inicio() {
    printf(" == BIENVENIDO A DEUSTOPARKING == \n");
    printf("\n");
    printf("r -> Registrarse.\n");
    printf("i -> Iniciar sesion.\n");
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

		if (letra == 'i') {
			loggearse(); //llamamos al método
		} else if (letra == 'r') {
			registrarse();
		} else {
			printf("LETRA INVALIDA INSERTE UNO NUEVO: ");
			fflush(stdout);

			char linea[5];
			cleanStdIn(linea, 5);
			fgets(linea, 5, stdin);
			sscanf(linea, "%c", &letra);
			letra = tolower(letra);
		}
	} while (0);

}
