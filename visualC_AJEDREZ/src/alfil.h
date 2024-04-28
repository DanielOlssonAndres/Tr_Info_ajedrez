#pragma once
#include "Ficha.h"
#include "ETSIDI.h"

class Alfil : public Ficha
{
	ETSIDI::Sprite sprite_blanco{ "imagenes/T_ALFIL_PATO.png" };
	ETSIDI::Sprite sprite_negro{ "imagenes/A_ALFIL_PULPO.png" };
	
public:
	void dibuja();

};
