
#pragma once
#include "ObjetoMovil.h"
class Ficha : public ObjetoMovil
{
	friend class Interaccion;
	friend class Esfera;
public:
	void dibuja();
	Ficha();
	virtual ~Ficha();
	float distancia(Vector2D punto, Vector2D *direccion);//para rebote
	void setPos(float x1, float y1, float x2, float y2);//para rebote

private:
	float altura;
	Vector2D limite1;
	Vector2D limite2;
};

