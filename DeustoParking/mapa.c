#include "reserva.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mapa(Reserva arRsv[]){

	char** map = malloc(30 * sizeof(char*));
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
	do{
		j = 0;
		do {
			printf("hola "); fflush(stdout);
			if(map[k][j] == '[' && map[k][j+2] == ']'){
				printf("%c",map[k][j+1]); fflush(stdout);
				numChar = numPlaza+'0';
				printf("%c", numChar); fflush(stdout);
				map[k][j+1] = 'a';
				printf(" hey "); fflush(stdout);
				numPlaza++;
				j++;
			} else{
			j++;
			}
		} while(map[k][j] != '\0');

		k++;
		printf("%i", k);  fflush(stdout);
	} while(k<tamanyoMapa);

}
