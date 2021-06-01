/*
 * inicio.cpp
 *
 *  Created on: 1 jun. 2021
 *      Author: Tyler de Mier
 */
extern "C" {
#include "basedatos/Sqlite3.h"
}
#include "persona/Usuario.h"
#include "expUsuario/InicioUsuario.h"
#include "expUsuario/Login.h"
#include "expUsuario/Registrar.h"
#include <windows.h>
#include <stdio.h>
#include <ctype.h>

void inicio(sqlite3 *db) {
	bool valido = true;
	system("cls");
	fflush (stdout);
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
			loggearse(db);
			valido = false;
			break;
		case 'r':
			registrarse(db);
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

