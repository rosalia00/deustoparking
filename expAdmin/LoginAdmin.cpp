#include <iostream>
extern "C" {
#include "../basedatos/Sqlite3.h"
}
#include "../basedatos/Database.h"
#include "../persona/Administrador.h"
#include <string.h>
#include "LoginAdmin.h"
#include "InicioAdmin.h"
using namespace std;

void loggearseAdmin(sqlite3 *db) {
	char *dni = new char[9];
	cout << "Introduzca su DNI: ";
	cin >> dni;

	char *contrasenya = new char[32];
	cout << "Introduzca su contrasenya: ";
	cin >> contrasenya;

	Administrador *a = new Administrador();
	inicioSesionAdmin(db, dni, a);

	if (strcmp(a->getContrasenya(), contrasenya) == 0) {
		inicioAdmin(a, db);
	} else {
		cout << "Contraseña o usuario inexistente por favor intentelo de nuevo"
				<< endl;
		loggearseAdmin(db);
	}
	delete[] dni;
	delete[] contrasenya;
}
