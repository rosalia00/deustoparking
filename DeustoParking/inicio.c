#include <stdio.h>
#include "registrarse.h"

void inicio(void){
	printf("BIENVENIDO A DEUSTOPARKING \n ELIGE UNA OPCION: \n 1. INICIAR SESION \n "
			"2. REGISTRARSE \n INSERTE NUMERO: "); fflush(stdout);

	do {
		char c = getchar();
		if (c == '1'){
			printf("hola");
		} else if (c == '2') {
			registrarse();
		} else {
			printf("CARACTER INVALIDO INSERTE UNO NUEVO: ");fflush(stdout);
			c = getchar();
		}
	} while (0);

}
