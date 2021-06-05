#ifndef RESERVA_TIPOBONO_H_
#define RESERVA_TIPOBONO_H_

#include "../basedatos/Sqlite3.h"
#include "../persona/Usuario.h"
#include "Reserva.h"

void tipoBono(sqlite3 *db, Usuario *u, Reserva *res);

#endif /* RESERVA_TIPOBONO_H_ */
