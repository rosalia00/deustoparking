/*
 * Administrar.cpp
 *
 *  Created on: 1 jun. 2021
 *      Author: Tyler de Mier
 */
#include "iostream"
extern "C" {
#include "../basedatos/Sqlite3.h"
}
#include "../basedatos/Database.h"
#include <string>
#include <cstring>
#include "Administrar.h"
#include "InicioAdmin.h"
using namespace std;

void administrarInicio(sqlite3 *db, Administrador *a) {
	int opcion;
	float precio;
	int eleccion;
	string nombre;
	cout << "--- ADMINISTRAR BONOS ---" << endl << endl << "Tipo de bono:"
			<< endl << "1. Semanal" << endl << "2. Mensual" << endl
			<< "3. Trimestral" << endl << "4. Anual" << endl << "5. Volver"<< endl;
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
	case 5:
		inicioAdmin(a, db);
		break;
	default:
		break;
	}

	cout << "Escriba el precio: ";
	cin >> precio;

	cout << endl << "�QUIERE CONFIRMAR LOS SIGUIENTES CAMBIOS?" << endl
			<< "Tipo Bono -> " << nombre << endl << "Precio -> " << precio
			<< "�" << endl;
	cout << endl << "1. Confirmar" << endl << "2. Deshacer cambios y volver"
			<< endl;
	do {
		cout << "Seleccione la opci�n: ";
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

