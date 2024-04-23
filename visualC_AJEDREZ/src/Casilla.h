#pragma once

#include "Vector2xy.h"

class Casilla
{
	// Par�metros gr�ficos de casilla
	int vx;
	int vy;
	int colR, colG, colB;
	Vector2xy PosCentro; // Indica la posici�n de la ficha que se encuentra en esta casilla
	
	
public:
	void dibuja();

	friend class Tablero;
};

