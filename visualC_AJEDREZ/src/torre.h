#pragma once
#include "Vector2xy.h"
#include "ETSIDI.h"
#include "Ficha.h"

class Torre : public Ficha
{


public:
	ETSIDI::Sprite sprite_blanco{ "imagenes/T_TORRE_GIRAFA.png" };
	ETSIDI::Sprite sprite_negro{ "imagenes/A_TORRES_CANGREJO.png" };

	void dibuja_blanco();
	void dibuja_negro();
};

