#pragma once
#include "Vector2xy.h"
#include "Ficha.h"
#include "ETSIDI.h"
class Rey : public Ficha
{


public:
	
	ETSIDI::Sprite sprite_blanco{ "bin/imagenes/T_REY_LEON.png" };
	ETSIDI::Sprite sprite_negro{ "bin/imagenes/A_REY_TIBURON.png" };

	void inicializa_5x6EO(const Vector2xy& posicion, const float tipo);
	void inicializa_PETTY(const Vector2xy& posicion, const float tipo);
	void dibuja_blanco();
	void dibuja_negro();
};

