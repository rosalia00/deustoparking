
#ifndef USUARIO_H_
#define USUARIO_H_

#include "persona.h"

class Usuario: public Persona {
	char *tipo;
	char *matricula;

public:
	Usuario(const char *dni, char *nombre, char *apellido, int telefono,
			int tarjeta, char *contrasenya, char *tipo, char *matricula);
	Usuario(const Usuario &u);
	virtual ~Usuario();

	char* getTipo();
	char* getMatricula();

	void setTipo(char *tipo);
	void setMatricula(char *matricula);
};

#endif /* USUARIO_H_ */
