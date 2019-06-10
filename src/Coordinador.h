#pragma once
#include "Mundo.h"
#include "ETSIDI.h"

class Coordinador
{
public:
	Coordinador(void);
	virtual ~Coordinador(void);

	void teclaEspecial(unsigned char key);
	void tecla (unsigned char key);
	void mueve();
	void dibuja();

protected:
	Mundo mundo;
	enum Estado {INICIO, JUEGO, GAMEOVER, FIN, PAUSA,NIVEL1, NIVEL2};
	Estado estado;
};

