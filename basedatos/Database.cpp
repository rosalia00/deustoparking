
#include <iostream>
#include "Sqlite3.h"
#include "../persona/Usuario.h"
#include "../reserva/Reserva.h"
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

int cuentaReservas(sqlite3 *db) {
	float numReserv;
	sqlite3_stmt *stmt;

	char sql[] = "SELECT COUNT(*) FROM RESERVA";

	int resultado = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);
	if (resultado != SQLITE_OK) {
		cout << "Error preparando la declaraci�n (SELECT)" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}

	resultado = sqlite3_step(stmt);
	if (resultado == SQLITE_ROW) {
		numReserv = sqlite3_column_double(stmt, 0);
	}

	resultado = sqlite3_finalize(stmt);
	if (resultado != SQLITE_OK) {
		cout << "Error terminando la declaracion (SELECT)" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}

	return numReserv;
}

void recogeReservas(int *listaNum, sqlite3 *db, int tamanyo) {
	sqlite3_stmt *stmt;

	char sql[] = "SELECT * FROM RESERVA";

	int resultado = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);
	if (resultado != SQLITE_OK) {
		cout << "Error preparando la declaraci�n (SELECT)" << endl
				<< sqlite3_errmsg(db) << endl;
	}

	int i = 0;
	do {
		resultado = sqlite3_step(stmt);
		if (resultado == SQLITE_ROW) {
			listaNum[i] = sqlite3_column_double(stmt, 6);
		}
		i++;
	} while (resultado == SQLITE_ROW);

	resultado = sqlite3_finalize(stmt);
	if (resultado != SQLITE_OK) {
		cout << "Error terminando la declaracion (SELECT)" << endl
				<< sqlite3_errmsg(db) << endl;
	}
}

/* RECOGER RESERVAS DE USUARIOS*/
void printReservas(sqlite3 *db, Usuario *u) {
	sqlite3_stmt *stmt;

	char sql[] =
			"SELECT FECHAI, FECHAF, PLAZA, HORAIN, HORAFIN FROM RESERVA WHERE DNI = ?";

	int resultado = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);
	if (resultado != SQLITE_OK) {
		cout << "Error preparando la declaraci�n (SELECT)" << endl
				<< sqlite3_errmsg(db) << endl;
	}

	resultado = sqlite3_bind_text(stmt, 1, u->dni, strlen(u->dni),
	SQLITE_STATIC);
	if (resultado != SQLITE_OK) {
		cout << "Error uniendo el parametro dni" << endl << sqlite3_errmsg(db)
				<< endl;
	}

	char *fechai = new char[100];
	char *fechaf = new char[100];
	int plaza;
	char *horain = new char[100];
	char *horafin = new char[100];
	int num = 1;

	do {
		resultado = sqlite3_step(stmt);
		if (resultado == SQLITE_ROW) {
			strcpy(fechai, (char*) sqlite3_column_text(stmt, 0));
			strcpy(fechaf, (char*) sqlite3_column_text(stmt, 1));
			plaza = sqlite3_column_int(stmt, 2);
			strcpy(horain, (char*) sqlite3_column_text(stmt, 3));
			strcpy(horafin, (char*) sqlite3_column_text(stmt, 4));
			cout << endl << "RESERVA " << num << ":" << endl << "Fecha inicio: "
					<< fechai << endl << "Fecha fin: " << fechaf << endl
					<< "Plaza: " << plaza << endl << "Hora de inicio: "
					<< horain << endl << "Hora de fin: " << horafin << endl;
			++num;
		}
	} while (resultado == SQLITE_ROW);

	resultado = sqlite3_finalize(stmt);
	if (resultado != SQLITE_OK) {
		cout << "Error terminando la declaracion (SELECT)" << endl
				<< sqlite3_errmsg(db) << endl;
	}

}

/* --- ADMINISTRAR BONOS --- */
int administrarBono(sqlite3 *db, float precio, int opcion) {

	sqlite3_stmt *stmt;

	char sql[] = "UPDATE BONO SET PRECIO = ? WHERE ID = ?";

	int resultado = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);
	if (resultado != SQLITE_OK) {
		cout << "Error preparando la declaraci�n (UPDATE)" << endl
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
		cout << "Error uniendo el parametro opci�n" << endl
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

	cout << "La declaraci�n preparada ha terminado (UPDATE)" << endl;

	return SQLITE_OK;
}

/* --- GUARDAR TICKET EN BASE DE DATOS --- */
int guardarTicket(sqlite3 *db, Reserva *res) {

	sqlite3_stmt *stmt;

	char sql[] =
			"INSERT INTO RESERVA (DNI, NOMBRE, APELLIDO, MATRICULA, FECHAI, FECHAF, PLAZA, TARJETA, PRECIO, BONO, HORAIN, HORAFIN) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

	int resultado = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);
	if (resultado != SQLITE_OK) {
		cout << "Error preparando la declaraci�n (INSERT)" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}

	resultado = sqlite3_bind_text(stmt, 1, res->getDni(), strlen(res->getDni()),
	SQLITE_STATIC);
	if (resultado != SQLITE_OK) {
		cout << "Error uniendo el parametro dni" << endl << sqlite3_errmsg(db)
				<< endl;
		return resultado;
	}

	resultado = sqlite3_bind_text(stmt, 2, res->getNombre(),
			strlen(res->getNombre()),
			SQLITE_STATIC);
	if (resultado != SQLITE_OK) {
		cout << "Error uniendo el parametro nombre" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}

	resultado = sqlite3_bind_text(stmt, 3, res->getApellido(),
			strlen(res->getApellido()),
			SQLITE_STATIC);
	if (resultado != SQLITE_OK) {
		cout << "Error uniendo el parametro apellido" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}

	resultado = sqlite3_bind_text(stmt, 4, res->getMatricula(),
			strlen(res->getMatricula()),
			SQLITE_STATIC);
	if (resultado != SQLITE_OK) {
		cout << "Error uniendo el parametro matricula" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}

	resultado = sqlite3_bind_text(stmt, 5, res->getDatainicio(),
			strlen(res->datainicio),
			SQLITE_STATIC);
	if (resultado != SQLITE_OK) {
		cout << "Error uniendo el parametro fecha inicio" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}

	resultado = sqlite3_bind_text(stmt, 6, res->getDatafin(),
			strlen(res->getDatafin()),
			SQLITE_STATIC);
	if (resultado != SQLITE_OK) {
		cout << "Error uniendo el parametro fecha fin" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}

	resultado = sqlite3_bind_int(stmt, 7, res->getPlaza());
	if (resultado != SQLITE_OK) {
		cout << "Error uniendo el parametro plaza" << endl << sqlite3_errmsg(db)
				<< endl;
		return resultado;
	}

	resultado = sqlite3_bind_int(stmt, 8, res->getTarjeta());
	if (resultado != SQLITE_OK) {
		cout << "Error uniendo el parametro tarjeta" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}

	resultado = sqlite3_bind_double(stmt, 9, res->getPrecio());
	if (resultado != SQLITE_OK) {
		cout << "Error uniendo el parametro precio" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}

	resultado = sqlite3_bind_int(stmt, 10, res->getBono());
	if (resultado != SQLITE_OK) {
		cout << "Error uniendo el parametro precio" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}

	resultado = sqlite3_bind_int(stmt, 11, res->getHorainicio());
	if (resultado != SQLITE_OK) {
		cout << "Error uniendo el parametro precio" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}

	resultado = sqlite3_bind_int(stmt, 12, res->getHorafinal());
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

/* --- RECOGER EL PRECIO DE LOS BONOS --- */
float recogerPrecioBono(sqlite3 *db, int num) {
	float precio;
	sqlite3_stmt *stmt;

	char sql[] = "SELECT PRECIO FROM BONO WHERE ID=?";

	int resultado = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);
	if (resultado != SQLITE_OK) {
		cout << "Error preparando la declaraci�n (SELECT)" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}

	resultado = sqlite3_bind_int(stmt, 1, num);
	if (resultado != SQLITE_OK) {
		cout << "Error uniendo el parametro id" << endl << sqlite3_errmsg(db)
				<< endl;
		return resultado;
	}

	do {
		resultado = sqlite3_step(stmt);
		if (resultado == SQLITE_ROW) {
			precio = sqlite3_column_double(stmt, 0);
		}
	} while (resultado == SQLITE_ROW);

	resultado = sqlite3_finalize(stmt);
	if (resultado != SQLITE_OK) {
		cout << "Error terminando la declaracion (SELECT)" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}

	return precio;
}

/* --- GUARDAR USUARIOS EN LA BASE DE DATOS AL REGISTRAR --- */
int baseDatosUsuarioRegistrar(sqlite3 *db, Usuario *u) {

	sqlite3_stmt *stmt;

	char sql[] =
			"INSERT INTO USUARIO (DNI, NOMBRE, APELLIDO, TELEFONO, TARJETA, CONTRASENYA, TIPO, MATRICULA) VALUES (?, ?, ?, ?, ?, ?, ?, ?)";

	int resultado = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);
	if (resultado != SQLITE_OK) {
		cout << "Error preparando la declaraci�n (INSERT)" << endl
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

int inicioSesion(sqlite3 *db, char *dni, Usuario *usuario) {
	sqlite3_stmt *stmt;
	char sql[] = "SELECT * FROM USUARIO WHERE DNI = ?";

	int resultado = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);
	if (resultado != SQLITE_OK) {
		cout << "Error preparando la declaraci�n (SELECT)" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}

	resultado = sqlite3_bind_text(stmt, 1, dni, strlen(dni), SQLITE_STATIC);
	if (resultado != SQLITE_OK) {
		cout << "Error uniendo el parametro id" << endl << sqlite3_errmsg(db)
				<< endl;
		return resultado;
	}

	char *nombre = new char[100];
	char *apellido = new char[100];
	char *contrasenya = new char[100];
	char *dnito = new char[100];
	char *matricula = new char[100];
	int tarjeta;
	char *tipo = new char[100];
	int telefono;

	do {
		resultado = sqlite3_step(stmt);
		if (resultado == SQLITE_ROW) {
			strcpy(dnito, (char*) sqlite3_column_text(stmt, 0));
			usuario->setdni(dnito);

			strcpy(nombre, (char*) sqlite3_column_text(stmt, 1));
			usuario->setNombre(nombre);

			strcpy(apellido, (char*) sqlite3_column_text(stmt, 2));
			usuario->setApellido(apellido);

			telefono = sqlite3_column_int(stmt, 3);
			usuario->setTelefono(telefono);

			tarjeta = sqlite3_column_int(stmt, 4);
			usuario->setTarjeta(tarjeta);

			strcpy(contrasenya, (char*) sqlite3_column_text(stmt, 5));
			usuario->setContrasenya(contrasenya);

			strcpy(tipo, (char*) sqlite3_column_text(stmt, 6));
			usuario->setTipo(tipo);

			strcpy(matricula, (char*) sqlite3_column_text(stmt, 7));
			usuario->setMatricula(matricula);
		}
	} while (resultado == SQLITE_ROW);
//
//	resultado = sqlite3_step(stmt);
//	if (resultado == SQLITE_ROW) {
//		usuario->apellido =
//				new char[sizeof((char*) sqlite3_column_text(stmt, 2)) + 1];
//		usuario->contrasenya = new char[sizeof((char*) sqlite3_column_text(stmt,
//				5)) + 1];
//		usuario->dni =
//				new char[sizeof((char*) sqlite3_column_text(stmt, 0)) + 1];
//		usuario->matricula = new char[sizeof((char*) sqlite3_column_text(stmt,
//				7)) + 1];
//		usuario->nombre = new char[sizeof((char*) sqlite3_column_text(stmt, 1))
//				+ 1];
//		usuario->tarjeta = 0;
//		usuario->tipo = new char[sizeof((char*) sqlite3_column_text(stmt, 6))
//				+ 1];
//		usuario->telefono = 0;
//
//		usuario->setdni((char*) sqlite3_column_text(stmt, 0));
//		usuario->setNombre((char*) sqlite3_column_text(stmt, 1));
//		usuario->setApellido((char*) sqlite3_column_text(stmt, 2));
//		usuario->telefono = sqlite3_column_int(stmt, 3);
//		usuario->tarjeta = sqlite3_column_int(stmt, 4);
//		usuario->setContrasenya((char*) sqlite3_column_text(stmt, 5));
//		usuario->setTipo((char*) sqlite3_column_text(stmt, 6));
//		usuario->setMatricula((char*) sqlite3_column_text(stmt, 7));
//	}

	resultado = sqlite3_finalize(stmt);

	if (resultado != SQLITE_OK) {
		cout << "Error terminando la declaracion (SELECT)" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}

	return SQLITE_OK;
}
