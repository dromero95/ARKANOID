#pragma once
#include "iostream"
using namespace std;

class Puntos
{
	int Puntuacion;
public:
	Puntos(void);
	~Puntos(void);
	void setPuntos() {Puntuacion=0;}
	int getPuntos(){return Puntuacion;}
	void imprimePuntos(){cout<<"Putuaci�n: "<<getPuntos()<<"Puntos"<<endl;}
	void incrementaPuntos() {Puntuacion+=10;}
};

