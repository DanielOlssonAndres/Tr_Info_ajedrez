#pragma once

#include "vector2xy.h"
#include "Tablero.h"

using namespace std;

enum { BOTON_RATON_IZQ, BOTON_RATON_DRCH};

class Mundo
{
public:

	Tablero tablero;
	int Tjuego = 0;
	Vector2xy PosEnCasillas[6][5];
	
	// VARIABLES PARA SELECCI�N POR RAT�N----------------------------
	float ancho = 6; //Darle un valor al ancho de las casillas
	Vector2xy CasillaOrigen;	//casilla seleccionada con el rat�n ORIGEN
	Vector2xy CasillaDestino; //casilla seleccionada con el rat�n DESTINO
	// --------------------------------------------------------------

	void inicializa();
	void dibuja();

	// FUNCIONES RELACIONADAS CON LA SELECCI�N POR RAT�N---------------------------------------------------
	void MouseButton(int x, int y, int boton, bool abajo, bool TeclaSp, bool TeclaCtr);
	// ----------------------------------------------------------------------------------------------------

};