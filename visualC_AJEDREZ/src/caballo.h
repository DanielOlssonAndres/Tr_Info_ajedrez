#pragma once
#include "Ficha.h"
#include "ETSIDI.h"

class Caballo : public Ficha
{ 
	ETSIDI::Sprite sprite_blanco{ "imagenes/T_CABALLO_CEBRA.png" };
	ETSIDI::Sprite sprite_negro{ "imagenes/A_CABALLO_CABALLITO_DE_MAR.png" };

public:
	void dibuja() override;

};

