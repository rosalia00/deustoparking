/*
 * administrador.h
 *
 *  Created on: 1 jun. 2021
 *      Author: Tyler de Mier
 */

#ifndef PERSONA_ADMINISTRADOR_H_
#define PERSONA_ADMINISTRADOR_H_

#include "Persona.h"

class Administrador: public Persona {
	int nss;
	float salario;

public:
	Administrador(const char *dni, char *nombre, char *apellido, int telefono,
			int tarjeta, char *contrasenya, const int nss, float salario);
	Administrador(const Administrador &a);
	Administrador();
	virtual ~Administrador();

	const int getNss();
	float getSalario();

	void setNSS(int nss);
	void setSalario(float salario);
};

#endif /* PERSONA_ADMINISTRADOR_H_ */
