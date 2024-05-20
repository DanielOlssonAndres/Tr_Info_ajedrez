#include "Ficha.h"

Ficha::Ficha(int x, int y, int val, Vector2xy PosEnCasillas):
	valor(val),
	sprite("imagenes/T_REY_LEON.png"),
	posicion({ x, y }),
	ubicacion(PosEnCasillas)
{
	if (valor = 1)  sprite = { "imagenes/T_REY_LEON.png" };
	if (valor = -1) sprite = { "imagenes/A_REY_TIBURON.png" };

	if (valor = 2) sprite = { "imagenes/T_DAMA_LEONA.png" };
	if (valor = -2) sprite = { "imagenes/A_DAMA_BALLENA.png" };

	if (valor = 3) sprite = { "imagenes/T_ALFIL_PATO.png" };
	if (valor = -3) sprite = { "imagenes/A_ALFIL_PULPO.png" };

	if (valor = 4) sprite = { "imagenes/T_CABALLO_CEBRA.png" };
	if (valor = -4) sprite = { "imagenes/A_CABALLO_CABALLITO_DE_MAR.png" };

	if (valor = 5) sprite = { "imagenes/T_TORRE_GIRAFA.png" };
	if (valor = -5) sprite = { "imagenes/A_TORRES_CANGREJO.png" };

	if (valor = 6) sprite = { "imagenes/T_PEON_CONEJO_2.png" };
	if (valor = -6) sprite = { "imagenes/A_PEON_GAMBA.png" };
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

void Ficha::dibuja() {

	if (valor > 0) {
		glPushMatrix();
		glTranslatef(ubicacion.x - 3, ubicacion.y - 3, 1);

		sprite.setSize(5, 5);

		sprite.draw();
		glPopMatrix();
	}
	else {
		glPushMatrix();
		glTranslatef(ubicacion.x - 3, ubicacion.y - 3, 1);

		sprite.setSize(5, 5);

		sprite.draw();
		glPopMatrix();
	}
}

