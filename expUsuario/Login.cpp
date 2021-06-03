#include <iostream>
extern "C" {
#include "../basedatos/Sqlite3.h"
}
#include "../basedatos/Database.h"
#include "../persona/Usuario.h"
#include <string.h>
#include "InicioUsuario.h"
#include "Login.h"
using namespace std;

void loggearse(sqlite3 *db) {
	char *dni = new char[9];
	cout << "Introduzca su DNI: ";
	cin >> dni;

	char *contrasenya = new char[32];
	cout << "Introduzca su contrasenya: ";
	cin >> contrasenya;

	Usuario *u = new Usuario();
	inicioSesion(db, dni, u);

	cout << "DNI:" << u->getdni() << " Contrasenya:" << u->getContrasenya()
			<< endl;

	if (strcmp(u->getContrasenya(), contrasenya) == 0) {
		inicioUsuario(u, db);
	} else {
		cout << "Contraseña o usuario inexistente por favor intentelo de nuevo"
				<< endl;
		loggearse(db);
	}
}
