#pragma once

#include "Vector2D.h"
#include "ColorRGB.h"
#include "Planobloque.h"

class Bonus
{
	friend class Interaccion;
public:
	void mueve(float t);
	void dibuja();
	void setVel(float v){velocidad.y=v;}
	void setPos(Planobloque p){	posicion.x = (p.limite1.x + p.limite2.x)/2;posicion.y = (p.limite1.y + p.limite2.y)/2;};
	Bonus();
	virtual ~Bonus();
private:
	float lado;
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;

};
