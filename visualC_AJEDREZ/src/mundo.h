#pragma once

#include "vector2xy.h"
#include "Tablero.h"

using namespace std;

enum { MOUSE_LEFT_BUTTON, MOUSE_MIDDLE_BUTTON, MOUSE_RIGHT_BUTTON };
enum { KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT };

class Mundo
{


	double x_ojo, y_ojo, z_ojo;
	double x_look, y_look, z_look;

	int Tjuego;
	Vector2xy PosEnCasillas[6][5];
	Vector2xy casillaSelec; //Vector que tiene la casilla seleccionada

	Tablero tablero;

	// VARIABLES PARA SELECCIÓN POR RATÓN----------------------------
	float width = 6; //Darle un valor al ancho de las casillas
	int xcell_sel, ycell_sel;	//casilla seleccionada con el ratón 
	bool leftButton;
	bool rightButton;
	bool midButton;
	// --------------------------------------------------------------

public:

	void inicializa();
	void dibuja();
	void MouseButton(int x, int y, int button, bool down, bool shiftKey, bool ctrlKey);
	int mov_raton();

	// FUNCIONES RELACIONADAS CON LA SELECCIÓN POR RATÓN---------------------------------------------------
	void centro_casilla(int cell_x, int cell_y, float& glx, float& gly);
	void world2cell(double x, double y, int& cell_x, int& cell_y);
	// ----------------------------------------------------------------------------------------------------

};