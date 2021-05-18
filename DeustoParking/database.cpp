extern "C" {
#include "sqlite3.h"
#include "reserva.h"
}
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

static int callback(void *data, int argc, char **argv, char **azColName) {
	int i;
	fprintf(stderr, "%s: ", (const char*) data);

	for (i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}

	printf("\n");
	return 0;
}

int cuentaReservas(sqlite3 *db) {
	sqlite3_stmt *stmt;
	char *zErrMsg = 0;
	int rc;
	int numReserv = 0;

	int result = sqlite3_exec(db, "SELECT COUNT(*) FROM RESERVA", callback,
			&numReserv, &zErrMsg);
	if (result) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	} else {
		printf("count: %d\n", numReserv);
		return numReserv;
	}

	return numReserv;
}

void recogeReservas(Reserva*, sqlite3 *db) {

}

/* --- ADMINISTRAR BONOS --- */
int administrarBono(sqlite3 *db, float precio, int opcion) {

	sqlite3_stmt *stmt;

	char sql[] = "UPDATE BONO SET PRECIO = ? WHERE ID = ?";

	int resultado = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);
	if (resultado != SQLITE_OK) {
		cout << "Error preparando la declaración (UPDATE)" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}

	cout << "Consulta SQL preparada (UPDATE)" << endl;

	resultado = sqlite3_bind_double(stmt, 1, precio);
	if (resultado != SQLITE_OK) {
		cout << "Error uniendo el parametro precio" << endl
				<< sqlite3_errmsg(db);
		return resultado;
	}

	resultado = sqlite3_bind_int(stmt, 2, opcion);
	if (resultado != SQLITE_OK) {
		cout << "Error uniendo el parametro opción" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}

	cout << "Parametros insertados" << endl;

	resultado = sqlite3_step(stmt);
	if (resultado == SQLITE_OK) {
		cout << "Error actualizando los datos." << endl << sqlite3_errmsg(db)
				<< endl;
		return resultado;
	}

	cout << "Datos actualizados" << endl;

	resultado = sqlite3_finalize(stmt);
	if (resultado != SQLITE_OK) {
		cout << "Error terminando la declaracion (UPDATE)" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}

	cout << "La declaración preparada ha terminado (UPDATE)" << endl;

	return SQLITE_OK;
}

sqlite3 *db;
int rc = sqlite3_open("test.db", &db);
int a = cuentaReservas(db)

