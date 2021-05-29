#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <bits/stdc++.h>
#include "database.h"
#include "inicioUsuario.h"
extern "C" {
#include "sqlite3.h"
}
using namespace std;

bool checkReserva(int plaza, sqlite3 *db) {
	bool esCierto = false;
	int tamanyoReserva = cuentaReservas(db);
	int *reservas = new int[tamanyoReserva];
	recogeReservas(reservas, db, tamanyoReserva);
	int var;
	for (var = 0; var < tamanyoReserva; ++var) {
		if (reservas[var] == plaza) {
			esCierto = true;
			return esCierto;
		}
	}
	return esCierto;
}

void printMapa(int piso, sqlite3 *db) {
	vector<string> map;

	map.push_back("  ===============================");
	map.push_back("// [ ][ ][ ][ ][ ][ ]");
	map.push_back("<-");
	map.push_back("|| [ ][ ][ ][ ][ ][ ]");
	map.push_back("|| [ ][ ][ ][ ][ ][ ]");
	map.push_back("||  ->");
	map.push_back("|| [ ][ ][ ][ ][ ][ ]");
	map.push_back("|| [ ][ ][ ][ ][ ][ ]");
	map.push_back("||                            <-");
	map.push_back("\\\\ [ ][ ][ ][ ][ ][ ]");
	map.push_back("  ===============================");
	int plaza;
	if (piso == 1) {
		plaza = 0;
	} else if (piso == 2) {
		plaza = 37;
	} else if (piso == 3) {
		plaza = 73;
	}

	int numPlaza[36];

	int y;
	for (y = 0; y < 36; ++y) {
		numPlaza[y] = plaza;
		plaza++;
	}
	string prev;
	string post;
	string num;
	string result;
	int iteradorNumPlaza = 0;
	unsigned int var;
	for (var = 0; var < 11; ++var) {
		result.clear();
		if (var == 0 || var == 2 || var == 5 || var == 8 || var == 10) {

			result = map[var];
		} else {
			unsigned int x;
			for (x = 0; x != map[var].length(); ++x) {
				if (map[var][x] == '[' && map[var][x + 2] == ']') {
					if (checkReserva(numPlaza[iteradorNumPlaza], db) == true) {
						prev = map[var].substr(0, x + 1);
						post = map[var].substr(x + 2);

						map[var] = prev + "X" + post;
						result = prev + "X" + post;
					} else {
						prev = map[var].substr(0, x + 1);
						post = map[var].substr(x + 2);
						num = to_string(numPlaza[iteradorNumPlaza]);

						map[var] = prev + num + post;
						result = prev + num + post;
					}
					iteradorNumPlaza++;
				}
			}
		}
		cout << map[var] << endl;
	}
	cout << "X marca una parcela ocupada" << endl;
}
void ventanaMapa(int piso, sqlite3 *db, Usuario *u) {
	char opcion;
	int pisoNuevo = piso;
	printMapa(piso, db);
	cout << "s - subir piso" << endl << "b- bajar piso" << endl << "v - volver"
			<< endl << "Se encuentra usted en la planta " << piso
			<< " inserte un caracter para seleccionar una accion: ";
	cin >> opcion;
	if (opcion == 's' && piso != 3) {
		pisoNuevo++;
		ventanaMapa(pisoNuevo, db, u);
	} else if (opcion == 'b' && piso != 1) {
		pisoNuevo--;
		ventanaMapa(pisoNuevo, db, u);
	} else if (opcion == 's' && piso == 3) {
		cout << "Se encuentra en el último piso, por favor intentelo de nuevo"
				<< endl;
		ventanaMapa(pisoNuevo, db, u);
	} else if (opcion == 'b' && piso == 1) {
		cout << "Se encuentra en el primer piso, por favor intentelo de nuevo"
				<< endl;
		ventanaMapa(pisoNuevo, db, u);
	} else if(opcion == 'v'){
		inicioUsuario(u, db);
	} else {
		cout << "Carácter invalido" << endl;
		ventanaMapa(pisoNuevo, db, u);
	}
}
