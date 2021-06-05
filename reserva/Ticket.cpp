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

	cout << endl << "------ DATOS DE LA RESERVA ------" << endl;
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
	cout << "------ ----- -- -- ------- ------" << endl;

}

