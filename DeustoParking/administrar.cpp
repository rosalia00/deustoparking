extern "C" {
#include "sqlite3.h"
}
#include <string>
#include <cstring>
#include "database.h"
#include <iostream>
using namespace std;

void administrarInicio(sqlite3 *db) {
	int opcion;
	float precio;
	int eleccion;
	string nombre;
	cout << "--- ADMINISTRAR BONOS ---" << endl << endl << "Tipo de bono:"
			<< endl << "1. Semanal" << endl << "2. Mensual" << endl
			<< "3. Trimestral" << endl << "4. Anual" << endl << endl;
	do {
		cout << "Seleccione el bono a cambiar: ";
		cin >> opcion;
	} while (opcion < 1 || opcion > 4);

	switch (opcion) {
	case 1:
		nombre = "Semanal";
		break;
	case 2:
		nombre = "Mensual";
		break;
	case 3:
		nombre = "Trimestral";
		break;
	case 4:
		nombre = "Anual";
		break;
	default:
		break;
	}

	cout << "Escriba el precio: ";
	cin >> precio;

	cout << endl << "¿QUIERE CONFIRMAR LOS SIGUIENTES CAMBIOS?" << endl
			<< "Tipo Bono -> " << nombre << endl << "Precio -> " << precio
			<< "€" << endl;
	cout << endl << "1. Confirmar" << endl << "2. Deshacer cambios y volver"
			<< endl;
	do {
		cout << "Seleccione la opción: ";
		cin >> eleccion;
	} while (eleccion < 1 || eleccion > 2);

	switch (eleccion) {
	case 1:
		administrarBono(db, precio, opcion);
		cout << endl << "Volviendo a la pantalla de inicio...";
		break;
	case 2:
		cout << endl << "Volviendo a la pantalla de inicio...";
		break;
	default:
		break;
	}

}
