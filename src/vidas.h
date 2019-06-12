#pragma once
#include "iostream"
#include <stdlib.h>
using namespace std;
class Vidas
{
	friend class Coordinador;
	int numvidas;
	char nvidas[2];
public:
	Vidas(void);
	~Vidas(void);
	void setVidas(int numerovidas) {numvidas=numerovidas;}
	int getVidas(){return numvidas;}
	char* getVidasItoa(){_itoa_s((int)getVidas(), nvidas, 10); return nvidas;}
	void decrementaVidas() 
	{
		numvidas--;
		cout<< "Has perdido una vida. Te quedan: " <<getVidas()<< " de 5 iniciales." << endl;
	}
};

