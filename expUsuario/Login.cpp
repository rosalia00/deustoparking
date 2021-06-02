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
	cout << "Introduzca su contrasenya: ";
	cin >> contrasenya;

	Usuario u;
	u.apellido = new char[24];
	u.contrasenya = new char[24];
	u.dni = new char[24];
	u.matricula= new char[24];
	u.nombre= new char[24];
	u.tarjeta= 0;
	u.tipo= new char[24];
	u.telefono=0;
	inicioSesion(db, dni, &u);

	cout<<endl<<u.contrasenya<<" "<<contrasenya;
	if (strcmp(u.getContrasenya(), contrasenya)) {
		inicioUsuario(&u, db);
	} else {
		cout << "Contraseña o usuario inexistente por favor intentelo de nuevo"<<endl;
		loggearse(db);
	}
}
