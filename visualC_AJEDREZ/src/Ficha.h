#pragma once
#include "vector2xy.h"
#include<ETSIDI.h>

struct Posicion {
	int x;
	int y;
};

enum Tipo {NEGRAS = 0, BLANCAS};
enum Forma {Peon = 1, Caballo, Alfil, Torre, Dama, Rey};

class Ficha
{
private:

	int valor;
	Vector2xy posicion;

public:

	Ficha(int x, int y, int val, Vector2xy PosEnCasillas);
	void Contener_Posicion(int, int);
	void Set_Posicion(int, int);
	Vector2xy Get_Posicion();
	int Get_Valor();

};

