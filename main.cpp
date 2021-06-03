/*
 * main.cpp
 *
 *  Created on: 1 jun. 2021
 *      Author: Tyler de Mier
 */
#include "iostream"
extern "C" {
#include "basedatos/Sqlite3.h"
}
#include "inicio.h"
using namespace std;

int main() {
	sqlite3 *db;

	int resultado = sqlite3_open("deustoparking_db.db", &db);
	if (resultado != SQLITE_OK) {
		cout << "Error abriendo la base de datos" << endl;
		return resultado;
	}
	char* tipo = (char*)"Usuario";
	inicio(db, tipo);

	return 0;
}


