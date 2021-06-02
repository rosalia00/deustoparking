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
#include <string.h>
#include "InicioUsuario.h"
#include "Login.h"
#include <iostream>
using namespace std;

void loggearse(sqlite3 *db) {
	char *dni = new char[9];
	cout << "Introduzca su DNI: ";
	cin >> dni;

	char *contrasenya = new char[32];
	cout<<"holiwis";
	cout << "Introduzca su contrasenya: ";
	cin >> contrasenya;
	cout<<"hola";
	Usuario u = Usuario();

	inicioSesion(db, dni, &u);

	if (strcmp(u.getContrasenya(), contrasenya)) {
		inicioUsuario(&u, db);
	} else {
		cout << "Contraseņa o usuario inexistente por favor intentelo de nuevo"<<endl;
		loggearse(db);
	}
}
