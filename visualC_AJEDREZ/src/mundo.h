#pragma once

#include "vector2xy.h"

#include "Tablero.h"
#include "listafichas.h"

#include "Ficha.h" //...


class Mundo
{
	double x_ojo, y_ojo, z_ojo;
	double x_look, y_look, z_look;

	int Tjuego;

	Tablero tablero;
	Listafichas fichas;

	Ficha ficha; //...

public:
	void inicializa();
	void dibuja();
};

