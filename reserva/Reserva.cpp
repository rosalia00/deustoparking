/*
 * Reserva.cpp
 *
 *  Created on: 3 jun. 2021
 *      Author: Tyler de Mier
 */

#include <iostream>
#include "Reserva.h"
using namespace std;

Reserva::Reserva() {
	this->nombre = '\0';
	this->apellido = '\0';
	this->bono = 0;
	this->datafin = '\0';
	this->datainicio = '\0';
	this->dni = '\0';
	this->horainicio = 0;
	this->horafinal = 0;
	this->matricula = '\0';
	this->plaza = '\0';
	this->precio = 0.0;
	this->tarjeta = 0;
}

const char* Reserva::getDni() {
	return this->dni;
}

char* Reserva::getNombre() {
	return this->nombre;
}

char* Reserva::getApellido() {
	return this->apellido;
}

int Reserva::getTarjeta() {
	return this->tarjeta;
}

int Reserva::getHorainicio() {
	return this->horainicio;
}

int Reserva::getHorafinal() {
	return this->horafinal;
}

char* Reserva::getDatainicio() {
	return this->datainicio;
}

char* Reserva::getDatafin() {
	return this->datafin;
}

float Reserva::getPrecio() {
	return this->precio;
}

int Reserva::getBono() {
	return this->bono;
}

char* Reserva::getMatricula() {
	return this->matricula;
}

int Reserva::getPlaza() {
	return this->plaza;
}

void Reserva::setDni(const char *dni) {
	this->dni = dni;
}

void Reserva::setNombre(char *nombre) {
	this->nombre = nombre;
}

void Reserva::setApellido(char *apellido) {
	this->apellido = apellido;
}

void Reserva::setTarjeta(int tarjeta) {
	this->tarjeta = tarjeta;
}

void Reserva::setHorainicio(int horainicio) {
	this->horainicio = horainicio;
}

void Reserva::setHorafin(int horafin) {
	this->horafinal = horafin;
}

void Reserva::setDatainicio(char *datainicio) {
	this->datainicio = datainicio;
}

void Reserva::setDatafin(char *datafin) {
	this->datafin = datafin;
}

void Reserva::setPrecio(float precio) {
	this->precio = precio;
}

void Reserva::setBono(int bono) {
	this->bono = bono;
}

void Reserva::setMatricula(char *matricula) {
	this->matricula = matricula;
}

void Reserva::setPlaza(int plaza) {
	this->plaza = plaza;
}

