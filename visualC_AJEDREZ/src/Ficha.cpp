#include "Ficha.h"

Ficha::Ficha(int x, int y, int val, Vector2xy PosEnCasillas):
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

void Ficha::Contener_Posicion(int x, int y) {//Posicion del ratón

	// Hcer una función que le de un valor a la casilla que tiene seleccionada el raton
	// Una vez tengas la casilla nombrala como pInd 
}


