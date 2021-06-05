#include <iostream>
#include "InicioUsuario.h"
extern "C" {
#include "../basedatos/Sqlite3.h"
}
#include "../basedatos/Database.h"
#include "../persona/Usuario.h"
#include "../reserva/Reservar.h"
#include "Mapa.h"
#include <windows.h>
using namespace std;

void inicioUsuario(Usuario *u, sqlite3 *db) {

	int opcion;
	char volver;

	cout << endl << "--- BIENVENIDO " << u->getNombre() << " ---" << endl;
	cout << "1. Reservar plazas." << endl << "2. Mapa." << endl
			<< "3. Reservas." << endl << endl << "4. Salir." << endl;

	do {
		cout << "Elija la opci�n: ";
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
		cout << endl << "Saliendo del programa..." << endl;
		Sleep(1000);
		cout << "�GRACIAS POR USAR DEUSTO PARKING!";
		exit(1);
		break;
	default:
		break;
	}

}

