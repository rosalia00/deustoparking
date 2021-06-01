/*
 * reserva.cpp
 *
 *  Created on: 1 jun. 2021
 *      Author: Tyler de Mier
 */
extern "C" {
#include "../basedatos/Sqlite3.h"
}
#include "../basedatos/Database.h"
#include "../persona/Usuario.h"
#include "../expUsuario/InicioUsuario.h"
#include <cstring>
#include "Reserva.h"
#include <iostream>
using namespace std;

void reservacion(Usuario *u, sqlite3 *db) {

	Reserva *res;

	int plaza;
	int horaI;
	char *cHoraI = new char[4];
	int horaF;
	char *cHoraF = new char[4];
	int fid;
	int fim;
	int fia;
	int ffd;
	int ffm;
	int ffa;

	int opcion;
	char *tecla = new char[1];

	cout << "PLAZA: ";
	cin >> plaza;
	res->plaza = plaza;

	cout << "HORA INICIO: ";
	cin >> horaI;
	itoa(horaI, cHoraI, 10);
	res->datainicio = cHoraI;

	cout << "HORA FINAL: ";
	cin >> horaF;
	itoa(horaF, cHoraF, 10);
	res->datafin = cHoraF;

	cout << "FECHA INICIO DIA: ";
	cin >> fid;

	cout << "FECHA INICIO MES: ";
	cin >> fim;

	cout << "FECHA INICIO ANYO: ";
	cin >> fia;

	char *datainFinal = new char[9];
	char *datain1 = new char[2];
	char *datain2 = new char[2];
	char *datain3 = new char[2];

	itoa(fid, datain1, 10);
	itoa(fim, datain2, 10);
	itoa(fia, datain3, 10);

	strcpy(datainFinal, datain1);
	strcat(datainFinal, "-");
	strcat(datainFinal, datain2);
	strcat(datainFinal, "-");
	strcat(datainFinal, datain3);

	cout << "FECHA FIN DIA: ";
	cin >> ffd;

	cout << "FECHA FIN MES: ";
	cin >> ffm;

	cout << "FECHA FIN ANYO: ";
	cin >> ffa;

	char *datafinFinal = new char[9];
	char *datafin1 = new char[2];
	char *datafin2 = new char[2];
	char *datafin3 = new char[2];

	itoa(ffd, datafin1, 10);
	itoa(ffm, datafin2, 10);
	itoa(ffa, datafin3, 10);

	strcpy(datafinFinal, datafin1);
	strcat(datafinFinal, "-");
	strcat(datafinFinal, datafin2);
	strcat(datafinFinal, "-");
	strcat(datafinFinal, datafin3);

	res->apellido = u->getApellido();
	res->datafin = datafinFinal;
	res->datainicio = datainFinal;
	res->dni = u->getdni();
	res->nombre = u->getNombre();
	res->plaza = plaza;
	tipoBono(db, u, res);
	res->tarjeta = u->getTarjeta();

	cout << "1. Guardar e imprimir el ticket." << endl
			<< "2. Cancelar y volver al inicio.";

	do {
		cout << "Elija la opción: ";
		cin >> opcion;
	} while (opcion < 1 || opcion > 2);

	switch (opcion) {
	case 1:
		ticket(res, db);
		cout << "Pulse una tecla para volver al menu principal...";
		cin >> tecla;
		inicioUsuario(u, db);
		break;
	case 2:
		inicioUsuario(u, db);
		break;
	default:
		break;
	}
}

