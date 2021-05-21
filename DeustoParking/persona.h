#ifndef PERSONA_H_
#define PERSONA_H_

class Persona {
private:
	char *dni;
	char *nombre;
	char *apellido;
	int telefono;
	int tarjeta;
	char *contrasenya;

public:
	Persona(const char *dni, char *nombre, char *apellido, int telefono,
			int tarjeta, char *contrasenya);
	Persona(const Persona &p);
	virtual ~Persona();

	const char* getdni();
	char* getNombre();
	char* getApellido();
	int getTelefono();
	int getTarjeta();
	char* getContrasenya();

	void setdni(char *dni);
	void setNombre(char *nombre);
	void setApellido(char *apellido);
	void setTelefono(int telefono);
	void setTarjeta(int tarjeta);
	void setContrasenya(char *contrasenya);
};

#endif
