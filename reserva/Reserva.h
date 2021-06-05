#ifndef RESERVA_RESERVA_H_
#define RESERVA_RESERVA_H_

class Reserva {
public:
	const char *dni;
	char *nombre;
	char *apellido;
	int tarjeta;
	int horainicio;
	int horafinal;
	char *datainicio;
	char *datafin;
	float precio;
	int bono;
	char *matricula;
	int plaza;

public:
	Reserva();

	const char* getDni();
	char* getNombre();
	char* getApellido();
	int getTarjeta();
	int getHorainicio();
	int getHorafinal();
	char* getDatainicio();
	char* getDatafin();
	float getPrecio();
	int getBono();
	char* getMatricula();
	int getPlaza();

	void setDni(const char *dni);
	void setNombre(char *nombre);
	void setApellido(char *apellido);
	void setTarjeta(int tarjeta);
	void setHorainicio(int horainicio);
	void setHorafin(int horafin);
	void setDatainicio(char *datainicio);
	void setDatafin(char *datafin);
	void setPrecio(float precio);
	void setBono(int bono);
	void setMatricula(char *matricula);
	void setPlaza(int plaza);

};

#endif /* RESERVA_RESERVA_H_ */
