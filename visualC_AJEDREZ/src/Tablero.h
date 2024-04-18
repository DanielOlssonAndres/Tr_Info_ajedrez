#pragma once

#include "Casilla.h"

#include <iostream>


class Tablero
{
	// El tablero es una matríz de 6 filas y 5 columnas (30 objetos tipo Casilla)
	Casilla Mcasillas[6][5];

public:
	void inicializa();
	void dibuja();
};

