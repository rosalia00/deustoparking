///*
// * ticket.cpp
// *
// *  Created on: 1 jun. 2021
// *      Author: Tyler de Mier
// */
//extern "C" {
//#include "../basedatos/Sqlite3.h"
//}
//#include "../basedatos/Database.h"
//#include "Reserva.h"
//#include <stdio.h>
//#include <iostream>
//#include <fstream>
//using namespace std;
//
//void ticket(Reserva *res, sqlite3 *db) {
//	cout<<"entra";
//
////	ofstream freserva("ticket.dat");
////
////	freserva << "Nombre: , " << res->nombre;
////	freserva << "Apellido: , " << res->apellido;
////	freserva << "DNI: , " << res->dni;
////	freserva << "Tarjeta: , " << res->tarjeta;
////	freserva << "Fecha de Inicio: , " << res->datainicio;
////	freserva << "Fecha de Fin: , " << res->datafin;
////	freserva << "Precio: , " << res->precio;
////	freserva << "Matricula: , " << res->matricula;
////	freserva << "Plaza: , " << res->plaza;
////
////	freserva.close();
//
//	guardarTicket(db, res);
//
////	printf("\n------ DATOS DE LA RESERVA ------\n");
////	printf("Nombre: %s\n", res->nombre);
////	printf("Apellido: %s\n", res->apellido);
////	printf("DNI: %s\n", res->dni);
////	printf("Tarjeta: %i\n", res->tarjeta);
////	printf("Fecha de Inicio: %s\n", res->datainicio);
////	printf("Fecha de Fin: %s\n", res->datafin);
////	printf("Precio: %.2f\n", res->precio);
////	printf("Matricula: %s\n", res->matricula);
////	printf("Plaza: %i\n", res->plaza);
////	fflush(stdout);
//}
#include <iostream>
extern "C" {
#include "../basedatos/Sqlite3.h"
}
#include "../basedatos/Database.h"
#include "Reserva.h"
#include "Ticket.h"
#include <stdio.h>
using namespace std;

void ticket(Reserva *res, sqlite3 *db) {
	FILE *freserva;
	freserva = fopen("ticket.dat", "a");
	if (freserva != NULL) {
		fprintf(freserva, "Nombre: %s; ", res->nombre);
		fprintf(freserva, "Apellido: %s; ", res->apellido);
		fprintf(freserva, "DNI: %s; ", res->dni);
		fprintf(freserva, "Tarjeta: %i; ", res->tarjeta);
		fprintf(freserva, "Fecha de Inicio: %s; ", res->datainicio);
		fprintf(freserva, "Fecha de Fin: %s; ", res->datafin);
		fprintf(freserva, "Precio: %.2f; ", res->precio);
		fprintf(freserva, "Matricula: %s; ", res->matricula);
		fprintf(freserva, "Plaza: %i; ", res->plaza);

		fclose(freserva);
	}

	cout << "------ DATOS DE LA RESERVA ------" << endl;
	cout << "Nombre: " << res->getNombre() << endl;
	cout << "Apellido: " << res->getApellido() << endl;
	cout << "DNI: " << res->getDni() << endl;
	cout << "Tarjeta: " << res->getTarjeta() << endl;
	cout << "Fecha de inicio: " << res->getDatainicio() << endl;
	cout << "Fecha fin: " << res->getDatafin() << endl;
	cout << "Hora de inicio: " << res->getHorainicio() << endl;
	cout << "Hora fin: " << res->getHorafinal() << endl;
	cout << "Precio: " << res->getPrecio() << endl;
	cout << "Matricula: " << res->getMatricula() << endl;
	cout << "Plaza: " << res->getPlaza() << endl;

//	printf("\n------ DATOS DE LA RESERVA ------\n");
//	printf("Nombre: %s\n", res->nombre);
//	printf("Apellido: %s\n", res->apellido);
//	printf("DNI: %s\n", res->dni);
//	printf("Tarjeta: %i\n", res->tarjeta);
//	printf("Fecha de Inicio: %s\n", res->datainicio);
//	printf("Fecha de Fin: %s\n", res->datafin);
//	printf("Precio: %.2f\n", res->precio);
//	printf("Matricula: %s\n", res->matricula);
//	printf("Plaza: %i\n", res->plaza);
//	fflush(stdout);
}

