#pragma once
#include "iostream"
using namespace std;

class Puntos
{
	friend class Coordinador;
	friend class Mundo;
	int Puntuacion;
	char npuntos[5];
public:
	Puntos(void);
	~Puntos(void);
	void setPuntos() {Puntuacion=0;}
	int getPuntos(){return Puntuacion;}
	char* getPuntosItoa(){_itoa_s((int)getPuntos(), npuntos, 10); return npuntos;}
	
	void imprimePuntos(){cout<<"Putuacion: "<<getPuntos()<<" Puntos"<<endl;}
	void incrementaPuntos() {Puntuacion+=10;}
};

