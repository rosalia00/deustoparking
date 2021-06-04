#include "inicioAdmin.h"
#include <iostream>
extern "C" {
#include "../basedatos/Sqlite3.h"
}
#include "../basedatos/Database.h"
#include "../persona/Administrador.h"
#include "Estadisticas.h"
#include "Administrar.h"
using namespace std;

void inicioAdmin(Administrador *a, sqlite3 *db) {
	int opcion;

	cout << endl << "--- BIENVENIDO " << a->getNombre() << " ---" << endl;
	cout << "1. Administrar Bonos" << endl << "2. Ver estadisticas" << endl
			<< "3. Salir." << endl;

	do {
		cout << "Elija la opción: ";
		cin >> opcion;
	} while (opcion < 1 || opcion > 4);

	switch (opcion) {
	case 1:
		administrarInicio(db, a);
		break;
	case 2:
		menuEstadisticas(db, a);
		break;
	case 3:
		cout << "Saliendo del programa...";
		exit(1);
		break;
	default:
		break;
	}

}
