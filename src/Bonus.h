#pragma once

#include "Vector2D.h"
#include "ColorRGB.h"
#include "Planobloque.h"
#include "ObjetoMovil.h"
class Bonus:public ObjetoMovil
{
	friend class Interaccion;
public:
	void dibuja();
	void setVel(float v){velocidad.y=v;}
	void setLado(float l){lado=l;}
	void setPos(Planobloque p){	posicion.x = (p.limite1.x + p.limite2.x)/2;posicion.y = (p.limite1.y + p.limite2.y)/2;};
	Bonus();
	~Bonus();
private:
	float lado;
};
