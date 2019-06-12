#include "ObjetoPlano.h"

ObjetoPlano::ObjetoPlano(void)
{
}


ObjetoPlano::~ObjetoPlano(void)
{
}

void ObjetoPlano::setColor( Byte r,Byte v, Byte a)
{
	color.set(r,v,a);
}

void ObjetoPlano::setPos(float x1, float y1, float x2, float y2) //Los puntos de referencia para crear los planos
{
	limite1.x=x1;
	limite1.y=y1;
	limite2.x=x2;
	limite2.y=y2;
}

float ObjetoPlano::distancia(Vector2D punto, Vector2D *direccion) //No tocar, funciona
{
	Vector2D u=(punto-limite1);
	Vector2D v=(limite2-limite1).unitario();
	float longitud=(limite1-limite2).modulo();
	Vector2D dir;
	float valor=u*v;
	float distancia=0;

	if(valor<0)
		dir=u;
	else if(valor>longitud)
		dir=(punto-limite2);
	else
		dir=u-v*valor;
	distancia=dir.modulo();
	if(direccion!=0)
		*direccion=dir.unitario();
	return distancia;
}

