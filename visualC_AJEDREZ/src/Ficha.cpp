#include "Ficha.h"

Ficha::Ficha(int x, int y, int val):
	valor(val),
	posicion({ x, y })	
{}

Vector2xy Ficha::Get_Posicion() {
	return posicion;
}

void Ficha::Set_Posicion(int x, int y) {
	posicion.x = x;
	posicion.y = y;
}

int Ficha::Get_Valor() {
	return valor;
}



