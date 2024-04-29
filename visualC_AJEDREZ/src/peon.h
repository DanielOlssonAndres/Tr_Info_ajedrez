#pragma once
#include "Ficha.h"
#include "ETSIDI.h"

class Peon : public Ficha
{
	ETSIDI::Sprite sprite_blanco{ "bin/imagenes/T_PEON_CONEJO_2.png"};
	ETSIDI::Sprite sprite_negro{ "bin/imagenes/A_PEON_GAMBA.png" };

public:
	void dibuja();
	
};

