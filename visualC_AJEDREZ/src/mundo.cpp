#include "mundo.h"
#include <iostream>
#include <vector>
#include "freeglut.h"

#include "Tablero.h"
#include "Ficha.h"


void Mundo::inicializa(int Tjuego = 0)
{
	// Punto de vista
	x_ojo = 15;
	y_ojo = 18;
	z_ojo = 60;
	x_look = 15;
	y_look = 18;
	z_look = 0;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 5; j++) {
			PosEnCasillas[i][j] = { 3 + j * 6, 3 + i * 6 };
		}
	}

	tablero.inicializa();

	if (Tjuego == 0) { //5x6EO();
		//reyB.inicializa_5x6EO();

	}
	else { //PETTY


	}
	


}


void Mundo::dibuja()
{
	// vista
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		x_look, y_look, z_look,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  

	// dibujo de elementos
	tablero.dibuja();
	fichas.dibuja();


}
