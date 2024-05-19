#include "Ficha.h"
#include<ETSIDI.h>


Ficha::Ficha(int x, int y, int val) {
	valor = val;
	if (valor = 1)  ETSIDI::Sprite sprite_blanco{ "bin/imagenes/T_REY_LEON.png" };
	if (valor = -1) ETSIDI::Sprite sprite_negro{ "bin/imagenes/A_REY_TIBURON.png" };

	if (valor = 2) ETSIDI::Sprite sprite_blanco{ "bin/imagenes/T_DAMA_LEONA.png" };
	if (valor = -2) ETSIDI::Sprite sprite_negro{ "bin/imagenes/A_DAMA_BALLENA.png" };

	if (valor = 3) ETSIDI::Sprite sprite_blanco{ "bin/imagenes/T_ALFIL_PATO.png" };
	if (valor = -3) ETSIDI::Sprite sprite_negro{ "bin/imagenes/A_ALFIL_PULPO.png" };

	if (valor = 4) ETSIDI::Sprite sprite_blanco{ "bin/imagenes/T_CABALLO_CEBRA.png" };
	if (valor = -4) ETSIDI::Sprite sprite_negro{ "bin/imagenes/A_CABALLO_CABALLITO_DE_MAR.png" };

	if (valor = 5) ETSIDI::Sprite sprite_blanco{ "bin/imagenes/T_TORRE_GIRAFA.png" };
	if (valor = -5) ETSIDI::Sprite sprite_negro{ "bin/imagenes/A_TORRES_CANGREJO.png" };

	if (valor = 6) ETSIDI::Sprite sprite_blanco{ "bin/imagenes/T_PEON_CONEJO_2.png" };
	if (valor = -6) ETSIDI::Sprite sprite_negro{ "bin/imagenes/A_PEON_GAMBA.png" };


}


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


