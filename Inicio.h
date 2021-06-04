#include "iostream"
extern "C" {
#include "basedatos/Sqlite3.h"
}
#include "persona/Usuario.h"
#include "expUsuario/InicioUsuario.h"
#include "expUsuario/Login.h"
#include "expAdmin/LoginAdmin.h"
#include "expUsuario/Registrar.h"
#include <windows.h>
#include <stdio.h>
#include <ctype.h>
using namespace std;

#ifndef INICIO_H_
#define INICIO_H_

#include "basedatos/Sqlite3.h"

void inicio(sqlite3 *db, char *tipo);
void admin(sqlite3 *db, char *tipo);

#endif /* INICIO_H_ */
