#include "Caja.h"	
#include "Ficha.h"	
#include "Esfera.h"	
#include "Bloque.h"
#include "ListaBloques.h"
#include "Vidas.h"
#include "Puntos.h"
#include "ObjetoMovil.h"
class Mundo
{
	Esfera esfera;
	Ficha ficha;
	Caja caja;
	Bloque bloque; 
	ListaBloques bloques;
	Vidas vds;
	Puntos punto;
	ObjetoMovil objetomovil;

	int nivel;
	float x_ojo;
	float y_ojo;
	float z_ojo;
public: 
	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void inicializa();
	void inicializaV1();
	void inicializaV2();
	void inicializaV3();
	void rotarOjo();
	void mueve();
	void dibuja();
	~Mundo();
};
