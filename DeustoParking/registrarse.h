#ifndef REGISTRARSE_H_
#define REGISTRARSE_H_

typedef struct {
	char *nombre;
	char *apellido;
	char *dni;
	int telefono;
	int numTarj;
	int contrasenya;
} Usuario;

void registrarse();
char* quitadorContrabarraN(char *s);

#endif
