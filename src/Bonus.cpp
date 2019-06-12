#include "Bonus.h"
#include <stdlib.h>
#include "ETSIDI.h"
#include "glut.h"

Bonus::Bonus()
{
	aceleracion.y = -9.8f; //movimiento gravitatorio
	//velocidad.y = 0; //velocidad vertical inicial
	//lado = 0.7f;
}


Bonus::~Bonus()
{

}

void Bonus::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/bonus.png").id);
	glDisable(GL_LIGHTING);
	//color.ponColor(); //Es de ColorRGB
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
		glTexCoord2d(0.0,1.0); glVertex3d(0,lado,0.3);
		glTexCoord2d(1.0,1.0); glVertex3d(lado,lado,0.3);
		glTexCoord2d(1.0,0.0); glVertex3d(lado,0,0.3);
		glTexCoord2d(0.0,0.0); glVertex3d(0,0,0.3);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

