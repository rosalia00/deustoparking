/*
 * tipoBono.c
 *
 *  Created on: 6 abr. 2021
 *      Author: rosal
 */

#include <stdio.h>
#include "tipoBono.h"

float tipoBono(){
	int op=0;
	float tipoBono;
	char c;

	do{
	printf("\n TIPOS DE BONO: ");
	printf("\n 1. Bono Semanal Alumnado: 62.99 euros. ");
	printf("\n 2. Bono Semana Profesorado: 75.59 euros. ");
	printf("\n 3. Bono Mensual Alumnado: 209.99 euros. ");
	printf("\n 4. Bono Mensual Profesorado: 251.99 euros. ");
	printf("\n 5. Bono Anual Alumnado: 1641.99 euros. ");
	printf("\n 6. Bono Anual Profesorado: 1970.39 euros. ");
	printf("\n Elija tipo de Bono: ");
	scanf("%d", &op);
	switch (op)
		{
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
		printf("\n Opcion Erronea... Pulse una tecla. ");
		//Impide que continue hasta que pulse una tecla
		c = getchar();
		break;
		}
//Controla que sea un numero dentro del rango
	}while(op <=0 && op>=6);
}





