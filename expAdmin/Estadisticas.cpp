#include "Estadisticas.h"
#include "InicioAdmin.h"
#include "../persona/Administrador.h"
#include "iostream"
extern "C" {
#include "../basedatos/Sqlite3.h"
}
#include "../basedatos/Database.h"
using namespace std;

void menuEstadisticas(sqlite3 *db, Administrador *a) {
	int opcion;
	int opcion1;
	int hora1;
	int hora2;
	char *tipo1=(char*)"Estudiante";
	char *tipo2=(char*)"Profesor";

	cout << "---Bienvenido al menu de Estadisticas---" << endl;
	cout << "1. Cantidad de bonos reservados de cada tipo. " << endl;
	cout << "2. Horas más concurridas. " << endl;
	cout << "3. Número de cada tipo de usuarios. " << endl;
	cout << "4. Plazas reservadas por cada tipo. " << endl << endl;
	cout << "5. Volver. " << endl;

	do {
		cout << "Seleccione la estadistica que desea ver: ";
		cin >> opcion;
	} while (opcion < 1 || opcion > 5);

	switch (opcion) {
	case 1:
		bonosNum(db, 1);
		bonosNum(db, 2);
		bonosNum(db, 3);
		break;
	case 2:
		cout << "Indique el intervalo de horas que desea ver: " << endl;
		cout << "- Primera hora: ";
		cin >> hora1;
		cout << "- Segunda hora: ";
		cin >> hora2;
		horasEntrada(db, hora1, hora2);
		break;
	case 3:
		tipoUsuario(db, tipo1);
		tipoUsuario(db, tipo2);
		break;
	case 4:
		reservasPisos(db);
		break;
	case 5:
		inicioAdmin(a, db);
		break;
	default:
		break;
	}

	cout << "1. Volver al menu principal de Administrador. " << endl;
	cout << "2. Volver al menu de Estadísticas. " << endl << endl;
	do {
		cout << "Seleccione la opción: ";
		cin >> opcion1;
	} while (opcion1 < 1 || opcion1 > 2);
	switch (opcion1) {
	case 1:
		inicioAdmin(a, db);
		break;
	case 2:
		menuEstadisticas(db, a);
		break;
	}
}
