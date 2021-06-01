///*
// * tipoBono.cpp
// *
// *  Created on: 1 jun. 2021
// *      Author: Tyler de Mier
// */
//extern "C" {
//#include "../basedatos/Sqlite3.h"
//}
//#include "../basedatos/Database.h"
//#include <stdio.h>
//#include <conio.h>
//#include <string.h>
//#include "Reserva.h"
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
