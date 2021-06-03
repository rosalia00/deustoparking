#include "iostream"
extern "C" {
#include "basedatos/Sqlite3.h"
}
#include "persona/Usuario.h"
#include "expUsuario/InicioUsuario.h"
#include "expUsuario/Login.h"
#include "expAdmin/LoginAdmin.h"
#include "expUsuario/Registrar.h"
#include <windows.h>
#include <stdio.h>
#include <ctype.h>
using namespace std;

void inicio(sqlite3 *db, char *tipo) {
	char* tipoNuevo;
	int opcion;

	cout << "--- BIENVENIDO A DEUSTO PARKING ---" << endl;
	cout << "1. Registrarse." << endl << "2. Iniciar sesion." << endl
			<< "3. Administrador." << endl << "4. Salir del programa." << endl;
	cout << "Estas accediendo como " << tipo << " si desea cambiar pulse 5"
			<< endl;
	if (strcmp(tipo, "Usuario")==0) {
		do {
			cout << "Elija la opci�n: ";
			cin >> opcion;
		} while (opcion < 1 || opcion > 5);

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
		case 5:
			tipoNuevo = (char*)"Administrador";
			inicio(db, tipoNuevo);
			break;
		default:
			break;
		}
	} else if (strcmp(tipo, "Administrador")==0) {
		do {
			cout << "Elija la opci�n: ";
			cin >> opcion;
		} while (opcion < 1 || opcion > 5);

		switch (opcion) {
		case 1:
			registrarse(db);
			break;
		case 2:
			loggearseAdmin(db);
			break;
		case 3:
			break;
		case 4:
			cout << "Saliendo del programa...";
			Sleep(3000);
			exit(1);
			break;
		case 5:
			tipoNuevo = (char*)"Administrador";
			inicio(db, tipoNuevo);
			break;
		default:
			break;
		}
	}

}

