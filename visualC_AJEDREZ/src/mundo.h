#pragma once

#include "Tablero.h"
#include "Ficha.h"

#include <vector>

class Mundo
{
	double x_ojo, y_ojo, z_ojo;
	double x_look, y_look, z_look;

	Tablero tablero;
	Ficha fichas;



public:
	void inicializa();
	void dibuja();
};

