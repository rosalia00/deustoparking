#include <iostream>
extern "C" {
#include "../basedatos/Sqlite3.h"
}
#include "../basedatos/Database.h"
#include "../expUsuario/InicioUsuario.h"
#include "Reserva.h"
#include "Ticket.h"
#include "TipoBono.h"
#include "Reservar.h"
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

Reserva reservacion(Usuario *u, sqlite3 *db) {

	Reserva *res = new Reserva();

	int plaza = 0;
	int horaI = 0;
	int horaF = 0;
	char *fid = new char[3];
	char *fim = new char[3];
	char *fia = new char[5];
	char *ffd = new char[3];
	char *ffm = new char[3];
	char *ffa = new char[5];

	char *tecla = new char[2];
	int opcion;

	cout << endl << "PLAZA: ";
	cin >> plaza;
	res->setPlaza(plaza);

	cout << "HORA INICIO: ";
	cin >> horaI;
	res->setHorainicio(horaI);

	cout << "HORA FINAL: ";
	cin >> horaF;
	res->setHorafin(horaF);

	cout << "FECHA INICIO DIA: ";
	cin >> fid;

	cout << "FECHA INICIO MES: ";
	cin >> fim;

	cout << "FECHA INICIO ANYO: ";
	cin >> fia;

	char *datainFinal = new char[11];

	strcpy(datainFinal, fid);
	strcat(datainFinal, "-");
	strcat(datainFinal, fim);
	strcat(datainFinal, "-");
	strcat(datainFinal, fia);

	res->setDatainicio(datainFinal);

	cout << "FECHA FIN DIA: ";
	cin >> ffd;

	cout << "FECHA FIN MES: ";
	cin >> ffm;

	cout << "FECHA FIN ANYO: ";
	cin >> ffa;

	char *datafinFinal = new char[11];

	strcpy(datafinFinal, ffd);
	strcat(datafinFinal, "-");
	strcat(datafinFinal, ffm);
	strcat(datafinFinal, "-");
	strcat(datafinFinal, ffa);

	res->setDatafin(datafinFinal);

	res->setApellido(u->getApellido());
	res->setDni(u->getdni());
	res->setNombre(u->getNombre());
	cout << endl;
	tipoBono(db, u, res);
	res->setMatricula(u->getMatricula());
	res->setTarjeta(u->getTarjeta());

	cout << endl << "1. Guardar e imprimir el ticket." << endl
			<< "2. Cancelar y volver al inicio." << endl;

	do {
		cout << "Elija la opción: ";
		cin >> opcion;
	} while (opcion < 1 || opcion > 2);

	switch (opcion) {
	case 1:
		guardarTicket(db, res);
		ticket(res, db);
		cout << "Pulse una tecla para volver al menu principal... ";
		cin >> tecla;
		inicioUsuario(u, db);
		break;
	case 2:
		inicioUsuario(u, db);
		break;
	default:
		break;
	}

	Reserva reserv;
	return reserv;
}
