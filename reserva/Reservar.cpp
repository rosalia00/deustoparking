///*
// * reserva.cpp
// *
// *  Created on: 1 jun. 2021
// *      Author: Tyler de Mier
// */
//extern "C" {
//#include "../basedatos/Sqlite3.h"
//}
//#include "../basedatos/Database.h"
//#include "../persona/Usuario.h"
//#include "../expUsuario/InicioUsuario.h"
//#include <cstring>
//#include "Reserva.h"
//#include "Reservar.h"
//#include "Ticket.h"
//#include <iostream>
//using namespace std;
//
//void tipoBono(sqlite3 *db, Usuario *u, Reserva *res) {
//
//	float precioSem = recogerPrecioBono(db, 1);
//	float precioMen = recogerPrecioBono(db, 2);
//	float precioAnu = recogerPrecioBono(db, 3);
//
//	int opcion;
//
//	if (strcmp(u->getTipo(), "Profesor") == 0) {
//		precioSem = precioSem + (precioSem * 0.2);
//		precioMen = precioMen + (precioMen * 0.2);
//		precioAnu = precioAnu + (precioAnu * 0.2);
//	}
//
//	cout << "Tipos de Bonos:" << endl;
//	cout << "1. Bono Semanal: " << precioSem << "€" << endl;
//	cout << "2. Bono Mensual: " << precioMen << "€" << endl;
//	cout << "3. Bono Anual: " << precioAnu << "€" << endl;
//
//	do {
//		cout << "Elija el tipo de bono: ";
//		cin >> opcion;
//	} while (opcion < 1 || opcion > 3);
//
//	switch (opcion) {
//	case 1:
//		res->bono = 1;
//		res->precio = precioSem;
//		break;
//	case 2:
//		res->bono = 2;
//		res->precio = precioMen;
//		break;
//	case 3:
//		res->bono = 3;
//		res->precio = precioAnu;
//		break;
//	default:
//		break;
//	}
//}
//
//void reservacion(Usuario *u, sqlite3 *db) {
//
//	Reserva *res;
//
//	int plaza;
//	int horaI;
//	char *cHoraI = new char[4];
//	int horaF;
//	char *cHoraF = new char[4];
//	int fid;
//	int fim;
//	int fia;
//	int ffd;
//	int ffm;
//	int ffa;
//
//	int opcion;
//	char *tecla = new char[1];
//
//	cout << "PLAZA: ";
//	cin >> plaza;
//	res->plaza = plaza;
//
//	cout << "HORA INICIO: ";
//	cin >> horaI;
//	itoa(horaI, cHoraI, 10);
//	res->datainicio = cHoraI;
//
//	cout << "HORA FINAL: ";
//	cin >> horaF;
//	itoa(horaF, cHoraF, 10);
//	res->datafin = cHoraF;
//
//	cout << "FECHA INICIO DIA: ";
//	cin >> fid;
//
//	cout << "FECHA INICIO MES: ";
//	cin >> fim;
//
//	cout << "FECHA INICIO ANYO: ";
//	cin >> fia;
//
//	char *datainFinal = new char[9];
//	char *datain1 = new char[2];
//	char *datain2 = new char[2];
//	char *datain3 = new char[2];
//
//	itoa(fid, datain1, 10);
//	itoa(fim, datain2, 10);
//	itoa(fia, datain3, 10);
//
//	strcpy(datainFinal, datain1);
//	strcat(datainFinal, "-");
//	strcat(datainFinal, datain2);
//	strcat(datainFinal, "-");
//	strcat(datainFinal, datain3);
//
//	cout << "FECHA FIN DIA: ";
//	cin >> ffd;
//
//	cout << "FECHA FIN MES: ";
//	cin >> ffm;
//
//	cout << "FECHA FIN ANYO: ";
//	cin >> ffa;
//
//	char *datafinFinal = new char[9];
//	char *datafin1 = new char[2];
//	char *datafin2 = new char[2];
//	char *datafin3 = new char[2];
//
//	itoa(ffd, datafin1, 10);
//	itoa(ffm, datafin2, 10);
//	itoa(ffa, datafin3, 10);
//
//	strcpy(datafinFinal, datafin1);
//	strcat(datafinFinal, "-");
//	strcat(datafinFinal, datafin2);
//	strcat(datafinFinal, "-");
//	strcat(datafinFinal, datafin3);
//
//	res->apellido = u->getApellido();
//	res->datafin = datafinFinal;
//	res->datainicio = datainFinal;
//	res->dni = u->getdni();
//	res->nombre = u->getNombre();
//	res->plaza = plaza;
////	tipoBono(db, u, res);
//	res->tarjeta = u->getTarjeta();
//
//	cout << "1. Guardar e imprimir el ticket." << endl
//			<< "2. Cancelar y volver al inicio.";
//
//	do {
//		cout << "Elija la opción: ";
//		cin >> opcion;
//	} while (opcion < 1 || opcion > 2);
//
//	switch (opcion) {
//	case 1:
//		ticket(res, db);
//		cout << "Pulse una tecla para volver al menu principal...";
//		cin >> tecla;
//		inicioUsuario(u, db);
//		break;
//	case 2:
//		inicioUsuario(u, db);
//		break;
//	default:
//		break;
//	}
//}
//


extern "C"{
#include "../basedatos/Sqlite3.h"
}
#include "../expUsuario/InicioUsuario.h"
#include "Reserva.h"
#include "Ticket.h"
#include "TipoBono.h"
#include "Reservar.h"
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

Reserva reservacion(Usuario *u, sqlite3 *db) {

	Reserva res;

	int plaza = 0;
	int horaI = 0;
	int horaF = 0;
	int fid = 0;
	int fim = 0;
	int fia = 0;
	int ffd = 0;
	int ffm = 0;
	int ffa = 0;

	int eleccion;
	int c;

	printf("PLAZA: ");
	fflush(stdout);
	scanf("%i", &plaza);

	printf("HORA INICIO: ");
	fflush(stdout);
	scanf("%i", &horaI);

	printf("HORA FINAL: ");
	fflush(stdout);
	scanf("%i", &horaF);

	printf("FECHA INICIO DIA: ");
	fflush(stdout);
	scanf("%i", &fid);

	printf("FECHA INICIO MES: ");
	fflush(stdout);
	scanf("%i", &fim);

	printf("FECHA INICIO ANYO: ");
	fflush(stdout);
	scanf("%i", &fia);

	char datainFinal[11];
	char datain1[3];
	char datain2[3];
	char datain3[5];

	itoa(fid, datain1, 10);
	itoa(fim, datain2, 10);
	itoa(fia, datain3, 10);

	strcpy(datainFinal, datain1);
	strcat(datainFinal, "-");
	strcat(datainFinal, datain2);
	strcat(datainFinal, "-");
	strcat(datainFinal, datain3);

	printf("FECHA FIN DIA: ");
	fflush(stdout);
	scanf("%i", &ffd);

	printf("FECHA FIN MES: ");
	fflush(stdout);
	scanf("%i", &ffm);

	printf("FECHA FIN ANYO: ");
	fflush(stdout);
	scanf("%i", &ffa);

	char datafinFinal[11];
	char datafin1[3];
	char datafin2[3];
	char datafin3[5];

	itoa(ffd, datafin1, 10);
	itoa(ffm, datafin2, 10);
	itoa(ffa, datafin3, 10);

	strcpy(datafinFinal, datafin1);
	strcat(datafinFinal, "-");
	strcat(datafinFinal, datafin2);
	strcat(datafinFinal, "-");
	strcat(datafinFinal, datafin3);

	res.apellido = u->getApellido();
	res.datafin = datafinFinal;
	res.datainicio = datainFinal;
	res.dni = u->getdni();
	res.nombre = u->getNombre();
	res.plaza = plaza;
	tipoBono(db, u, &res);
	fflush(stdin);
	res.tarjeta = u->getTarjeta();

	system("cls");
	do {
		printf("\n1. Guardar e imprimir ticket.\n2. Cancelar y volver a inicio.\n");
		printf("\nElija opcion: ");
		fflush(stdout);
		scanf("%i", &eleccion);
		switch (eleccion) {
		case 1:
			fflush(stdout);
			ticket(&res, db);
			printf("\nPulse una tecla para volver al menu principal... ");
			fflush(stdout);
			cin >> c;
			inicioUsuario(u, db);
			break;
		case 2:
			fflush(stdin);
			inicioUsuario(u, db);
			break;
		default:
			printf("CARACTER INVALIDO. INSERTE UNO NUEVO: ");
			fflush(stdout);
			fflush(stdin);
			cin >> c;
			break;
		}
	} while (eleccion <= 0 || eleccion >= 3);

	return res;
}
