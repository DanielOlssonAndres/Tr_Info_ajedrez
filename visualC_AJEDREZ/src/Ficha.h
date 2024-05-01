#pragma once
#include "vector2xy.h"

struct Posicion {
	int x;
	int y;
};

enum Tipo {NEGRAS = 0, BLANCAS};
class Ficha
{
protected:
	Tipo tipo;
	Posicion pos;
	Vector2xy PosEnCasillas[6][5]; //Matriz que almacena las posiciones de las piezas en las casillas para parte GRÁFICA
public:
	void inicializa(const Posicion& posicion, const Tipo& tipo);
	virtual void dibuja() = 0;
};
