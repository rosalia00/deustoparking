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
#include "iostream"
using namespace std;

void inicio(sqlite3 *db) {

	int opcion;

	cout << "--- BIENVENIDO A DEUSTO PARKING ---" << endl;
	cout << "1. Registrarse." << endl << "2. Iniciar sesion." << endl
			<< "3. Administrador." << endl << "4. Salir del programa." << endl;

	do {
		cout << "Elija la opción: ";
		cin >> opcion;
	} while (opcion < 1 || opcion > 3);

	switch (opcion) {
	case 1:
		registrarse(db);
		break;
	case 2:
		loggearse(db);
		break;
	case 3:
		break;
	case 4:
		cout << "Saliendo del programa...";
		Sleep(3000);
		exit(1);
		break;
	default:
		break;
	}

}

