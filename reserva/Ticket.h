/*
 * Ticket.h
 *
 *  Created on: 1 jun. 2021
 *      Author: Tyler de Mier
 */

#ifndef RESERVA_TICKET_H_
#define RESERVA_TICKET_H_

#include "../basedatos/Sqlite3.h"
#include "Reserva.h"

void ticket(Reserva *res, sqlite3 *db);

#endif /* RESERVA_TICKET_H_ */
