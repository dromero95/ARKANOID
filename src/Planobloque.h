#pragma once
#include "ObjetoPlano.h"

class Planobloque:public ObjetoPlano
{
	friend class Bonus;
	friend class Interaccion;
public:
	Planobloque();
	virtual ~Planobloque();
	void dibuja();
	void dibujaFrontal();
	void dibujaFrontalEspecial();
};

