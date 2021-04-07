#include "reserva.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void mapa(Reserva arRsv[]) {

	char **map = malloc(30 * sizeof(char*));
	int tamanyoMapa = 11;

	map[0] = "  ===================";
	map[1] = "// [b][ ][ ][ ][ ][ ] \\";
	map[2] = "||                    ||";
	map[3] = "|| [ ][ ][ ][ ][ ][ ] ||";
	map[4] = "|| [ ][ ][ ][ ][ ][ ] ||";
	map[5] = "||                    ||";
	map[6] = "|| [ ][ ][ ][ ][ ][ ] ||";
	map[7] = "|| [ ][ ][ ][ ][ ][ ] ||";
	map[8] = "||                    ||";
	map[9] = "\\ [ ][ ][ ][ ][ ][ ] //";
	map[10] = "  ===================";

	int tamanyoReserva = sizeof(arRsv) / sizeof *arRsv;
	int plazas[tamanyoReserva];

	int var;
	for (var = 0; var < tamanyoReserva; ++var) {
		plazas[var] = arRsv[var].plaza;
	}
	int numPlaza = 1;

	int k = 0;
	int j;
	char numChar;
	do {
		j = 0;
		do {
			if (map[k][j] == '[' && map[k][j + 2] == ']') {
				//printf("%c", map[k][j + 1]);
				fflush(stdout);
				numChar = numPlaza + '0';
				//itoa(numPlaza, numChar, 10);
				//printf("%c", numChar);
				fflush(stdout);
				printf("\n\n", cambiador(map[k], numChar));
				//printf("%c", map[k][j + 1]);
				//map[k][j + 1] = numChar; //esto no funciona
				//printf(" hey ");
				fflush(stdout);
				numPlaza++;
				j++;
			} else {
				j++;
			}
		} while (map[k][j] != '\0');

		k++;
	} while (k < tamanyoMapa);

}
