#pragma once

/*#include "Vector2xy.h"

enum Tipo {NEGRAS = 0, BLANCAS};
class Ficha
{
protected:
	Vector2xy posicion;
	Tipo tipo;

public:
	void inicializa(const Vector2xy& posicion, const Tipo& tipo);
};*/

#include "Vector2xy.h"

#include "peon.h"
#include "torre.h"
#include "caballo.h"
#include "alfil.h"
#include "dama.h"
#include "rey.h"

class Ficha
{
public:

	Vector2xy PosEnCasillas[6][5];

	//Fichas blancas
	Peon peonB1, peonB2, peonB3, peonB4, peonB5;
	Torre torreB;
	Caballo caballoB;
	Alfil alfilB;
	Dama damaB;
	Rey reyB;

	//Fichas negras
	Peon peonN1, peonN2, peonN3, peonN4, peonN5 ;
	Torre torreN;
	Caballo caballoN;
	Alfil alfilN;
	Dama damaN;
	Rey reyN;

	void inicializa(const int Tjuego);
	void dibuja();

	
};

