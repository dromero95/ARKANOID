#include "ObjetoMovil.h"


ObjetoMovil::ObjetoMovil(void)
{
}


ObjetoMovil::~ObjetoMovil(void)
{
}

void ObjetoMovil::mueve(float t) //Movimiento de la ficha
{
	posicion=posicion+velocidad*t+aceleracion*(0.5f*t*t);
	velocidad=velocidad+aceleracion*t;
}

void ObjetoMovil::setPos(float ix,float iy) //Posición 
{
	posicion.x=ix;
	posicion.y=iy;
}

void ObjetoMovil::setVel(float vx, float vy) //Velocidad
{
	velocidad.x=vx;
	velocidad.y=vy;
}

void ObjetoMovil::setColor( Byte r,Byte v, Byte a) //Color de la esfera
{
	color.set(r,v,a);
}