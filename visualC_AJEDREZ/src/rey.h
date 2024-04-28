#pragma once
#include "Ficha.h"
#include "ETSIDI.h"

class Rey : public Ficha
{


public:
	
	ETSIDI::Sprite sprite_blanco{ "imagenes/T_REY_LEON.png" };
	ETSIDI::Sprite sprite_negro{ "imagenes/A_REY_TIBURON.png" };

	void dibuja_blanco();
	void dibuja_negro();
};

