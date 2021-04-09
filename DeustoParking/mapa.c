#include "reserva.h"
#include "inicioUsuario.h"
#include "inicio.h"
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

void imprimirMapa(char **mapa, int tamanyoMapa){
	int x;
	for (x = 0; x < tamanyoMapa; ++x) {
		printf("%s", mapa[x]);
	}
}

void inicioMapa (char letra, int piso){
	if(letra =='a' && piso!= 3){
		piso++;
		printf("\nESTA USTED EN EL PISO %i, SELECCIONE UNA LETRA: ", piso); fflush(stdout);
		char letra;
		char linea[5];
		cleanStdIn(linea, 5);
		fgets(linea, 5, stdin);
		sscanf(linea, "%c", &letra);
		letra = tolower(letra);
	} else if (letra == 'b' && piso != 1){
		piso--;
		printf("\nESTA USTED EN EL PISO %i, SELECCIONE UNA LETRA: ", piso); fflush(stdout);
		char letra;
		char linea[5];
		cleanStdIn(linea, 5);
		fgets(linea, 5, stdin);
		sscanf(linea, "%c", &letra);
		letra = tolower(letra);
		printf("\nESTA USTED EN EL PISO %i, SELECCIONE UNA LETRA: ", piso); fflush(stdout);
	} else if (letra =='a' && piso== 3){
		printf("Esta usted en la ultima planta, seleccione otra letra por favor");
		printf("\nESTA USTED EN EL PISO %i, SELECCIONE UNA LETRA: ", piso); fflush(stdout);
		char letra;
		char linea[5];
		cleanStdIn(linea, 5);
		fgets(linea, 5, stdin);
		sscanf(linea, "%c", &letra);
		letra = tolower(letra);

	}  else if (letra =='b' && piso== 1){
		printf("Esta usted en la primera planta, seleccione otra letra por favor");
		printf("\nESTA USTED EN EL PISO %i, SELECCIONE UNA LETRA: ", piso); fflush(stdout);
		char letra;
		char linea[5];
		cleanStdIn(linea, 5);
		fgets(linea, 5, stdin);
		sscanf(linea, "%c", &letra);
		letra = tolower(letra);
	} else if (letra == 'v'){
		inicioUsuario();
	} else {
		printf("LETRA INVALIDA INSERTE UNA NUEVA");
		fflush(stdout);
		char linea[5];
		cleanStdIn(linea, 5);
		fgets(linea, 5, stdin);
		sscanf(linea, "%c", &letra);
		letra = tolower(letra);
		printf("\nESTA USTED EN EL PISO %i, SELECCIONE UNA LETRA: ", piso); fflush(stdout);
	}
}

void mapa(Reserva arRsv[]) {

	char **map = malloc(30 * sizeof(char*));
	int tamanyoMapa = 11;

	int piso = 1;

	map[0] = "  ===================\n";
	map[1] = "// [b][ ][ ][ ][ ][ ] \\\\ \n";
	map[2] = "||                    ||\n";
	map[3] = "|| [ ][ ][ ][ ][ ][ ] ||\n";
	map[4] = "|| [ ][ ][ ][ ][ ][ ] ||\n";
	map[5] = "||                    ||\n";
	map[6] = "|| [ ][ ][ ][ ][ ][ ] ||\n";
	map[7] = "|| [ ][ ][ ][ ][ ][ ] ||\n";
	map[8] = "||                    ||\n";
	map[9] = "\\\\ [ ][ ][ ][ ][ ][ ] //\n";
	map[10] = "  ===================\n";

	imprimirMapa(map, tamanyoMapa);

	printf("a -> Subir\n");
	printf("b -> Bajar\n");
	printf("v -> Volver\n"); fflush(stdout);
	printf("\nESTA USTED EN EL PISO %i, SELECCIONE UNA LETRA: ", piso); fflush(stdout);


	do {
		char letra;
		char linea[5];
		cleanStdIn(linea, 5);
		fgets(linea, 5, stdin);
		sscanf(linea, "%c", &letra);
		letra = tolower(letra);



	}while(0);
/*
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
	char *cambiar;
	do {
		j = 0;
		do {
			if (map[k][j] == '[' && map[k][j + 2] == ']') {
				//printf("%c", map[k][j + 1]); fflush(stdout);

				numChar = numPlaza + '0';
				//itoa(numPlaza, numChar, 10);
				//printf("%c", numChar); fflush(stdout);
				//printf("\n\n", cambiador(map[k], numChar));
				//printf("%c", map[k][j + 1]);
				//map[k][j + 1] = numChar; //esto no funciona
				//printf(" hey "); fflush(stdout);
				cambiar = map[k];
				printf("%s", cambiar); fflush(stdout);
				cambiar[j+1] = 'a';
				printf("hey"); fflush(stdout);
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
