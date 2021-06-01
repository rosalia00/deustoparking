/*
 * InicioUsuario.h
 *
 *  Created on: 1 jun. 2021
 *      Author: Tyler de Mier
 */

#ifndef EXPUSUARIO_INICIOUSUARIO_H_
#define EXPUSUARIO_INICIOUSUARIO_H_

#include "../basedatos/Sqlite3.h"
#include "../persona/Usuario.h"

void cleanStdIn(char *str, int max_line);
void inicioUsuario(Usuario *u, sqlite3 *db);

#endif /* EXPUSUARIO_INICIOUSUARIO_H_ */
