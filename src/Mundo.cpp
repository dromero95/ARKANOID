#include "Mundo.h"
#include "glut.h"
#include <math.h>
#include "Interaccion.h"
#include "Esfera.h"
#include "Planobloque.h"
#include "Bloque.h"
#include "BloqueDoble.h"

void Mundo::rotarOjo() //No tocar
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}

void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			0.0, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    
	ficha.dibuja(); //Dibuja la ficha
	caja.dibuja(); //Dibuja la caja completa
	bloques.dibuja(); //DIBUJO DE LISTABLOQUES!! Dibuja todos los bloques 
	esfera.dibuja(); //Dibuja las esferas
	bonus.dibuja();
}

void Mundo::mueve()
{
	ficha.mueve(0.09f); //MOVIMIENTO DE LA FICHA ROJA
	ficha.setVel(0.0f,0.0f); //PARA QUE LA FICHA NO SE MUEVA SI NO SE PULSA UNA TECLA
	esfera.mueve(0.025f); //MOVIMIENTO DE LA ESFERA
	bonus.mueve(0.025f); //MOVIMIENTO DEL BONUS
	Interaccion::rebote(ficha,caja); //LIMITE DE LA CAJA PARA LA FICHA
	Interaccion::rebote(esfera,caja); //CHOQUES ENTRE LA CAJA Y LA ESFERA
	Interaccion::rebote(esfera, ficha); //REBOTE ENTRE LA ESFERA Y LA FICHA
	
	if (Interaccion::intercepta(bonus, ficha))
	{
		esfera.especial=true;
		esfera.setColor(255,150,150);
	}

	// AQUÍ ESTÁ LA LÓGICA DEL JUEGO
	

	if (Interaccion::rebote(esfera, caja.suelo)&&(vds.getVidas()>0)) //Si se nos cae la bola, y tenemos vidas aún...
	{
		vds.decrementaVidas(); //nos resta una vida
		esfera.setPos(0,2); //esfera en posición inicial
		esfera.setVel(0,0);  //esfera parada esperando a ser lanzada
		esfera.aceleracion.y=0; //esfera parada esperando ser lanzada
		esfera.especial=false;
		esfera.setColor(40,40,40);
	}

	
	
	Bloque *aux=bloques.rebota(esfera);//Si la esfera choca con un bloque, nos devuelve el bloque con el que choca
	if(aux!=0x000000)//si alguna esfera ha chocado ¿Es necesario?
	{	
		if(!(contador%10))
		{
			bonus.dibuja();
			bonus.setPos(aux->suelo);
			bonus.setVel(0);
			
		}
		contador++;

		bloques.eliminar(aux);//eliminamos el bloque que hemos tocado //AQUÍ ES DONDE SE GESTIONA EL BORRADO DEL BLOQUE QUE CHOCA
	}
}

void Mundo::inicializa()
{	
	x_ojo=0; //Posiciones del ojo a donde miramos
	y_ojo=7.5;
	z_ojo=30;
	
	nivel=1;
	
	contador=1;
	
	esfera.setColor(40,40,40); //Establecemos la esfera de color rojo
	esfera.setRadio(0.5f); //Con este radio
	esfera.setPos(0,1.5f); //En esta posición inicial
	esfera.setVel(0,0); // Parada, esperando a ser lanzada

	esfera.especial=false; //Por defecto, la esfera no es "Especial". Lo será al coger un bonus.

	ficha.setPos(2.0f,1,-2.0f,1); //Fijamos la posición de la ficha en el centro de la pantalla.

	vds.setVidas(5); //Ponemos el número de vidas iniciales. 

	//Cargamos la primera pantalla del juego
	inicializaV1();


}

void Mundo::creaBloque(int h, int v)
{
	int horizontal=h;
	int vertical=v;
	Bloque* aux = new Bloque; // Creamos un bloque con NEW, y se lo asignamos a AUX. Utilizamos AUX para ahora darle posición y color a sus planos. 
	//aux->frontal.setColor(150,150,150);
	aux->frontal.setPos(-13.0f+horizontal,14.0f-vertical,-11.0f+horizontal,15.0f-vertical);
	//aux->suelo.setColor(150,150,150);
	aux->suelo.setPos(-13.0f+horizontal,14-vertical,-11.0f+horizontal,14-vertical);
	//aux->techo.setColor(255,0,0);
	aux->techo.setPos(-13.0f+horizontal,15.0f-vertical,-11.0f+horizontal,15.0f-vertical);
	//aux->pared_dcha.setColor(150,150,150);
	aux->pared_dcha.setPos(-13.0f+horizontal,14-vertical,-13.0f+horizontal,15.0f-vertical);
	//aux->pared_izq.setColor(150,150,150);
	aux->pared_izq.setPos(-11.0f+horizontal,14-vertical,-11.0f+horizontal,15.0f-vertical);
	bloques.agregar(aux); //Agregamos el bloque a la lista 
}

void Mundo::creaBloqueEspecial(int h, int v)
{
	int horizontal=h;
	int vertical=v;
	Bloque* aux = new BloqueDoble; // Creamos un bloque con NEW, y se lo asignamos a AUX. Utilizamos AUX para ahora darle posición y color a sus planos. 
	//aux->frontal.setColor(150,150,150);
	aux->frontal.setPos(-13.0f+horizontal,14.0f-vertical,-11.0f+horizontal,15.0f-vertical);
	//aux->suelo.setColor(150,150,150);
	aux->suelo.setPos(-13.0f+horizontal,14-vertical,-11.0f+horizontal,14-vertical);
	//aux->techo.setColor(255,0,0);
	aux->techo.setPos(-13.0f+horizontal,15.0f-vertical,-11.0f+horizontal,15.0f-vertical);
	//aux->pared_dcha.setColor(150,150,150);
	aux->pared_dcha.setPos(-13.0f+horizontal,14-vertical,-13.0f+horizontal,15.0f-vertical);
	//aux->pared_izq.setColor(150,150,150);
	aux->pared_izq.setPos(-11.0f+horizontal,14-vertical,-11.0f+horizontal,15.0f-vertical);
	bloques.agregar(aux); //Agregamos el bloque a la lista 
}

void Mundo::inicializaV1()
{
	nivel=1;
	//PRIMERA PANTALLA (NIVEL 1)
	int horizontal=0;
	int vertical=0;
	//cout<<"Memoria inicial"<<endl;
	for (int j=0; j<3; j++) //3 filas  //SI SE PONE J<0, CARGA EL NIVEL 2 
	{
		for (int i=0 ; i<13 ; i++) 
		{
			creaBloque(horizontal,vertical);
			//cout<<bloques.lista[i]<<endl;
			horizontal+=2; //pasamos al siguiente bloque horizontal
		}
		horizontal=0; //volvemos al principio de la fila horizontal
		vertical+=1; //añadimos una fila 
	}
	for (int j=0; j<1; j++) //3 filas  //SI SE PONE J<0, CARGA EL NIVEL 2 
	{
		for (int i=0 ; i<13 ; i++) 
		{
			creaBloqueEspecial(horizontal,vertical);
			//cout<<bloques.lista[i]<<endl;
			horizontal+=2; //pasamos al siguiente bloque horizontal
		}
		horizontal=0; //volvemos al principio de la fila horizontal
		vertical+=1; //añadimos una fila 
	}

}
void Mundo::inicializaV2()
{
	nivel=2;
	esfera.especial=true;
	esfera.setColor(40,40,40);
	cout<<"Primer nivel superado. Siguiente nivel: Nivel 2."<<endl;
	esfera.setPos(0,2); //esfera en posición inicial
	esfera.setVel(0,0);  //esfera parada esperando a ser lanzada
	esfera.aceleracion.y=0; //esfera parada esperando ser lanzada
	ficha.setPos(2.0f,1,-2.0f,1);
	ficha.setVel(0,0);

	int horizontal=0;
	int vertical=0;
	int num=7, i=1;

	for (int j=0; j<1; j++) //3 filas  //SI SE PONE J<0, CARGA EL NIVEL 2 
	{
		for (int i=0 ; i<13 ; i++) 
		{
			creaBloqueEspecial(horizontal,vertical);
			//cout<<bloques.lista[i]<<endl;
			horizontal+=2; //pasamos al siguiente bloque horizontal
		}
		horizontal=0; //volvemos al principio de la fila horizontal
		vertical+=1; //añadimos una fila 
	}
	for (int i=1; i<num; i++) 
	{
		int j=1;
		for (int j=1 ; j<=i; j++) {horizontal+=2;}
		for (int k=0; k<2*(num-i)-1; k++)
		{
			creaBloque(horizontal,vertical); 
			horizontal+=2; //pasamos al siguiente bloque horizontal
		}
		horizontal=0; //volvemos al principio de la fila horizontal
		vertical+=1; //añadimos una fila 
	}
}
void Mundo::inicializaV3()
{
	nivel=3;
	esfera.especial=true;
	esfera.setColor(40,40,40);
	cout<<"Segundo nivel superado. Siguiente nivel: Nivel 3."<<endl;
	esfera.setPos(0,2); //esfera en posición inicial
	esfera.setVel(0,0);  //esfera parada esperando a ser lanzada
	esfera.aceleracion.y=0; //esfera parada esperando ser lanzada
	ficha.setPos(2.0f,1,-2.0f,1);
	ficha.setVel(0,0);

	int horizontal=6;
	int vertical=-1;
	int num=4, i=1;
	for (int i=0; i<num; i++) 
	{
		int j=1;
		for (int j=1 ; j<=num-i; j++) {horizontal=horizontal+2;}
		for (int k=0; k<2*i-1; k++)
		{
			creaBloque(horizontal,vertical);
			horizontal+=2; //pasamos al siguiente bloque horizontal
		}
		horizontal=6; //volvemos al principio de la fila horizontal
		vertical+=1; //añadimos una fila 
	}
		for (int i=0; i<num; i++) 
	{
		int j=1;
		for (int j=1 ; j<=i; j++) {horizontal=horizontal+2;}
		for (int k=0; k<2*(num-i)-1; k++)
		{
			creaBloqueEspecial(horizontal,vertical);
			horizontal+=2; //pasamos al siguiente bloque horizontal
		}
		horizontal=6; //volvemos al principio de la fila horizontal
		vertical+=1; //añadimos una fila 
	}
}


void Mundo::finDelJuego()
{
	cout<<"Fin del juego"<<endl;
	ficha.setVel (0,0); //Fin del juego, la ficha queda inmovi
	esfera.setVel (0,0);
	esfera.setPos (0,2);
	ficha.setPos (2.0f,1,-2.0f,1);
	esfera.aceleracion.y=0;
	nivel=0;
}


void Mundo::tecla(unsigned char key)
{

}

void Mundo::teclaEspecial(unsigned char key)
{
	if (vds.getVidas()==0)
	{
		ficha.setVel (0,0); //Fin del juego, la ficha queda inmovi
		esfera.setVel (0,0);
		esfera.setPos (0,2);
		ficha.setPos (2.0f,1,-2.0f,1);
		//cout<<"Memoria final"<<endl;
		//	for(int i = 0; i<52; i++)
		//		cout<<bloques.lista[i]<<endl;
	}
	else
	{
		switch(key)
		{

		case GLUT_KEY_LEFT:
			ficha.setVel (-15.0f, 0.0f); //Si quedan vidas, la ficha se mueve a esa velocidad.
			break;

		case GLUT_KEY_RIGHT:
			ficha.setVel (15.0f, 0.0f); //por defecto tiene este movimiento
			break;

		case GLUT_KEY_UP:
			if (esfera.aceleracion.y==0)
			{
				float v1;
				v1=rand() % 15 + (-7);
				esfera.setVel (v1, 19.25f); //por defecto esto
				esfera.aceleracion.y=-9.8f; 
			}
			break;
		}
	}	
}

Mundo::~Mundo() //se llama a los destructores de todos los objetos
{
	bloques.destruirContenido(); //al salir del juego llamamos al destructor con memoria dinamica de los bloques
	ficha.~Ficha();
	caja.~Caja();
	esfera.~Esfera();
}