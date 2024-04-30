#pragma once
#include "Ficha.h"
#include "ETSIDI.h"

class Dama : public Ficha
{
	ETSIDI::Sprite sprite_blanco{ "imagenes/T_DAMA_LEONA.png" };
	ETSIDI::Sprite sprite_negro{ "imagenes/A_DAMA_BALLENA.png" };

public:
	void dibuja();
};

