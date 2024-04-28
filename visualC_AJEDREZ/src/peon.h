#pragma once
#include "Vector2xy.h"
#include "Ficha.h"

class Peon : public Ficha
{

public:
	ETSIDI::Sprite sprite_blanco{ "bin/imagenes/T_PEON_CONEJO_2.png"};
	ETSIDI::Sprite sprite_negro{ "bin/imagenes/A_PEON_GAMBA.png" };

	void inicializa(const Vector2xy& posicion, const float tipo);

	void dibuja_blanco();
	void dibuja_negro();
};

