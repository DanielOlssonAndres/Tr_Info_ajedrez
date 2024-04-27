#pragma once
#include "Vector2xy.h"

class Peon {
	Vector2xy posicion;
	float tipo; // 1.0 = BLANCO  0.3 = NEGRO        ¡¡¡MEJORABLE!!!  

public:
	void inicializa(const Vector2xy& posicion, const float tipo);
	void dibuja();
};

