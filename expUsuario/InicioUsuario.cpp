/*
 * InicioUsuario.cpp
 *
 *  Created on: 1 jun. 2021
 *      Author: Tyler de Mier
 */
extern "C" {
#include "../basedatos/Sqlite3.h"
}
#include "../persona/Usuario.h"
#include <string.h>
#include "InicioUsuario.h"
#include "Mapa.h"
#include "iostream"
using namespace std;

void cleanStdIn(char *str, int max_line) {
	if ((strlen(str) == max_line - 1) && (str[max_line - 2] != '\n'))
		while (getchar() != '\n')
			;
}

void inicioUsuario(Usuario *u, sqlite3 *db) {
	cout << endl << "--- BIENVENIDO " << u->getNombre() << "---" << endl;
	printf("\n");
	printf("p -> Reservar plazas.\n");
	printf("m -> Mapa.\n");
	printf("r -> Reservas. (Aún no disponible)\n");
	printf("\n");
	printf("INTRODUZCA LA LETRA: ");
	fflush(stdout);

	do {
		char letra;
		char linea[5];
		cleanStdIn(linea, 5);
		fgets(linea, 5, stdin);
		letra = getchar();
		letra = tolower(letra);

		if (letra == 'p') {
//			fflush(stdin);
//			reservacion(u, db);
		} else if (letra == 'm') {
			fflush(stdin);
			ventanaMapa(1, db, u);
		} else if (letra == 'r') {
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

