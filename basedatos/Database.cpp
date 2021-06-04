#include "Database.h"

#include <iostream>
extern "C" {
#include "Sqlite3.h"
}
#include "../persona/Usuario.h"
#include "../persona/Administrador.h"
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
		cout << "Error preparando la declaración (SELECT)" << endl
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
		cout << "Error preparando la declaración (SELECT)" << endl
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
		cout << "Error preparando la declaración (SELECT)" << endl
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
		cout << "Error preparando la declaración (UPDATE)" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}

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

	resultado = sqlite3_step(stmt);
	if (resultado == SQLITE_OK) {
		cout << "Error actualizando los datos." << endl << sqlite3_errmsg(db)
				<< endl;
		return resultado;
	}

	resultado = sqlite3_finalize(stmt);
	if (resultado != SQLITE_OK) {
		cout << "Error terminando la declaracion (UPDATE)" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}

	return SQLITE_OK;
}

/* --- GUARDAR TICKET EN BASE DE DATOS --- */
int guardarTicket(sqlite3 *db, Reserva *res) {

	sqlite3_stmt *stmt;

	char sql[] =
			"INSERT INTO RESERVA (DNI, NOMBRE, APELLIDO, MATRICULA, FECHAI, FECHAF, PLAZA, TARJETA, PRECIO, BONO, HORAIN, HORAFIN) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

	int resultado = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);
	if (resultado != SQLITE_OK) {
		cout << "Error preparando la declaración (INSERT)" << endl
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
		cout << "Error preparando la declaración (SELECT)" << endl
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

int inicioSesion(sqlite3 *db, char *dni, Usuario *usuario) {
	sqlite3_stmt *stmt;
	char sql[] = "SELECT * FROM USUARIO WHERE DNI = ?";

	int resultado = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);
	if (resultado != SQLITE_OK) {
		cout << "Error preparando la declaración (SELECT)" << endl
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

	resultado = sqlite3_finalize(stmt);

	if (resultado != SQLITE_OK) {
		cout << "Error terminando la declaracion (SELECT)" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}

	return SQLITE_OK;
}

int inicioSesionAdmin(sqlite3 *db, char *dni, Administrador *admin) {
	sqlite3_stmt *stmt;
	char sql[] = "SELECT * FROM ADMINISTRADOR WHERE DNI = ?";

	int resultado = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);
	if (resultado != SQLITE_OK) {
		cout << "Error preparando la declaración (SELECT)" << endl
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
	int telefono;
	int tarjeta;
	int nss;
	float salario;

	do {
		resultado = sqlite3_step(stmt);
		if (resultado == SQLITE_ROW) {
			strcpy(dnito, (char*) sqlite3_column_text(stmt, 0));
			admin->setdni(dnito);

			strcpy(nombre, (char*) sqlite3_column_text(stmt, 1));
			admin->setNombre(nombre);

			strcpy(apellido, (char*) sqlite3_column_text(stmt, 2));
			admin->setApellido(apellido);

			telefono = sqlite3_column_int(stmt, 3);
			admin->setTelefono(telefono);

			tarjeta = sqlite3_column_int(stmt, 4);
			admin->setTarjeta(tarjeta);

			strcpy(contrasenya, (char*) sqlite3_column_text(stmt, 5));
			admin->setContrasenya(contrasenya);

			nss = sqlite3_column_int(stmt, 6);
			admin->setNSS(nss);

			salario = sqlite3_column_double(stmt, 4);
			admin->setSalario(salario);
		}
	} while (resultado == SQLITE_ROW);

	resultado = sqlite3_finalize(stmt);

	if (resultado != SQLITE_OK) {
		cout << "Error terminando la declaracion (SELECT)" << endl
				<< sqlite3_errmsg(db) << endl;
		return resultado;
	}
	return SQLITE_OK;
}

//Estadisticas
//Estadistica 1: Cantidad de bonos reservados de cada tipo
void bonosNum(sqlite3 *db, int idBonos) {
	int numBono;
	sqlite3_stmt *stmt;
	char sql[] = "SELECT COUNT(BONO) FROM RESERVA WHERE BONO=?;";

	int resultado = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);
	if (resultado != SQLITE_OK) {
		cout << "Error preparando la declaración (SELECT)" << endl
				<< sqlite3_errmsg(db) << endl;
	}

	resultado = sqlite3_bind_int(stmt, 1, idBonos);
	if (resultado != SQLITE_OK) {
		cout << "Error uniendo el parametro opción" << endl
				<< sqlite3_errmsg(db) << endl;
	}

	resultado = sqlite3_step(stmt);
	if (resultado == SQLITE_ROW) {
		if (idBonos == 1) {
			cout << "Bono Semanal: ";
		}
		if (idBonos == 2) {
			cout << "Bono Mensual: ";
		}
		if (idBonos == 3) {
			cout << "Bono Anual: ";
		}
		numBono = sqlite3_column_int(stmt, 0);
		cout << numBono << endl;
	}

	resultado = sqlite3_finalize(stmt);
	if (resultado != SQLITE_OK) {
		cout << "Error terminando la declaracion (SELECT)" << endl
				<< sqlite3_errmsg(db) << endl;
	}

}

//Estadistica 2: Horas más concurridas
void horasEntrada(sqlite3 *db, int hora1, int hora2) {
	//SELECT HORAIN, MAX(contador) FROM (SELECT HORAIN, COUNT(HORAIN) contador FROM RESERVA WHERE HORAIN BETWEEN ? AND ? GROUP BY HORAIN)
	int maxHora;
	int numHoras;
	sqlite3_stmt *stmt;
	char sql[] =
			"SELECT HORAIN, MAX(contador) FROM (SELECT HORAIN, COUNT(HORAIN) contador FROM RESERVA WHERE HORAIN BETWEEN ? AND ? GROUP BY HORAIN)";

	int resultado = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);
	if (resultado != SQLITE_OK) {
		cout << "Error preparando la declaración (SELECT)" << endl
				<< sqlite3_errmsg(db) << endl;
	}

	resultado = sqlite3_bind_int(stmt, 1, hora1);
	if (resultado != SQLITE_OK) {
		cout << "Error uniendo el parametro opción" << endl
				<< sqlite3_errmsg(db) << endl;
	}

	resultado = sqlite3_bind_int(stmt, 2, hora2);
	if (resultado != SQLITE_OK) {
		cout << "Error uniendo el parametro opción" << endl
				<< sqlite3_errmsg(db) << endl;
	}

	resultado = sqlite3_step(stmt);
	if (resultado == SQLITE_ROW) {
		cout << "Desde las " << hora1 << " hasta las " << hora2
				<< " la hora más concurrida es ";
		maxHora = sqlite3_column_int(stmt, 0);
		cout << maxHora << " con ";
		numHoras = sqlite3_column_int(stmt, 1);
		cout << numHoras << " horas reservadas." << endl;
	}

}

//Estadisticas 3: Numero de cada tipo de usuarios
void tipoUsuario(sqlite3 *db, char *tipo) {
	int numUsuarios;
	sqlite3_stmt *stmt;
	char sql[] = "SELECT COUNT(TIPO) FROM USUARIO WHERE TIPO=?";

	int resultado = sqlite3_prepare_v2(db, sql, strlen(sql), &stmt, NULL);
	if (resultado != SQLITE_OK) {
		cout << "Error preparando la declaración (SELECT)" << endl
				<< sqlite3_errmsg(db) << endl;
	}

	resultado = sqlite3_bind_text(stmt, 1, tipo, strlen(tipo),
	SQLITE_STATIC);
	if (resultado != SQLITE_OK) {
		cout << "Error uniendo el parametro dni" << endl << sqlite3_errmsg(db)
				<< endl;
	}

	resultado = sqlite3_step(stmt);
	if (resultado == SQLITE_ROW) {
		if (strcmp(tipo, (char*) "Estudiante") == 0) {
			cout << "Tipo Estudiante: ";
		}
		if (strcmp(tipo, (char*) "Profesor") == 0) {
			cout << "Tipo Profesor: ";
		}
		numUsuarios = sqlite3_column_int(stmt, 0);
		cout << numUsuarios << endl;
	}

	resultado = sqlite3_finalize(stmt);
	if (resultado != SQLITE_OK) {
		cout << "Error terminando la declaracion (SELECT)" << endl
				<< sqlite3_errmsg(db) << endl;
	}

}

//Estadistica 4: Plazas reservadas por cada piso
void reservasPisos(sqlite3 *db) {
	int cont1 = 0;
	int cont2 = 0;
	int cont3 = 0;
	int i;

	int tamanyoReserva = cuentaReservas(db);
	int *reservas = new int[tamanyoReserva];
	recogeReservas(reservas, db, tamanyoReserva);

	for (i = 0; i < tamanyoReserva; ++i) {
		if (reservas[i] >= 0 && reservas[i] <= 36) {
			cont1++;
		} else if (reservas[i] >= 37 && reservas[i] <= 72) {
			cont2++;
		} else {
			cont3++;
		}
	}

	cout << "Plazas reservadas en el Piso 1: " << cont1 << endl;
	cout << "Plazas reservadas en el Piso 2: " << cont2 << endl;
	cout << "Plazas reservadas en el Piso 3: " << cont3 << endl;
	delete[] reservas;
}
