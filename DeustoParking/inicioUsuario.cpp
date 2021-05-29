extern "C" {
#include "sqlite3.h"
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "inicio.h"
#include "reserva.h"
#include "usuario.h"
#include "mapa.h"
#include <iostream>
using namespace std;

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
			fflush(stdin);
			reservacion(u, db);
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

