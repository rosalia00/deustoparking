#include <iostream>
extern "C" {
#include "../basedatos/Sqlite3.h"
}
#include "../basedatos/Database.h"
#include "../persona/Usuario.h"
#include "../reserva/Reservar.h"
#include "Mapa.h"
using namespace std;

#ifndef EXPUSUARIO_INICIOUSUARIO_H_
#define EXPUSUARIO_INICIOUSUARIO_H_

#include "../basedatos/Sqlite3.h"
#include "../persona/Usuario.h"


void inicioUsuario(Usuario *u, sqlite3 *db);

#endif /* EXPUSUARIO_INICIOUSUARIO_H_ */
