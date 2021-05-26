extern "C" {
#include "sqlite3.h"
}
#include "string.h"
#include "usuario.h"
#include "database.h"
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
}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include "registrarse.h"
//#include "login.h"
//
//char* quitadorContrabarraN(char *s) {
//	char *n;
//	n = (char*) malloc(strlen(s ? s : "\n"));
//	if (s) {
//		strcpy(n, s);
//	}
//	n[strlen(n) - 1] = '\0';
//	return n;
//}
//
//void registrarse() {
//
//	char *nombre;
//	nombre = (char*) malloc(20 * sizeof(char));
//	char *apellido;
//	apellido = (char*) malloc(20 * sizeof(char));
//	char *dni;
//	dni = (char*) malloc(10 * sizeof(char));
//	int telefono = 0;
//	int numTarj = 0;
//	int contrasenya = 0;
//
//	printf("\n---------REGISTRARSE---------\n");
//	fflush(stdout);
//
//	printf("Insertar Nombre: ");
//	fflush(stdout);
//	fgets(nombre, 20, stdin);
//	nombre = quitadorContrabarraN(nombre);
//
//	printf("Insertar Apellido: ");
//	fflush(stdout);
//	fgets(apellido, 20, stdin);
//	apellido = quitadorContrabarraN(apellido);
//
//	printf("Insertar DNI: ");
//	fflush(stdout);
//	fgets(dni, 10, stdin);
//	dni = quitadorContrabarraN(dni);
//
//	printf("Insertar Telefono: ");
//	fflush(stdout);
//	scanf("%i", &telefono);
//
//	printf("Insertar Tarjeta: ");
//	fflush(stdout);
//	scanf("%i", &numTarj);
//
//	printf("Insertar Contrasenya Numerica: ");
//	fflush(stdout);
//	scanf("%i", &contrasenya);
//
//	printf("-----------------------------\n");
//	fflush(stdout);
//
//	fflush(stdin);
//	loggearse();
//}
