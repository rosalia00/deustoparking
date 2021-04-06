/*
 * tipoBono.c
 *
 *  Created on: 6 abr. 2021
 *      Author: rosal
 */

#include <stdio.h>

void tipoBono(){
	int op=0;
	float tipoBono;
	char c;

	do{
	printf("\n TIPOS DE BONO: ");
	printf("\n 1. Bono Semanal Alumnado: 62,99 €. ");
	printf("\n 2. Bono Semana Profesorado: 75,59 €. ");
	printf("\n 3. Bono Mensual Alumnado: 209,99 €. ");
	printf("\n 4. Bono Mensual Profesorado: 251,99 €. ");
	printf("\n 5. Bono Anual Alumnado: 1.641,99 €. ");
	printf("\n 6. Bono Anual Profesorado: 1970,39 € ");
	printf("\n Elija tipo de Bono: ");
	scanf("%d", &op);
	switch (op)
		{
	case 1:
		tipoBono = 62,99;
		return tipoBono;
		break;
	case 2:
		tipoBono = 75,59;
		return tipoBono;
		break;
	case 3:
		tipoBono = 62,99;
		return tipoBono;
		break;
	default:
		printf('\n Opci�n Err�nea... Pulse una tecla. ');
		c = getchar();

		break;
		} (op >=1 || op<=6)


	}while(op <=0 && op>=0);
}





