/*
 * ticket.cpp
 *
 *  Created on: 1 jun. 2021
 *      Author: Tyler de Mier
 */
extern "C" {
#include "../basedatos/Sqlite3.h"
}
#include "../basedatos/Database.h"
#include "Reserva.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

void ticket(Reserva *res, sqlite3 *db) {
	cout<<"entra";

//	ofstream freserva("ticket.dat");
//
//	freserva << "Nombre: , " << res->nombre;
//	freserva << "Apellido: , " << res->apellido;
//	freserva << "DNI: , " << res->dni;
//	freserva << "Tarjeta: , " << res->tarjeta;
//	freserva << "Fecha de Inicio: , " << res->datainicio;
//	freserva << "Fecha de Fin: , " << res->datafin;
//	freserva << "Precio: , " << res->precio;
//	freserva << "Matricula: , " << res->matricula;
//	freserva << "Plaza: , " << res->plaza;
//
//	freserva.close();

	guardarTicket(db, res);

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
