#pragma once
#include "vector2xy.h"
#include "Tablero.h"

using namespace std;

enum { BOTON_RATON_IZQ, BOTON_RATON_DRCH};

class Mundo
{

	Tablero tablero;
	int Tjuego = 0;
	int Toponente = 0;
	Vector2xy PosEnCasillas[6][5];
	
	// VARIABLES PARA SELECCIÓN POR RATÓN----------------------------
	float ancho = 6; //Darle un valor al ancho de las casillas
	Vector2xy CasillaOrigen;	//casilla seleccionada con el ratón ORIGEN
	Vector2xy CasillaDestino; //casilla seleccionada con el ratón DESTINO
	// --------------------------------------------------------------

public:

	void inicializa(int tipo_juego, const int& tipo_oponente);
	void dibuja();

	// FUNCIONES RELACIONADAS CON LA SELECCIÓN POR RATÓN---------------------------------------------------
	void MouseButton(int tipo_oponente, int x, int y, int boton, bool abajo, bool TeclaSp, bool TeclaCtr);
	// ----------------------------------------------------------------------------------------------------
	int get_oponente() { return tablero.Get_Oponente(); }

	int get_Jaques() {
		if (tablero.Get_JaqueMateBlancas())
			return 1;
		else if (tablero.Get_JaqueMateNegras())
			return 2;
		else if (tablero.Get_Tablas())
			return 3;
		return 0;
	}


};
