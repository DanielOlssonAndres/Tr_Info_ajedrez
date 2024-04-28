#pragma once
#include "Vector2xy.h"
#include "ETSIDI.h"
#include "Ficha.h"

class Torre : public Ficha
{


public:
	ETSIDI::Sprite sprite_blanco{ "bin/imagenes/T_TORRE_GIRAFA.png" };
	ETSIDI::Sprite sprite_negro{ "bin/imagenes/A_TORRES_CANGREJO.png" };

	void inicializa_5x6EO(const Vector2xy& posicion, const float tipo);
	void inicializa_PETTY(const Vector2xy& posicion, const float tipo);
	void dibuja_blanco();
	void dibuja_negro();
};

