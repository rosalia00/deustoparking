#include "mapa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tamanyoString(char cadena[]){
	int i = 0;

	while (cadena[i] != '\0')
	{
		i++;
	}

	return i + 1;
}

void imprimidorArray(char cadena[]){
	int i = 0;
	while (cadena[i] != '\0')
	{
		printf("%c", cadena[i]); fflush(stdout);
		i++;
	}
}

void mapa(Reserva arRsv[]){

	char** map;
	int tamanyoMapa = 10;

	map[0] = '  ===================';
	map[1] = '// [ ][ ][ ][ ][ ][ ] \\';
	map[2] = '||					||';
	map[3] = '|| [ ][ ][ ][ ][ ][ ] ||';
	map[4] = '|| [ ][ ][ ][ ][ ][ ] ||';
	map[5] = '||					||';
	map[6] = '|| [ ][ ][ ][ ][ ][ ] ||';
	map[7] = '|| [ ][ ][ ][ ][ ][ ] ||';
	map[8] = '||					||';
	map[9] = '\\ [ ][ ][ ][ ][ ][ ] //';
	map[10] = '  ===================';

	int tamanyoReserva = sizeof(arRsv) / sizeof *arRsv;
	int plazas[tamanyoReserva];

	int var;
	for (var = 0; var < tamanyoReserva; ++var) {
		plazas[var] = arRsv[var].plaza;
	}

	int numPlaza = 1;
	int tamanyoStr = 0;
	int k;
	int j;
	for (k = 0; k < tamanyoMapa; ++k) {
		tamanyoStr = tamanyoString(map[k]);
		for (j = 0; j < tamanyoString; ++j) {
			if(map[k][j] == '[' && map[k][j+2] == ']'){
				map[k][j+1] == numPlaza+'0';
				numPlaza++;
			}
		}
	}

	int w;
	for (w = 0; w < tamanyoMapa; ++w) {
		imprimidorArray(map[w]);
	}

}
