#include "Coordinador.h"
#include <windows.h>
#include "Puntos.h"
Coordinador::Coordinador(void)
{
	estado=INICIO;
	ETSIDI::playMusica("musicas/industrial.mp3", true);
	
}


Coordinador::~Coordinador(void)
{
}

void Coordinador::dibuja()
{
	ETSIDI::setTextColor(1,1,0);
	ETSIDI::setFont("fuentes/Bitwise.ttf",16);
	ETSIDI::printxy("Arkanoid V.Final", -12, 16);

	if(estado==INICIO) //Cuando le das a empezar el juego
	{
		gluLookAt(0.0 , 7.5, 30.0, 0.0, 7.5, 0.0, 0.0, 1.0, 0.0);
		ETSIDI::setTextColor(1,0,0);
		ETSIDI::setFont("fuentes/Bitwise.ttf",16);
		ETSIDI::printxy("Arkanoid V.Final", -5, 8);
		ETSIDI::setTextColor(1,1,1);
		ETSIDI::setFont("fuentes/Bitwise.ttf",12);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR A JUGAR", -10, 7);
		ETSIDI::printxy("PULSE LA TECLA -S PARA SALIR", -10, 6);
		ETSIDI::printxy("Francisco Munoz", -17, 1);
		ETSIDI::printxy("Dani Romero", -2, 1);
		ETSIDI::printxy("David Navas", 13, 1);
	}
	else if (estado==JUEGO) //Cuando se te acaban las vidas
	{
		ETSIDI::setTextColor(1,0,0);
		ETSIDI::setFont("fuentes/Bitwise.ttf",12);
		ETSIDI::printxy("Puntuacion: ", 0, 16);
		mundo.punto.getPuntosItoa();
		ETSIDI::setTextColor(1,1,1);
		ETSIDI::setFont("fuentes/Bitwise.ttf",12);
		ETSIDI::printxy(mundo.punto.npuntos , 4, 16);
		mundo.vds.getVidasItoa();
		ETSIDI::setTextColor(1,0,0);
		ETSIDI::setFont("fuentes/Bitwise.ttf",12);
		ETSIDI::printxy("Vidas: ", 10, 16);

		ETSIDI::setTextColor(1,1,1);
		ETSIDI::setFont("fuentes/Bitwise.ttf",12);
		ETSIDI::printxy(mundo.vds.nvidas , 12, 16);
		mundo.dibuja();
	}
	else if (estado==GAMEOVER) //Cuando se te acaban las vidas y pulsas c para continuar
	{
		ETSIDI::setTextColor(1,0,0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("GAMEOVER: Te has quedado sin vidas", -5, 5);
		ETSIDI::printxy("Pulsa -c- para continuar", -5, 4);
		ETSIDI::setTextColor(1,0,0);
		ETSIDI::setFont("fuentes/Bitwise.ttf",16);
		ETSIDI::printxy("Puntuacion final: ", -5, 5);
		mundo.punto.getPuntosItoa();
		ETSIDI::setTextColor(1,1,1);
		ETSIDI::setFont("fuentes/Bitwise.ttf",16);
		ETSIDI::printxy(mundo.punto.npuntos , 1, 5);
		mundo.dibuja();
	}
	else if (estado==FIN) //Cuando superas los 3 niveles y y pulsas c para continuar
	{
		ETSIDI::setTextColor(1,0,0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("ENHORABUENA, HAS GANADO.", -5,5);
		ETSIDI::printxy("Pulsa -c- para continuar", -5, 4);
		mundo.dibuja();
	}
	else if (estado==PAUSA)
	{
		ETSIDI::setTextColor(1,0,0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("PAUSA, NO TARDES!", -5,5);
		ETSIDI::printxy("Pulsa -c- para continuar", -5, 4);
		mundo.dibuja();
	}
	else if (estado==NIVEL1)
	{
		ETSIDI::setTextColor(1,0,0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("PRIMER NIVEL SUPERADO!", -5,5);
		ETSIDI::printxy("Pulsa -c- para continuar", -5, 4);
		mundo.dibuja();
	}
	else if (estado==NIVEL2)
	{
		ETSIDI::setTextColor(1,0,0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("SEGUNDO NIVEL SUPERADO!", -5,5);
		ETSIDI::printxy("Pulsa -c- para continuar", -5, 4);
		mundo.dibuja();
	}
}

void Coordinador::tecla(unsigned char key)
{
	if (estado==INICIO)
	{
		if(key=='e')
		{
			mundo.bloques.destruirContenido();
			mundo.inicializa();
			estado=JUEGO;
		}
		if (key=='s')
			exit(0);
	}
	else 
		if (estado==JUEGO)
		{
			mundo.tecla(key);
			if(key=='p')
			{
				estado=PAUSA;
			}
		}
	else if (estado==GAMEOVER)
	{
		if(key=='c')
		{
			estado=INICIO;
		}
	}
	else if (estado==FIN)
	{
		if(key=='c')
		{
			estado=INICIO;
		}
	}
	else if (estado==PAUSA)
	{
		if (key=='c')
		{
			estado=JUEGO;
		}
	}
	else if (estado==NIVEL1)
	{
		if(key=='c')
		{
			estado=JUEGO;
		}
	}
	else if (estado==NIVEL2)
	{
		if(key=='c')
		{
			estado=JUEGO;
		}
	}
}

void Coordinador::teclaEspecial(unsigned char key)
{
	if (estado==JUEGO)
		mundo.teclaEspecial(key);
}

void Coordinador::mueve()
{
	if (estado==JUEGO)
	{
		mundo.mueve();
		if (mundo.bloques.lista[0]==00000000 && mundo.nivel==1)
		{
			estado=NIVEL1;
			mundo.inicializaV2();
		}
		if (mundo.bloques.lista[0]==00000000 && mundo.nivel==2)
		{
			estado=NIVEL2;
			mundo.inicializaV3();
		}
		if (mundo.bloques.lista[0]==00000000 && mundo.nivel==3)
		{
			ETSIDI::playMusica("musicas/victoria.mp3", false);
			estado=FIN;
			mundo.finDelJuego();
		}
		if (mundo.vds.getVidas()==0)
		{
			ETSIDI::playMusica("musicas/fail2.mp3", false);
			estado=GAMEOVER;
		}
	}

}