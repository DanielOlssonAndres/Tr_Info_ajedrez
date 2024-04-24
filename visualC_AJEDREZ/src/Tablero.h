#pragma once

#include "Casilla.h"
#include "Ficha.h"
#include <iostream>


class Tablero
{
	// El tablero es una matríz de 6 filas y 5 columnas (30 objetos tipo Casilla)
	Casilla Mcasillas[6][5];
	Vector2xy CentroCasillas[6][5]; // Indica la posición de la ficha que se encuentra en esta casilla

public:
	void inicializa();
	void dibuja();

	const Vector2xy& obtenerCentroCasilla(int fila, int columna) const{
		return CentroCasillas[fila][columna];
	}
	// Es amigo de las funciones de inicialización de las fichas para poder conocer las posiciones de las fichas en el tablero
	friend class Ficha;
};

