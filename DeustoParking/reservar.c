#include <stdio.h>
#include <stdlib.h>

void escribir(char *matricula, char *plaza, int horaI, int horaF, int fid,
		int fim, int fia, int ffd, int ffm, int ffa);

void reservar() {

	char *matricula = malloc(sizeof(char));
	char *plaza = malloc(sizeof(char));
	int horaI = 0;
	int horaF = 0;
	int fid = 0;
	int fim = 0;
	int fia = 0;
	int ffd = 0;
	int ffm = 0;
	int ffa = 0;

	int eleccion;

	printf("MATRICULA: ");
	fflush(stdout);
	scanf("%c", matricula);

	printf("PLAZA: ");
	fflush(stdout);
	scanf("%c%*c", plaza);

	printf("HORA INICIO: ");
	fflush(stdout);
	scanf("%c%*c", &horaI);

	printf("HORA FINAL: ");
	fflush(stdout);
	scanf("%i", &horaF);

	printf("FECHA INICIO DIA: ");
	fflush(stdout);
	scanf("%i", &fid);

	printf("FECHA INICIO MES: ");
	fflush(stdout);
	scanf("%i", &fim);

	printf("FECHA INICIO AÑO: ");
	fflush(stdout);
	scanf("%i", &fia);

	printf("FECHA FIN DIA: ");
	fflush(stdout);
	scanf("%i", &ffd);

	printf("FECHA FIN MES: ");
	fflush(stdout);
	scanf("%i", &ffm);

	printf("FECHA FIN AÑO: ");
	fflush(stdout);
	scanf("%i", &ffa);

	printf("\n");
	printf("1. Finalizar.\n2. Cancelar.\n");
	fflush(stdout);
	scanf("%i", &eleccion);

	if (eleccion == 1) {
		escribir(matricula, plaza, horaI, horaF, fid, fim, fia, ffd, ffm, ffa);
	} else if (eleccion == 2) {
		printf("SALIR");
	} else {
		printf("CARACTER INVALIDO INSERTE UNO NUEVO: ");
		fflush(stdout);
		scanf("%i", &eleccion);
	}
}

void escribir(char *matricula, char *plaza, int horaI, int horaF, int fid,
		int fim, int fia, int ffd, int ffm, int ffa) {
	FILE *f;
	f = fopen("reserva.txt", "w");

	if (f == NULL) {
		printf("Error abriendo archivo %s", "reserva.txt");
	}

	fprintf(f, "MATRICULA: %c;", *matricula);
	fprintf(f, "PLAZA: %c;", *plaza);
	fprintf(f, "HORA INICIO: %i;", horaI);
	fprintf(f, "HORA FINAL: %i;", horaF);
	fprintf(f, "INICIO: %i-", fid);
	fprintf(f, "%i-", fim);
	fprintf(f, "%i;", fia);
	fprintf(f, "FINAL: %i-", ffd);
	fprintf(f, "%i-", ffm);
	fprintf(f, "%i.\n", ffa);

	fclose(f);
}

