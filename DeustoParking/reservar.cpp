extern "C" {
#include "sqlite3.h"
}
#include "usuario.h"
#include "reserva.h"
#include "tipoBono.h"
#include "inicioUsuario.h"
#include <cstring>
#include <iostream>
using namespace std;

Reserva reservacion(Usuario *u, sqlite3 *db) {

	Reserva res;

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

	res.apellido = u->getApellido();
	res.datafin = datafinFinal;
	res.datainicio = datainFinal;
	res.dni = u->getdni();
	res.nombre = u->getNombre();
	res.plaza = plaza;
	res.precio = tipoBono();
	fflush(stdin);
	res.tarjeta = u->getTarjeta();
	system("cls");
	do {
		printf(
				"\n1. Guardar e imprimir ticket.\n2. Cancelar y volver a inicio.\n");
		printf("\nElija opcion: ");
		fflush(stdout);
		scanf("%i", &eleccion);
		switch (eleccion) {
		case 1:
			fflush(stdout);
			ticket(&res, db);
			printf("\nPulse una tecla para volver al menu principal... ");
			fflush(stdout);
			cin >> c;
			inicioUsuario(u, db);
			break;
		case 2:
			fflush(stdin);
			inicioUsuario(u, db);
			break;
		default:
			printf("CARACTER INVALIDO. INSERTE UNO NUEVO: ");
			fflush(stdout);
			fflush(stdin);
			cin >> c;
			break;
		}
	} while (eleccion <= 0 || eleccion >= 3);

	return res;
}

