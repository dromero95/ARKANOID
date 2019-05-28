#pragma once
#include "iostream"
using namespace std;
class Vidas
{
	int numvidas;
public:
	Vidas(void);
	~Vidas(void);
	void setVidas(int numerovidas) {numvidas=numerovidas;}
	int getVidas(){return numvidas;}
	void decrementaVidas() 
	{
		numvidas--;
		cout<< "Has perdido una vida. Te quedan: " <<getVidas()<< " de 5 iniciales." << endl;
	}
};

