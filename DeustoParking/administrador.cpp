#include "administrador.h"
#include <iostream>
using namespace std;

Administrador::Administrador(const char *dni, char *nombre, char *apellido,
		int telefono, int tarjeta, char *contrasenya, const int nss,
		float salario) :
		Persona(dni, nombre, apellido, telefono, tarjeta, contrasenya) {

	cout << endl << "Guardando el administrador..." << endl;
	this->nss = nss;
	this->salario = salario;
}
Administrador::Administrador(const Administrador &a) :
		Persona(a) {

	cout << endl << "Copiando el administrador..." << endl;
	this->nss = a.nss;
	this->salario = a.salario;
}
Administrador::~Administrador() {
	cout << endl << "Destruyendo el administrador..." << endl;
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
