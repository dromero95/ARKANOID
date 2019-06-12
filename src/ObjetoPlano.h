#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
class ObjetoPlano
{
protected:
	Vector2D limite1;
	Vector2D limite2;
	ColorRGB color;
public:
	ObjetoPlano(void);
	virtual ~ObjetoPlano(void);
	virtual void setColor(Byte r,Byte v, Byte a);
	virtual void setPos(float x1, float y1, float x2, float y2);
	virtual float distancia(Vector2D punto, Vector2D *direccion);
};

