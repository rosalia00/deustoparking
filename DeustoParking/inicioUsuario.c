#include <stdio.h>
#include <stdlib.h>
#include "inicio.h"
#include "mapa.h"
#include "tipoBono.h"

void inicioUsuario() {
    printf(" == BIENVENIDO == \n");
    printf("\n");
    printf("p -> Reservar plazas.\n");
    printf("m -> Mapa.\n");
    printf("r -> Reservas.\n");
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

		if (letra == 'p') {
			tipoBono(); //llamamos al m�todo
		} else if (letra == 'm') {
		//	mapa();
		} else if (letra == 'r') {
					//dejamos vacío pq falta bbdd :(
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
