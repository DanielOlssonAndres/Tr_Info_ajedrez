#pragma once
#include "Vector2xy.h"
#include "Ficha.h"
#include "ETSIDI.h"

class Caballo : public Ficha
{ 

public:

	ETSIDI::Sprite sprite_blanco{ "bin/imagenes/T_CABALLO_CEBRA.png" };
	ETSIDI::Sprite sprite_negro{ "bin/imagenes/A_CABALLO_CABALLITO_DE_MAR.png" };

	void inicializa_5x6EO(const Vector2xy& posicion, const float tipo);
	void inicializa_PETTY(const Vector2xy& posicion, const float tipo);
	void dibuja_blanco();
	void dibuja_negro();

};

