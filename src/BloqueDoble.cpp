#include "BloqueDoble.h"


BloqueDoble::BloqueDoble(void)
{
}


BloqueDoble::~BloqueDoble(void)
{

}

void BloqueDoble::dibuja() //Dibuja las 5 caras (salvo la trasera) de un cubo
{
	suelo.dibuja();
	techo.dibuja();
	pared_izq.dibuja();
	pared_dcha.dibuja();
	frontal.dibujaFrontalEspecial();

}
