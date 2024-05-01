#pragma once

#include <iostream>
#include "vector2xy.h"
#include "Ficha.h"

#include "peon.h"
#include "torre.h"
#include "caballo.h"
#include "alfil.h"
#include "dama.h"
#include "rey.h"

struct CASILLA {
	// Parámetros gráficos de casilla
	int vx;
	int vy;
	int colR, colG, colB;
};

class Tablero
{
	int Tjuego;

	CASILLA Mcasillas[6][5]; // Para parte GRÁFICA -> Indica posición de esquina de las casillas

	Ficha* MatTablero[6][5];

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
	void inicializa(const int& TJ);
	void dibuja();

	friend class Ficha;
};