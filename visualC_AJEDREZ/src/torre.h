#pragma once
#include "Ficha.h"
#include "Vector2xy.h"
#include "ETSIDI.h"

class Torre :public Ficha {
	Vector2xy posicion;
	float tipo; // 1.0 = BLANCO  0.3 = NEGRO        ¡¡¡MEJORABLE!!!  
	//ETSIDI::SpriteSequence spriteB{ "imagenes/TBLANC.png", 5 };
	//ETSIDI::SpriteSequence spriteN{ "imagenes/TorreNegra.png", 5 };

public:
	void inicializa_5x6EO(const Vector2xy& posicion, const float tipo);
	void inicializa_PETTY(const Vector2xy& posicion, const float tipo);
	void dibuja();
};

