#include "Inicio.h"
#include "persona/Usuario.h"
#include "expAdmin/LoginAdmin.h"
#include <windows.h>
#include <stdio.h>
#include <ctype.h>

void admin(sqlite3 *db, char *tipo) {
	char *tipoNuevo;
	int opcion;

	cout << "--- BIENVENIDO A DEUSTO PARKING ---" << endl;
	cout << "1. Iniciar sesion." << endl << "2. Cambiar a Usuario"
			<< endl << "3. Salir del programa." << endl;
	do {
		cout << "Elija la opción: ";
		cin >> opcion;
	} while (opcion < 1 || opcion > 3);

	switch (opcion) {
	case 1:
		loggearseAdmin(db);
		break;
	case 2:
		tipoNuevo = (char*) "Usuario";
		inicio(db, tipoNuevo);
		break;
	case 3:
		cout << "Saliendo del programa...";
		Sleep(3000);
		exit(1);
		break;

	default:
		break;
	}
}
