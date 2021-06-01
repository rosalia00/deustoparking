/*
 * Login.cpp
 *
 *  Created on: 1 jun. 2021
 *      Author: Tyler de Mier
 */

extern "C" {
#include "../basedatos/Sqlite3.h"
}
#include "../basedatos/Database.h"
#include "../persona/Usuario.h"
#include "InicioUsuario.h"
#include "Login.h"
#include <iostream>
using namespace std;

void loggearse(sqlite3 *db) {
	char *dni = new char[9];
	cout << "Introduzca su DNI: ";
	cin >> dni;

	char *contrasenya = new char[32];
	cout << "Introduzca su contrasenya: ";
	cin >> contrasenya;

	Usuario *u;
	inicioSesion(db, dni, u);
	cout<<dni<<" "<<u->dni<<endl;
	if (u->contrasenya == contrasenya) {
		inicioUsuario(u, db);
	} else {
		cout << "Contraseña o usuario inexistente por favor intentelo de nuevo"<<endl;
		loggearse(db);
	}
}
