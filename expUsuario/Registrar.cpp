
#include <iostream>
extern "C" {
#include "../basedatos/Sqlite3.h"
}
#include "../basedatos/Database.h"
#include "../persona/Usuario.h"
#include "Registrar.h"
#include "InicioUsuario.h"
#include <string>
using namespace std;

void registrarse(sqlite3 *db) {
	Usuario *u = new Usuario();
	int opcion;
	char *dni = new char[10];
	char *nombre = new char[25];
	char *apellido = new char[50];
	int telefono;
	int tarjeta;
	char *contrasenya = new char[20];
	char *matricula = new char[8];

	cout << endl << "--- --- REGISTRARSE --- ---";

	cout << endl << "DNI: ";
	cin >> dni;
	u->setdni(dni);

	cout << endl << "Nombre: ";
	cin >> nombre;
	u->setNombre(nombre);

	cout << endl << "Apellido: ";
	cin >> apellido;
	u->setApellido(apellido);

	cout << endl << "Numero de Telefono: ";
	cin >> telefono;
	u->setTelefono(telefono);

	cout << endl << "Numero de Tarjeta: ";
	cin >> tarjeta;
	u->setTarjeta(tarjeta);

	cout << endl << "Contrasenya: ";
	cin >> contrasenya;
	u->setContrasenya(contrasenya);

	cout << endl << "Tipo de usuario: " << endl << "1. Estudiante" << endl
			<< "2. Profesor" << endl;
	do {
		cout << "Seleccione el tipo de usuario: ";
		cin >> opcion;
	} while (opcion < 1 || opcion > 2);

	char *tipoString = new char[11];
	switch (opcion) {
	case 1:
		tipoString = (char*)"Estudiante";
		u->setTipo(tipoString);
		break;
	case 2:
		tipoString = (char*)"Profesor";
		u->setTipo(tipoString);
		break;
	}

	cout << endl << "Matricula: ";
	cin >> matricula;
	u->setMatricula(matricula);

	baseDatosUsuarioRegistrar(db, u);
	inicioUsuario(u, db);

	cout << endl << "USUARIO REGISTRADO" << endl
			<< "--- --- ----------- --- ---" << endl;
}

