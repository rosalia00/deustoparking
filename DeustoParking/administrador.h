#ifndef ADMINISTRADOR_H_
#define ADMINISTRADOR_H_

#include "persona.h"

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

#endif /* ADMINISTRADOR_H_ */
