#include "Planobloque.h"
#include "ETSIDI.h"
#include "glut.h"

Planobloque::Planobloque(void)
{
}

Planobloque::~Planobloque(void)
{
}

void Planobloque::dibuja() //Dibuja los planos que pueden chocar con las bolas. No dibuja el frontal
{
	glDisable(GL_LIGHTING);
	color.ponColor(); //Es de ColorRGB
	glBegin(GL_POLYGON);
		glVertex3d(limite1.x,limite1.y,0.3);
		glVertex3d(limite2.x,limite2.y,0.3);
		glVertex3d(limite2.x,limite2.y,-0.3);
		glVertex3d(limite1.x,limite1.y,-0.3);
	glEnd();
	glEnable(GL_LIGHTING);
}

void Planobloque::dibujaFrontal()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/bloque.png").id);
	
	glDisable(GL_LIGHTING);
	//color.ponColor(); //Es de ColorRGB
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
		glTexCoord2d(0.0,1.0); glVertex3d(limite1.x,limite1.y,0.3);
		glTexCoord2d(1.0,1.0); glVertex3d(limite1.x,limite2.y,0.3);
		glTexCoord2d(1.0,0.0); glVertex3d(limite2.x,limite2.y,0.3);
		glTexCoord2d(0.0,0.0); glVertex3d(limite2.x,limite1.y,0.3);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void Planobloque::dibujaFrontalEspecial()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/bloqueespecial.png").id);
	
	glDisable(GL_LIGHTING);
	//color.ponColor(); //Es de ColorRGB
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
		glTexCoord2d(0.0,1.0); glVertex3d(limite1.x,limite1.y,0.3);
		glTexCoord2d(1.0,1.0); glVertex3d(limite1.x,limite2.y,0.3);
		glTexCoord2d(1.0,0.0); glVertex3d(limite2.x,limite2.y,0.3);
		glTexCoord2d(0.0,0.0); glVertex3d(limite2.x,limite1.y,0.3);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

