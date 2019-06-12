#pragma once
#include "ObjetoMovil.h"
#include "Ficha.h"

class Esfera : public ObjetoMovil
{
	friend class Interaccion;
	friend class Mundo; //Necesario para la variable "especial"
public:
	Esfera();
	virtual ~Esfera();
	void dibuja();
	void setRadio(float r);
	void setPos(Ficha p){posicion.x = (p.limite1.x + p.limite2.x)/2;posicion.y = (((p.limite1.y + p.limite2.y)/2) + 0.51f);};
	
private:
	float radio;
	bool especial;
};


