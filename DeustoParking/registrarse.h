/*
 * registrarse.h
 *
 *  Created on: 02/04/2021
 *      Author: evaho
 */

#ifndef REGISTRARSE_H_
#define REGISTRARSE_H_

typedef struct {
	char *nombre;
	char *apellido;
	char *dni;
	int telefono;
	int numTarj;
	int contrasenya;
} Persona;

void registrarse (void);

#endif /* REGISTRARSE_H_ */
