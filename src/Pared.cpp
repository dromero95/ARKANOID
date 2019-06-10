#include "Pared.h"
#include "ETSIDI.h"
#include "glut.h"

Pared::Pared() //Constructor por defecto de la pared
{
}

Pared::~Pared() //Destructor por defecto de la pared
{
}

void Pared::dibuja()
{
	glEnable(GL_TEXTURE_2D);
  
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/borde.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1,1,1);
		glTexCoord2d(1.0,0.0); glVertex3d(limite1.x,limite1.y,1.3);
		glTexCoord2d(1.0,1.0); glVertex3d(limite2.x,limite2.y,1.3);
		glTexCoord2d(0.0,1.0); glVertex3d(limite2.x,limite2.y,-1.3);
		glTexCoord2d(0.0,0.0); glVertex3d(limite1.x,limite1.y,-1.3);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void Pared::setColor( Byte r,Byte v, Byte a)
{
	color.set(r,v,a);
}

void Pared::setPos(float x1, float y1, float x2, float y2)
{
	limite1.x=x1;
	limite1.y=y1;
	limite2.x=x2;
	limite2.y=y2;
}

float Pared::distancia(Vector2D punto, Vector2D *direccion) //No tocar, funciona
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


