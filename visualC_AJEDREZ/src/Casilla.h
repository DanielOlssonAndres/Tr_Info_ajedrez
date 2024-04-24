#pragma once

#include "Vector2xy.h"

class Casilla
{
	// Parámetros gráficos de casilla
	int vx;
	int vy;
	int colR, colG, colB;
	
	
public:
	void dibuja();

	friend class Tablero;
};

