#include "Persona.h"
#include <string.h>
#include <iostream>
using namespace std;

Persona::Persona(const char *dni, char *nombre, char *apellido, int telefono,
		int tarjeta, char *contrasenya) {
	this->dni = new char[strlen(dni) + 1];
	strcpy(this->dni, dni);
	this->nombre = new char[strlen(nombre) + 1];
	strcpy(this->nombre, nombre);
	this->apellido = new char[strlen(apellido) + 1];
	strcpy(this->apellido, apellido);
	this->telefono = telefono;
	this->tarjeta = tarjeta;
	this->contrasenya = new char[strlen(contrasenya) + 1];
	strcpy(this->contrasenya, contrasenya);
}
Persona::Persona(const Persona &p) {
	this->dni = new char[strlen(p.dni) + 1];
	strcpy(this->dni, p.dni);
	this->nombre = new char[strlen(p.nombre) + 1];
	strcpy(this->nombre, p.nombre);
	this->apellido = new char[strlen(p.apellido) + 1];
	strcpy(this->apellido, p.apellido);
	this->telefono = p.telefono;
	this->tarjeta = p.tarjeta;
	this->contrasenya = new char[strlen(p.contrasenya) + 1];
	strcpy(this->contrasenya, p.contrasenya);
}
Persona::Persona() {
	this->dni = "";
	this->nombre = "";
	this->apellido = "";
	this->telefono = 0;
	this->tarjeta = 0;
	this->contrasenya = "";
}
Persona::~Persona() {
	delete[] dni;
	delete[] nombre;
	delete[] apellido;
	delete[] contrasenya;
}

const char* Persona::getdni() {
	return this->dni;
}
char* Persona::getNombre() {
	return this->nombre;
}
char* Persona::getApellido() {
	return this->apellido;
}
int Persona::getTelefono() {
	return this->telefono;
}
int Persona::getTarjeta() {
	return this->tarjeta;
}
char* Persona::getContrasenya() {
	return this->contrasenya;
}

void Persona::setdni(char *dni) {
	this->dni = dni;
}
void Persona::setNombre(char *nombre) {
	this->nombre = nombre;
}
void Persona::setApellido(char *apellido) {
	this->apellido = apellido;
}
void Persona::setTelefono(int telefono) {
	this->telefono = telefono;
}
void Persona::setTarjeta(int tarjeta) {
	this->tarjeta = tarjeta;
}
void Persona::setContrasenya(char *contrasenya) {
	this->contrasenya = contrasenya;
}

