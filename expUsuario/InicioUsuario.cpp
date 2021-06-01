/*
 * InicioUsuario.cpp
 *
 *  Created on: 1 jun. 2021
 *      Author: Tyler de Mier
 */
extern "C" {
#include "../basedatos/Sqlite3.h"
}
#include "../persona/Usuario.h"
#include "../reserva/Reserva.h"
#include "InicioUsuario.h"
#include "Mapa.h"
#include "iostream"
using namespace std;

void inicioUsuario(Usuario *u, sqlite3 *db) {

	int opcion;

	cout << endl << "--- BIENVENIDO " << u->getNombre() << " ---" << endl;
	cout << "1. Reservar plazas." << endl << "2. Mapa." << endl
			<< "3. Reservas." << endl;

	do {
		cout << "Elija la opción: ";
		cin >> opcion;
	} while (opcion < 1 || opcion > 3);

	switch (opcion) {
	case 1:
		reservacion(u, db);
		break;
	case 2:
		ventanaMapa(1, db, u);
		break;
	case 3:
		break;
	default:
		break;
	}

}

