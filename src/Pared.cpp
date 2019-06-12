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
