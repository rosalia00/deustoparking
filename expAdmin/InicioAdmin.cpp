#include "inicioAdmin.h"

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
		//aqui van las estadisticas
		break;
	case 3:
		cout << "Saliendo del programa...";
		exit(1);
		break;
	default:
		break;
	}

}
