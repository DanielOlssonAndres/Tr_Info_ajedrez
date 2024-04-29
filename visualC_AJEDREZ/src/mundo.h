#pragma once
#include <vector>
#include <string>

#include "vector2xy.h"
#include "Tablero.h"
#include "peon.h"
#include "torre.h"
#include "caballo.h"
#include "alfil.h"
#include "dama.h"
#include "rey.h"

using namespace std;

enum { MOUSE_LEFT_BUTTON, MOUSE_MIDDLE_BUTTON, MOUSE_RIGHT_BUTTON };
enum { KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT };

class Mundo
{
	double x_ojo, y_ojo, z_ojo;
	double x_look, y_look, z_look;

	int Tjuego;
	Vector2xy PosEnCasillas[6][5];

	Tablero tablero;
	//Fichas blancas
	Peon peonB1, peonB2, peonB3, peonB4, peonB5;
	Torre torreB;
	Caballo caballoB;
	Alfil alfilB;
	Dama damaB;
	Rey reyB;
	//Fichas negras
	Peon peonN1, peonN2, peonN3, peonN4, peonN5;
	Torre torreN;
	Caballo caballoN;
	Alfil alfilN;
	Dama damaN;
	Rey reyN;
	
	
public:
	void inicializa();
	void dibuja();
	void MouseButton(int x, int y, int button, bool down, bool shiftKey, bool ctrlKey);
	Vector2xy mov_raton();
	Vector2xy pos_cas;
	

	void centro_casilla(int cell_x, int cell_y, float& glx, float& gly) {
		//cell_x, cell_y coordenadas de las casillas en el tablero 
		//glx, gly se refieren al centro de las casillas 
		glx = cell_y * width + width / 2.0f;
		gly = -cell_x * width - width / 2.0f;
	}

	//coordenadas globales
	void world2cell(double x, double y, int& cell_x, int& cell_y) {
		//world coordinates to cell
		cell_x = (int)(abs(y / width));
		cell_y = (int)(x / width);
	}


protected:

	float width = 6; //Darle un valor al ancho de las casillas

	int xcell_sel, ycell_sel;	//casilla seleccionada con el ratón 

	//mouse+special-keys 
	//  
	bool controlKey;
	bool shiftKey;
	bool leftButton;
	bool rightButton;
	bool midButton;
};



