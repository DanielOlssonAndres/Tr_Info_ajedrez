#pragma once

#include "Vector2xy.h"
#include "Tablero.h"

enum {BLANCA = 0, NEGRA = 1};

class Ficha
{
	bool color;
	Vector2xy PosBlancas[10]; 
	Vector2xy PosNegras[10];

public:
	void inicializa_5x6EO();
	void inicializa_PETTY();
	void dibuja();

};

