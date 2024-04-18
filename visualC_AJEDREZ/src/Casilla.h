#pragma once

#include "Vector2xy.h"

class Casilla
{
	// Parámetros gráficos de casilla
	int vx;
	int vy;
	int colR, colG, colB;
	Vector2xy PosF; // Indica la posición de la ficha que se encuentra en esta casilla
	
	
public:
	void dibuja();

	friend class Tablero;
};

