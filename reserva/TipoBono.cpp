/*
 * tipoBono.cpp
 *
 *  Created on: 1 jun. 2021
 *      Author: Tyler de Mier
 */

#include <stdio.h>
#include <conio.h>
#include "Reserva.h"

float tipoBono() {
	int op = 0;
	float tipoBono;
	int c = 0;

	do {
		printf("\nTIPOS DE BONO: ");
		printf("\n1. Bono Semanal Alumnado: 62,99 Euros. ");
		printf("\n2. Bono Semana Profesorado: 75,59 Euros. ");
		printf("\n3. Bono Mensual Alumnado: 209,99 Euros. ");
		printf("\n4. Bono Mensual Profesorado: 251,99 Euros. ");
		printf("\n5. Bono Anual Alumnado: 1.641,99 Euros. ");
		printf("\n6. Bono Anual Profesorado: 1.970,39 Euros. ");
		printf("\nElija tipo de Bono: ");
		fflush(stdout);
		scanf("%d", &op);
		switch (op) {
		case 1:
			tipoBono = 62.99;
			return tipoBono;
			break;
		case 2:
			tipoBono = 75.59;
			return tipoBono;
			break;
		case 3:
			tipoBono = 209.99;
			return tipoBono;
			break;
		case 4:
			tipoBono = 251.99;
			return tipoBono;
			break;
		case 5:
			tipoBono = 1641.99;
			return tipoBono;
			break;
		case 6:
			tipoBono = 1970.39;
			return tipoBono;
			break;
		default:
			printf(
					"\nOpcion Erronea. Debe elegir entre 1 - 6. Pulse una tecla para continuar... \n");
			//limpia teclado
			fflush(stdin);
			c = getch();
			break;
		}
	} while (op <= 0 || op >= 7);
}
