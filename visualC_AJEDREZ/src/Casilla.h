#pragma once

#include "Vector2xy.h"

class Casilla
{
	// Par�metros gr�ficos de casilla
	int vx;
	int vy;
	int colR, colG, colB;
	
	
public:
	void dibuja();

	friend class Tablero;
};

