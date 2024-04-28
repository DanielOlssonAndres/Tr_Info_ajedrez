#pragma once
#include "Ficha.h"
#include "ETSIDI.h"


class Dama : public Ficha
{

public:

	ETSIDI::Sprite sprite_blanco{ "bin/imagenes/T_DAMA_LEONA.png" };
	ETSIDI::Sprite sprite_negro{ "bin/imagenes/A_DAMA_BALLENA.png" };

	void dibuja_blanco();
	void dibuja_negro();
};

