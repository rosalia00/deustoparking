/*
 * usuario.cpp
 *
 *  Created on: 1 jun. 2021
 *      Author: Tyler de Mier
 */
#include <iostream>
#include <string.h>
#include "Usuario.h"
using namespace std;

Usuario::Usuario(const char *dni, char *nombre, char *apellido, int telefono,
		int tarjeta, char *contrasenya, char *tipo, char *matricula) :
		Persona(dni, nombre, apellido, telefono, tarjeta, contrasenya) {

	cout << endl << "Guardando el usuario..." << endl;
	this->tipo = new char[strlen(tipo) + 1];
	strcpy(this->tipo, tipo);
	this->matricula = new char[strlen(matricula) + 1];
	strcpy(this->matricula, matricula);
}

Usuario::Usuario(const Usuario &u) :
		Persona(u) {
	this->tipo = u.tipo;
	this->matricula = u.matricula;

}

Usuario::Usuario() :
		Persona() {
	this->tipo = "";
	this->matricula = "";
}

Usuario::~Usuario() {
	delete[] tipo;
	delete[] matricula;
}

char* Usuario::getTipo() {
	return this->tipo;
}

char* Usuario::getMatricula() {
	return this->matricula;
}

void Usuario::setTipo(char *tipo) {
	this->tipo = tipo;
}

void Usuario::setMatricula(char *matricula) {
	this->matricula = matricula;
}
