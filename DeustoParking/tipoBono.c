#include <stdio.h>
#include <conio.h>
#include "reserva.h"

float tipoBono(){
	int op=0;
	float tipoBono;
	int c;

	do{
	printf("\n");
	printf("\n TIPOS DE BONO: ");
	printf("\n 1. Bono Semanal Alumnado: 62,99 Euros. ");
	printf("\n 2. Bono Semana Profesorado: 75,59 Euros. ");
	printf("\n 3. Bono Mensual Alumnado: 209,99 Euros. ");
	printf("\n 4. Bono Mensual Profesorado: 251,99 Euros. ");
	printf("\n 5. Bono Anual Alumnado: 1.641,99 Euros. ");
	printf("\n 6. Bono Anual Profesorado: 1.970,39 Euros. ");
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
		printf("\n Opcion Erronea. Debe elegir entre 1 - 6. Pulse una tecla para continuar... \n");
		//limpia teclado
		fflush(stdin);
		c = getch();
		break;
		}
	}while(op <=0 || op>=7);
}
