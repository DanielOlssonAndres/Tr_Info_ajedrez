#pragma once

#include "Casilla.h"
#include "Ficha.h"
#include <iostream>
#include "vector2xy.h"


class Tablero
{
	// El tablero es una matr�z de 6 filas y 5 columnas (30 objetos tipo Casilla)
	Casilla Mcasillas[6][5];
	//Vector2xy CentroCasillas[6][5]; // Indica la posici�n de la ficha que se encuentra en esta casilla

public:
	void inicializa();
	void dibuja();

	friend class mundo;
};

