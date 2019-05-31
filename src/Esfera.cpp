#include "Esfera.h"
#include "glut.h"
#include "Interaccion.h"

Esfera::Esfera() //Constructor por defecto de la esfera	
{
}

Esfera::~Esfera() //Destructor por defecto de la esfera
{
}

void Esfera::dibuja() //Dibujo de la esfera
{
	color.ponColor();
	glTranslatef(posicion.x,posicion.y,0);
	glutSolidSphere(radio,90,90);
	glTranslatef(-posicion.x,-posicion.y,0);
}


void Esfera::setRadio(float r) //Radio
{
	radio=r;
}	

