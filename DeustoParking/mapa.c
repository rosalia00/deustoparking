#include "reserva.h"
#include "inicioUsuario.h"
#include "inicio.h"
#include "registrarse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqlite3.h"

char cambiador(char cosos[], char cosoacambiar) {

	char resultado;
	int i = 0;

	printf("COSOS[ %i ]: %c\n", i, cosos[i]);
	printf("COSOACAMBIAR: %c\n", cosoacambiar);

	for (i = 0; cosos[i] != '\0'; ++i) {
		resultado = cosoacambiar;
	}

	printf("RESULTADO: %c\n", resultado);

	return resultado;

}

void imprimirMapa(char **mapa, int tamanyoMapa) {
	int x;
	for (x = 0; x < tamanyoMapa; ++x) {
		printf("%s", mapa[x]);
	}
}

void crearMapa(int piso) {
	int primeraPlaza;
	if (piso == 1) {
		primeraPlaza = 1;
	} else if (piso == 2) {
		primeraPlaza = 37;
	} else if (piso == 3) {
		primeraPlaza = 73;
	}
	int arNum[36];
	int w;
	for (w = 0; w < 36; ++w) {
		arNum[w] = primeraPlaza;
		primeraPlaza++;
	}

	printf("  ==============================\n");
	printf("//   [%i][%i][%i][%i][%i][%i]   \\\\ \n", arNum[0], arNum[1],
			arNum[2], arNum[3], arNum[4], arNum[5]);
	printf("||                              ||\n");
	printf("||   [%i][%i][%i][%i][%i][%i]   ||\n", arNum[6], arNum[7], arNum[8],
			arNum[9], arNum[10], arNum[11]);
	printf("||   [%i][%i][%i][%i][%i][%i]   ||\n", arNum[12], arNum[13],
			arNum[14], arNum[15], arNum[16], arNum[17]);
	printf("||                              ||\n");
	printf("||   [%i][%i][%i][%i][%i][%i]   ||\n", arNum[18], arNum[19],
			arNum[20], arNum[21], arNum[22], arNum[23]);
	printf("||   [%i][%i][%i][%i][%i][%i]   ||\n", arNum[24], arNum[25],
			arNum[26], arNum[27], arNum[28], arNum[29]);
	printf("||                              ||\n");
	printf("\\\\   [%i][%i][%i][%i][%i][%i]   //\n", arNum[30], arNum[31],
			arNum[32], arNum[33], arNum[34], arNum[35]);
	printf("  ==============================\n");
	fflush(stdout);
}

void inicioMapa(int piso, char **map, int tamanyoMapa, Usuario u, sqlite3 *db) {
	int opcion = 0;
	printf("\nESTA USTED EN EL PISO %i, SELECCIONE UNA OPCIÓN: ", piso);
	fflush(stdout);

	do {
		scanf("%i", &opcion);
		switch (opcion) {
		case 1:
			if (piso != 3) {
				piso++;
				crearMapa(piso);
				printf("1. Subir\n");
				printf("2. Bajar\n");
				printf("3. Volver\n");
				fflush(stdout);
			} else {
				printf(
						"Esta usted en la ultima planta, seleccione otra letra por favor: ");
				fflush(stdout);
				scanf("%i", &opcion);
			}
			break;
		case 2:
			if (piso != 1) {
				piso--;
				crearMapa(piso);
				printf("1. Subir\n");
				printf("2. Bajar\n");
				printf("3. Volver\n");
				fflush(stdout);

			} else {
				printf(
						"Esta usted en la ultima planta, seleccione otra letra por favor: ");
				fflush(stdout);
				scanf("%i", &opcion);
			}

			break;
		case 3:
			inicioUsuario(u, db);

			break;
		default:
			printf("CARACTER INVALIDO, SELECCIONE OTRA OPCION.");
			fflush(stdout);
			scanf("%i", &opcion);

			break;
		}
		inicioMapa(piso, map, tamanyoMapa, u, db);

	} while (0);

}

void mapa(Reserva arRsv[], Usuario u, sqlite3 *db) {

	char **map = malloc(30 * sizeof(char*));
	int tamanyoMapa = 11;
	int h;
	for (h = 0; h < tamanyoMapa; h++) {
		map[h] = (char*) malloc(50 * sizeof(char));
	}

	map[0] = "  ===================\n";
	map[1] = "// [ ][ ][ ][ ][ ][ ] \\\\ \n";
	map[2] = "||                    ||\n";
	map[3] = "|| [ ][ ][ ][ ][ ][ ] ||\n";
	map[4] = "|| [ ][ ][ ][ ][ ][ ] ||\n";
	map[5] = "||                    ||\n";
	map[6] = "|| [ ][ ][ ][ ][ ][ ] ||\n";
	map[7] = "|| [ ][ ][ ][ ][ ][ ] ||\n";
	map[8] = "||                    ||\n";
	map[9] = "\\\\ [ ][ ][ ][ ][ ][ ] //\n";
	map[10] = "  ===================\n";

	int piso = 1;
	crearMapa(piso);
	printf("1. Subir\n");
	printf("2. Bajar\n");
	printf("3. Volver\n");
	fflush(stdout);

	inicioMapa(piso, map, tamanyoMapa, u, db);

	int tamanyoReserva = sizeof(arRsv) / sizeof *arRsv;
	int plazas[tamanyoReserva];

	int var;
	for (var = 0; var < tamanyoReserva; ++var) {
		plazas[var] = arRsv[var].plaza;
	}

	/*
	 int k = 0;
	 int j;
	 char numChar;
	 do {
	 j = 0;
	 do {
	 if (map[k][j] == '[' && map[k][j + 2] == ']') {
	 //itoa(numPlaza, numChar, 10);
	 //printf("%c", numChar); fflush(stdout);
	 //printf("\n\n", cambiador(map[k], numChar));
	 printf("%c", map[k][j + 1]);  fflush(stdout);
	 map[k][j + 1] = numChar; //esto no funciona
	 printf(" hey "); fflush(stdout);
	 numPlaza++;
	 j++;
	 } else {
	 j++;
	 }
	 } while (map[k][j] != '\0');

	 k++;
	 } while (k < tamanyoMapa);

	 */
}
