#pragma once

#include "Tablero.h"
#include "Casilla.h"
#include "Ficha.h"
#include "peon.h"
#include "torre.h"
#include "caballo.h"
#include "alfil.h"
#include "dama.h"
#include "rey.h"

#include <vector>

class Mundo
{
	double x_ojo, y_ojo, z_ojo;
	double x_look, y_look, z_look;

	Tablero tablero;
	Casilla casillas;
	Ficha fichas;

	//Fichas blancas
	Peon peonB1, peonB2, peonB3, peonB4, peonB5;
	Torre torreB;
	Caballo caballoB;
	Alfil alfilB;
	Dama damaB;
	Rey reyB;

	//Fichas negras
	Peon peonN1, peonN2, peonN3, peonN4, peonN5;
	Torre torreN;
	Caballo caballoN;
	Alfil alfilN;
	Dama damaN;
	Rey reyN;




public:
	void inicializa();
	void dibuja();
};

