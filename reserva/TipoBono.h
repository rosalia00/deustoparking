/*
 * TipoBono.h
 *
 *  Created on: 2 jun. 2021
 *      Author: Tyler de Mier
 */

#ifndef RESERVA_TIPOBONO_H_
#define RESERVA_TIPOBONO_H_

#include "../basedatos/Sqlite3.h"
#include "../persona/Usuario.h"

float tipoBono(sqlite3 *db, Usuario *u);


#endif /* RESERVA_TIPOBONO_H_ */
