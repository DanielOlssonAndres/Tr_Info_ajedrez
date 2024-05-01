#pragma once
#include "Ficha.h"
#include "ETSIDI.h"

class Caballo : public Ficha
{ 
	ETSIDI::Sprite sprite_blanco{ "bin/imagenes/T_CABALLO_CEBRA.png" };
	ETSIDI::Sprite sprite_negro{ "bin/imagenes/A_CABALLO_CABALLITO_DE_MAR.png" };

public:
	void dibuja() override;

};

