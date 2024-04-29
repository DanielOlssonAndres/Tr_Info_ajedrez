#pragma once

#include "Casilla.h"
#include <iostream>
#include "vector2xy.h"
#include "Ficha.h"


class Tablero
{
	// El tablero es una matríz de 6 filas y 5 columnas (30 objetos tipo Casilla)
	Casilla Mcasillas[6][5];
	//Vector2xy CentroCasillas[6][5]; // Indica la posición de la ficha que se encuentra en esta casilla

public:
	void inicializa();
	void dibuja();
	void casilla(Vector2xy);
};

