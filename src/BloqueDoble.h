#pragma once
#include "Bloque.h"
#include "Planobloque.h"
#include "Esfera.h"
class BloqueDoble : public Bloque
{
	friend class Interaccion; 
public:
	BloqueDoble();
	~BloqueDoble();
	virtual void dibuja();
};

