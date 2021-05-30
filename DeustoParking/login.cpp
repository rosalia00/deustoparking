#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "registrarse.h"
#include "inicioUsuario.h"
extern "C"{
#include "sqlite3.h"
}

void loggearse(sqlite3 *db) {
	char *dni;
	cout<<"Introduzca su DNI: ";
	cin >> dni;

	char *contrasenya;
	cout<<"Introduzca su contrasenya: ";
	cin >> contrasenya;

	Usuario u = inicioSesion(db, dni);

	if(u.contrasenya == contrasenya){
		inicioUsuario(u, db);
	} else{
		cout<<"Contraseña o usuario inexistente por favor intentelo de nuevo";
		loggearse(db);
	}
}

	//	char *dni;
//	dni = (char*) malloc(10 * sizeof(char));
//	int contrasenya;
//
//	printf("\nIntroduzca su DNI: ");
//	fflush(stdout);
//	fgets(dni, 10, stdin);
//	dni = quitadorContrabarraN(dni);
//
//	printf("Introduzca su contrasenya: ");
//	fflush(stdout);
//	scanf("%i", &contrasenya);
//
//	Usuario u;
//	u.dni = dni;
//	u.contrasenya = contrasenya;
//	u.nombre = "nombre_prueba";
//	u.apellido = "apellido_prueba";
//	u.numTarj = 12341234;
//	u.telefono = 123456789;
//	inicioUsuario(u, db);


