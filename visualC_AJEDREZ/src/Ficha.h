#pragma once
#include "vector2xy.h"
#include <ETSIDI.h>

class Ficha
{
private:

	int valor;
	Vector2xy posicion;

public:

	Ficha(int x, int y, int val);
	void Set_Posicion(int, int);
	Vector2xy Get_Posicion();
	int Get_Valor();

	int Get_PosicionX() { return posicion.x; }
	int Get_PosicionY() { return posicion.y; }

	void Cambiar_Valor(int);

};

