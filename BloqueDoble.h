#pragma once
#include "Bloque.h"
#include "Planobloque.h"
#include "Esfera.h"

//Dani Hace un cambio


class BloqueDoble : public Bloque
{
	friend class Interaccion; 
public:
	BloqueDoble();
	~BloqueDoble();
};

