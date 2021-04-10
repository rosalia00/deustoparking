#include <stdio.h>
#include <stdlib.h>
#include "reserva.h"
#include "registrarse.h"
#include "tipoBono.h"
#include <string.h>
#include <conio.h>
#include "inicio.h"
#include <windows.h>

Reserva reservacion(Usuario u) {

	Reserva res;

	char *matricula = (char*) malloc(7 * sizeof(char));
	int plaza = 0;
	int horaI = 0;
	int horaF = 0;
	int fid = 0;
	int fim = 0;
	int fia = 0;
	int ffd = 0;
	int ffm = 0;
	int ffa = 0;

	int eleccion;
	int c;

	printf("MATRICULA: ");
	fflush(stdout);
	fgets(matricula, 20, stdin);
	matricula = quitadorContrabarraN(matricula);

	printf("PLAZA: ");
	fflush(stdout);
	scanf("%i", &plaza);

	printf("HORA INICIO: ");
	fflush(stdout);
	scanf("%i", &horaI);

	printf("HORA FINAL: ");
	fflush(stdout);
	scanf("%i", &horaF);

	printf("FECHA INICIO DIA: ");
	fflush(stdout);
	scanf("%i", &fid);

	printf("FECHA INICIO MES: ");
	fflush(stdout);
	scanf("%i", &fim);

	printf("FECHA INICIO ANYO: ");
	fflush(stdout);
	scanf("%i", &fia);

	char datainFinal[11];
	char datain1[3];
	char datain2[3];
	char datain3[5];

	itoa(fid, datain1, 10);
	itoa(fim, datain2, 10);
	itoa(fia, datain3, 10);

	strcpy(datainFinal, datain1);
	strcat(datainFinal, "-");
	strcat(datainFinal, datain2);
	strcat(datainFinal, "-");
	strcat(datainFinal, datain3);

	printf("FECHA FIN DIA: ");
	fflush(stdout);
	scanf("%i", &ffd);

	printf("FECHA FIN MES: ");
	fflush(stdout);
	scanf("%i", &ffm);

	printf("FECHA FIN ANYO: ");
	fflush(stdout);
	scanf("%i", &ffa);

	char datafinFinal[11];
	char datafin1[3];
	char datafin2[3];
	char datafin3[5];

	itoa(ffd, datafin1, 10);
	itoa(ffm, datafin2, 10);
	itoa(ffa, datafin3, 10);

	strcpy(datafinFinal, datafin1);
	strcat(datafinFinal, "-");
	strcat(datafinFinal, datafin2);
	strcat(datafinFinal, "-");
	strcat(datafinFinal, datafin3);

	res.apellido = u.apellido;
	res.datafin = datafinFinal;
	res.datainicio = datainFinal;
	res.dni = u.dni;
	res.matricula = matricula;
	res.nombre = u.nombre;
	res.plaza = plaza;
	res.precio = tipoBono();
	res.tarjeta = u.numTarj;
	system("cls");
	do {
		printf("\n");
		printf("\n1. Imprimir ticket.\n2. Volver a inicio.\n");
		printf("\nElija opcion:  ");
		fflush(stdout);
		scanf("%i", &eleccion);
		fflush(stdin);
		switch (eleccion) {
		case 1:
			ticket(&res);
			printf("\nPulse una tecla para volver al menu principal");
			fflush(stdout);
			fflush(stdin);
			c = getch();
			inicio();
			break;
		case 2:
			fflush(stdin);
			inicio();
			break;
		default:
			printf("CARACTER INVALIDO. INSERTE UNO NUEVO: ");
			fflush(stdout);
			fflush(stdin);
			c = getch();
			break;
		}
	} while (eleccion <= 0 || eleccion >= 3);

	return res;
}

