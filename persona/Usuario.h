/*
 * usuario.h
 *
 *  Created on: 1 jun. 2021
 *      Author: Tyler de Mier
 */

#ifndef PERSONA_USUARIO_H_
#define PERSONA_USUARIO_H_

#include "Persona.h"

class Usuario: public Persona {
public:
	char *tipo;
	char *matricula;

public:
	Usuario(const char *dni, char *nombre, char *apellido, int telefono,
			int tarjeta, char *contrasenya, char *tipo, char *matricula);
	Usuario(const Usuario &u);
	Usuario();
	virtual ~Usuario();

	char* getTipo();
	char* getMatricula();

	void setTipo(char *tipo);
	void setMatricula(char *matricula);
};

#endif /* PERSONA_USUARIO_H_ */
