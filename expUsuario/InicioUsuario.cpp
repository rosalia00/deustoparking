#include "InicioUsuario.h"
#include <iostream>
extern "C" {
#include "../basedatos/Sqlite3.h"
}
#include "../basedatos/Database.h"
#include "../persona/Usuario.h"
#include "../reserva/Reservar.h"
#include "Mapa.h"
using namespace std;

void inicioUsuario(Usuario *u, sqlite3 *db) {

	int opcion;
	char volver;

	cout << endl << "--- BIENVENIDO " << u->getNombre() << " ---" << endl;
	cout << "1. Reservar plazas." << endl << "2. Mapa." << endl
			<< "3. Reservas." << endl << "4. Salir." << endl;

	do {
		cout << "Elija la opción: ";
		cin >> opcion;
	} while (opcion < 1 || opcion > 4);

	switch (opcion) {
	case 1:
		reservacion(u, db);
		break;
	case 2:
		ventanaMapa(1, db, u);
		break;
	case 3:
		cout << endl << "Mostrando las reservas: " << endl;
		printReservas(db, u);
		cout << endl
				<< "Escribe cualquier letra para volver al menu de usuario: ";
		cin >> volver;
		inicioUsuario(u, db);
		break;
	case 4:
		cout << "Saliendo del programa...";
		exit(1);
		break;
	default:
		break;
	}

}

