#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"

class ObjetoMovil
{
	friend class Mundo;
	friend class Interaccion;
protected:
	Vector2D posicion;
	Vector2D velocidad;	
	Vector2D aceleracion;
	ColorRGB color;
public:
	ObjetoMovil(void);
	~ObjetoMovil(void);
	void mueve(float t);
	void setPos(float ix,float iy);
	void setVel(float vx, float vy);
	void setColor( Byte r,Byte v, Byte a);
};

