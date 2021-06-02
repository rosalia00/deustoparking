/*
 * Registrar.cpp
 *
 *  Created on: 1 jun. 2021
 *      Author: Tyler de Mier
 */

extern "C" {
#include "../basedatos/Sqlite3.h"
}
#include "../basedatos/Database.h"
#include "../persona/Usuario.h"
#include "Registrar.h"
#include "InicioUsuario.h"
#include <string>
#include <iostream>
using namespace std;

void registrarse(sqlite3 *db) {
	Usuario *u = new Usuario();
	int opcion;
	char *dni = (char*) malloc(10 * sizeof(char));
	char *nombre = (char*) malloc(25 * sizeof(char));
	char *apellido = (char*) malloc(50 * sizeof(char));
	int telefono;
	int tarjeta;
	char *contrasenya = (char*) malloc(20 * sizeof(char));
	char *matricula = (char*) malloc(8 * sizeof(char));

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

	char *tipoString = (char*) malloc(11 * sizeof(char));
	switch (opcion) {
	case 1:
		tipoString = "Estudiante";
		u->setTipo(tipoString);
		break;
	case 2:
		tipoString = "Profesor";
		u->setTipo(tipoString);
		break;
	}

	cout << endl << "Matricula: ";
	cin >> matricula;
	u->setMatricula(matricula);

	cout << endl << "USUARIO REGISTRADO" << endl
			<< "--- --- ----------- --- ---" << endl;
	baseDatosUsuarioRegistrar(db, u);
	inicioUsuario(u, db);
}

