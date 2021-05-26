extern "C" {
#include "sqlite3.h"
#include "reserva.h"
}
#include "usuario.h"
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

void recogeReservas(Reserva *res, sqlite3 *db) {

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

/* --- GUARDAR TICKET EN BASE DE DATOS --- */
int guardarTicket(sqlite3 *db, Reserva *res) {

	sqlite3_stmt *stmt;

	char sql[] =
			"INSERT INTO RESERVA (MATRICULA, FECHAI, FECHAF, PLAZA, DNI, NOMBRE, APELLIDO, TARJETA, PRECIO) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)";

	int resultado = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);
	if (resultado != SQLITE_OK) {
		cout << "Error preparando la declaración (INSERT)" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}

	resultado = sqlite3_bind_text(stmt, 1, res->dni, strlen(res->dni),
	SQLITE_STATIC);
	if (resultado != SQLITE_OK) {
		cout << "Error uniendo el parametro dni" << endl << sqlite3_errmsg(db)
				<< endl;
		return resultado;
	}

	resultado = sqlite3_bind_text(stmt, 2, res->nombre, strlen(res->nombre),
	SQLITE_STATIC);
	if (resultado != SQLITE_OK) {
		cout << "Error uniendo el parametro nombre" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}

	resultado = sqlite3_bind_text(stmt, 3, res->apellido, strlen(res->apellido),
	SQLITE_STATIC);
	if (resultado != SQLITE_OK) {
		cout << "Error uniendo el parametro apellido" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}

	resultado = sqlite3_bind_text(stmt, 4, res->matricula,
			strlen(res->matricula), SQLITE_STATIC);
	if (resultado != SQLITE_OK) {
		cout << "Error uniendo el parametro matricula" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}

	resultado = sqlite3_bind_text(stmt, 5, res->datainicio,
			strlen(res->datainicio), SQLITE_STATIC);
	if (resultado != SQLITE_OK) {
		cout << "Error uniendo el parametro fecha inicio" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}

	resultado = sqlite3_bind_text(stmt, 6, res->datafin, strlen(res->datafin),
	SQLITE_STATIC);
	if (resultado != SQLITE_OK) {
		cout << "Error uniendo el parametro fecha fin" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}

	resultado = sqlite3_bind_int(stmt, 7, res->plaza);
	if (resultado != SQLITE_OK) {
		cout << "Error uniendo el parametro plaza" << endl << sqlite3_errmsg(db)
				<< endl;
		return resultado;
	}

	resultado = sqlite3_bind_int(stmt, 8, res->tarjeta);
	if (resultado != SQLITE_OK) {
		cout << "Error uniendo el parametro tarjeta" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}

	resultado = sqlite3_bind_double(stmt, 9, res->precio);
	if (resultado != SQLITE_OK) {
		cout << "Error uniendo el parametro precio" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}

	resultado = sqlite3_step(stmt);
	if (resultado == SQLITE_OK) {
		cout << "Error insertar los datos." << endl << sqlite3_errmsg(db)
				<< endl;
		return resultado;
	}

	resultado = sqlite3_finalize(stmt);
	if (resultado != SQLITE_OK) {
		cout << "Error terminando la declaracion (INSERT)" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}

	return SQLITE_OK;
}

/* --- GUARDAR USUARIOS EN LA BASE DE DATOS AL REGISTRAR --- */
int baseDatosUsuarioRegistrar(sqlite3 *db, Usuario *u) {

	sqlite3_stmt *stmt;

	char sql[] =
			"INSERT INTO USUARIO (DNI, NOMBRE, APELLIDO, TELEFONO, TARJETA, CONTRASENYA, TIPO, MATRICULA) VALUES (?, ?, ?, ?, ?, ?, ?, ?)";

	int resultado = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);
	if (resultado != SQLITE_OK) {
		cout << "Error preparando la declaración (INSERT)" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}

	resultado = sqlite3_bind_text(stmt, 1, u->getdni(), strlen(u->getdni()),
	SQLITE_STATIC);
	if (resultado != SQLITE_OK) {
		cout << "Error uniendo el parametro dni" << endl << sqlite3_errmsg(db)
				<< endl;
		return resultado;
	}
	resultado = sqlite3_bind_text(stmt, 2, u->getNombre(),
			strlen(u->getNombre()),
			SQLITE_STATIC);
	if (resultado != SQLITE_OK) {
		cout << "Error uniendo el parametro nombre" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}
	resultado = sqlite3_bind_text(stmt, 3, u->getApellido(),
			strlen(u->getApellido()),
			SQLITE_STATIC);
	if (resultado != SQLITE_OK) {
		cout << "Error uniendo el parametro apellido" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}
	resultado = sqlite3_bind_int(stmt, 4, u->getTelefono());
	if (resultado != SQLITE_OK) {
		cout << "Error uniendo el parametro telefono" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}
	resultado = sqlite3_bind_int(stmt, 5, u->getTarjeta());
	if (resultado != SQLITE_OK) {
		cout << "Error uniendo el parametro tarjeta" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}
	resultado = sqlite3_bind_text(stmt, 6, u->getContrasenya(),
			strlen(u->getContrasenya()), SQLITE_STATIC);
	if (resultado != SQLITE_OK) {
		cout << "Error uniendo el parametro contranseya" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}
	resultado = sqlite3_bind_text(stmt, 7, u->getTipo(), strlen(u->getTipo()),
	SQLITE_STATIC);
	if (resultado != SQLITE_OK) {
		cout << "Error uniendo el parametro tipo" << endl << sqlite3_errmsg(db)
				<< endl;
		return resultado;
	}
	resultado = sqlite3_bind_text(stmt, 8, u->getMatricula(),
			strlen(u->getMatricula()), SQLITE_STATIC);
	if (resultado != SQLITE_OK) {
		cout << "Error uniendo el parametro matricula" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}

	resultado = sqlite3_step(stmt);
	if (resultado == SQLITE_OK) {
		cout << "Error insertar los datos." << endl << sqlite3_errmsg(db)
				<< endl;
		return resultado;
	}

	resultado = sqlite3_finalize(stmt);
	if (resultado != SQLITE_OK) {
		cout << "Error terminando la declaracion (INSERT)" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}

	return SQLITE_OK;
}
//sqlite3 *db;
//int rc = sqlite3_open("test.db", &db);
//int a = cuentaReservas(db)

