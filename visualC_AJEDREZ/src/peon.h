#pragma once
#include "Ficha.h"
#include "ETSIDI.h"

class Peon : public Ficha
{

public:
	ETSIDI::Sprite sprite_blanco{ "imagenes/T_PEON_CONEJO_2.png"};
	ETSIDI::Sprite sprite_negro{ "imagenes/A_PEON_GAMBA.png" };

	void dibuja_blanco();
	void dibuja_negro();
};

