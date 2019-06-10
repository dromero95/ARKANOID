#pragma once
#include "Planobloque.h"
#include "Esfera.h"

class Bloque
{
	friend class Interaccion; 
	friend class Mundo;
protected:
	Planobloque suelo;
	Planobloque techo;
	Planobloque pared_izq;
	Planobloque pared_dcha;
	Planobloque frontal;
public:
	Bloque(); //Constructor de bloques
	virtual ~Bloque(); //Destructor virtual de bloques
	virtual void dibuja();
	bool rebota (Esfera &e); //rebote con la esfera

};


