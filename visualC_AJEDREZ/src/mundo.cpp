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
	
	//INICIALIZACIÓN DE FICHAS ESPECIALES
	if (Tjuego == 0) { //Modalidad 5x6EO();
		//Blancas
		reyB.inicializa_5x6EO(PosEnCasillas[0][4], 1.0);
		damaB.inicializa_5x6EO(PosEnCasillas[0][3], 1.0);
		alfilB.inicializa_5x6EO(PosEnCasillas[0][2], 1.0);
		caballoB.inicializa_5x6EO(PosEnCasillas[0][1], 1.0);
		torreB.inicializa_5x6EO(PosEnCasillas[0][0], 1.0);
		//Negras
		reyN.inicializa_5x6EO(PosEnCasillas[5][0], 0.3);
		damaN.inicializa_5x6EO(PosEnCasillas[5][1], 0.3);
		alfilN.inicializa_5x6EO(PosEnCasillas[5][2], 0.3);
		caballoN.inicializa_5x6EO(PosEnCasillas[5][3], 0.3);
		torreN.inicializa_5x6EO(PosEnCasillas[5][4], 0.3);
	}
	else { //Modalidad PETTY
		//Blancas
		reyB.inicializa_PETTY(PosEnCasillas[0][1], 1.0);
		damaB.inicializa_PETTY(PosEnCasillas[0][0], 1.0);
		alfilB.inicializa_PETTY(PosEnCasillas[0][2], 1.0);
		caballoB.inicializa_PETTY(PosEnCasillas[0][3], 1.0);
		torreB.inicializa_PETTY(PosEnCasillas[0][4], 1.0);
		//Negras
		reyN.inicializa_PETTY(PosEnCasillas[5][1], 0.3);
		damaN.inicializa_PETTY(PosEnCasillas[5][0], 0.3);
		alfilN.inicializa_PETTY(PosEnCasillas[5][2], 0.3);
		caballoN.inicializa_PETTY(PosEnCasillas[5][3], 0.3);
		torreN.inicializa_PETTY(PosEnCasillas[5][4], 0.3);
	}
	//INICIALIZACIÓN DE PEONES
	//Blancos
	peonB1.inicializa(PosEnCasillas[1][0], 1.0);
	peonB2.inicializa(PosEnCasillas[1][1], 1.0);
	peonB3.inicializa(PosEnCasillas[1][2], 1.0);
	peonB4.inicializa(PosEnCasillas[1][3], 1.0);
	peonB5.inicializa(PosEnCasillas[1][4], 1.0);
	//Negros
	peonN1.inicializa(PosEnCasillas[4][0], 0.3);
	peonN2.inicializa(PosEnCasillas[4][1], 0.3);
	peonN3.inicializa(PosEnCasillas[4][2], 0.3);
	peonN4.inicializa(PosEnCasillas[4][3], 0.3);
	peonN5.inicializa(PosEnCasillas[4][4], 0.3);

}


void Mundo::dibuja()
{
	// vista
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		x_look, y_look, z_look,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  

	// dibujo de elementos
	tablero.dibuja();
	
	//Blancas
	reyB.dibuja();
	damaB.dibuja();
	alfilB.dibuja();
	caballoB.dibuja();
	torreB.dibuja();
	peonB1.dibuja();
	peonB2.dibuja();
	peonB3.dibuja();
	peonB4.dibuja();
	peonB5.dibuja();

	//Negras
	reyN.dibuja();
	damaN.dibuja();
	alfilN.dibuja();
	caballoN.dibuja();
	torreN.dibuja();
	peonN1.dibuja();
	peonN2.dibuja();
	peonN3.dibuja();
	peonN4.dibuja();
	peonN5.dibuja();

}
