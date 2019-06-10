#include "Bonus.h"
#include <stdlib.h>
#include "glut.h"

Bonus::Bonus()
{
	aceleracion.y = -9.8f; //movimiento gravitatorio
	velocidad.y = 0; //velocidad vertical inicial
	lado = 0.7f;
}

Bonus::~Bonus()
{

}

void Bonus::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3ub(200, 0, 0);
	glutSolidCube(lado);
	glPopMatrix();
}

void Bonus::mueve(float t)
{
	posicion=posicion+velocidad*t+aceleracion*(0.5f*t*t);
	velocidad=velocidad+aceleracion*t;
}

