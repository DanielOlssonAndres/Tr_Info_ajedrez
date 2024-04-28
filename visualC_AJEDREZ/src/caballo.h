#pragma once
#include "Ficha.h"
#include "ETSIDI.h"

class Caballo : public Ficha
{ 

public:

	ETSIDI::Sprite sprite_blanco{ "imagenes/T_CABALLO_CEBRA.png" };
	ETSIDI::Sprite sprite_negro{ "imagenes/A_CABALLO_CABALLITO_DE_MAR.png" };

	void dibuja_blanco();
	void dibuja_negro();

};

