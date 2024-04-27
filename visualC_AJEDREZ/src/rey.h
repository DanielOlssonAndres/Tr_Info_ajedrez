#pragma once
#include "Vector2xy.h"

class Rey {
	Vector2xy posicion;
	float tipo; // 1.0 = BLANCO  0.3 = NEGRO        ¡¡¡MEJORABLE!!!  

public:
	void inicializa_5x6EO(const Vector2xy& posicion, const float tipo);
	void inicializa_PETTY(const Vector2xy& posicion, const float tipo);
	void dibuja();
};

