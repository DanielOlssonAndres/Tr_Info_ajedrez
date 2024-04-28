#pragma once
#include "Ficha.h"
#include "ETSIDI.h"

class Alfil : public Ficha
{

public:
	ETSIDI::Sprite sprite_blanco{ "bin/imagenes/T_ALFIL_PATO.png" };
	ETSIDI::Sprite sprite_negro{ "bin/imagenes/A_ALFIL_PULPO.png" };
	
	void dibuja_blanco();
	void dibuja_negro();

};
