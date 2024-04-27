#pragma once

#include "Vector2xy.h"

enum Tipo {NEGRAS = 0, BLANCAS};
class Ficha
{
protected:
	Vector2xy posicion;
	Tipo tipo;

public:
	void inicializa(const Vector2xy& posicion, const Tipo& tipo);
};

