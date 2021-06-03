/*
 * administrador.cpp
 *
 *  Created on: 1 jun. 2021
 *      Author: Tyler de Mier
 */
#include <iostream>
#include "Administrador.h"
using namespace std;

Administrador::Administrador(const char *dni, char *nombre, char *apellido,
		int telefono, int tarjeta, char *contrasenya, const int nss,
		float salario) :
		Persona(dni, nombre, apellido, telefono, tarjeta, contrasenya) {
	this->nss = nss;
	this->salario = salario;
}
Administrador::Administrador(const Administrador &a) :
		Persona(a) {
	this->nss = a.nss;
	this->salario = a.salario;
}
Administrador::Administrador() :
		Persona() {
	this->nss = 0;
	this->salario = 0.0;
}
Administrador::~Administrador() {
}

const int Administrador::getNss() {
	return this->nss;
}
float Administrador::getSalario() {
	return this->salario;
}

void Administrador::setNSS(int nss) {
	this->nss = nss;
}
void Administrador::setSalario(float salario) {
	this->salario = salario;
}
