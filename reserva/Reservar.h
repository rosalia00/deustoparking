#ifndef RESERVA_RESERVAR_H_
#define RESERVA_RESERVAR_H_

#include "../basedatos/Sqlite3.h"
#include "../persona/Usuario.h"
#include "Reserva.h"

Reserva reservacion(Usuario *u, sqlite3 *db);

#endif /* RESERVA_RESERVAR_H_ */
