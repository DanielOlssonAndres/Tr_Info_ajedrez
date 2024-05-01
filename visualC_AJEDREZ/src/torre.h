#pragma once
#include "Vector2xy.h"
#include "ETSIDI.h"
#include "Ficha.h"

class Torre : public Ficha
{
	ETSIDI::Sprite sprite_blanco{ "bin/imagenes/T_TORRE_GIRAFA.png" };
	ETSIDI::Sprite sprite_negro{ "bin/imagenes/A_TORRES_CANGREJO.png" };

public:
	void dibuja() override;
	
};

