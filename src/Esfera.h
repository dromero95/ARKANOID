#pragma once
#include "ObjetoMovil.h"
class Esfera : public ObjetoMovil
{
	friend class Interaccion;
	friend class Mundo; //Necesario para la variable "especial"
public:
	Esfera();
	virtual ~Esfera();
	void dibuja();
	void setRadio(float r);
private:
	float radio;
	bool especial;
};


