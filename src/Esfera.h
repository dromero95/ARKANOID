#pragma once
#include "ObjetoMovil.h"
class Esfera : public ObjetoMovil
{
	friend class Interaccion;
public:
	Esfera();
	virtual ~Esfera();
	void dibuja();
	void setRadio(float r);
private:
	float radio;

};


