#pragma once

#include "Vector2D.h"
#include "ColorRGB.h"
#include "ObjetoPlano.h"
class Pared : public ObjetoPlano
{
	friend class Interaccion;
public:
	Pared();
	virtual ~Pared();
	void dibuja();
};
