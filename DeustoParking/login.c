#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "registrarse.h"

void loggearse() {
	char *dni; //Cuando pongamos * usamos malloc :) 10/10
	dni = (char*)malloc(10 * sizeof (char)); //reservamos 9 huekitos, ponerlo cuando lo stateemos

	int contrasenya;//en los ints NO hacemos malloc xd

	printf("\nIntroduzca su DNI: ");
	fflush(stdout);
	fgets(dni, 10, stdin);

	dni = quitadorContrabarraN(dni); //le pasamos dni para quitarle contrabarra a dni :$ Y SOLO CON CHARS

	printf("Introduzca su contrasenya: ");
	fflush(stdout);
	scanf("%i", &contrasenya); //el % identifica el TIPO pq c es retra | &usamos para acceder dentro de valor int

	printf("%s", dni);
	printf("%i", contrasenya);
}

