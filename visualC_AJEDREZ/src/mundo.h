#pragma once

#include "vector2xy.h"
#include "Tablero.h"

using namespace std;

enum { BOTON_RATON_IZQ, BOTON_RATON_MED, BOTON_RATON_DRCH};
enum { TECAL_ARRIBA, TECAL_ABAJO, TECLA_IZQ, TECLA_DRCH}; //SE PUEDE ELIMINAR

class Mundo
{

	double x_ojo, y_ojo, z_ojo;
	double x_look, y_look, z_look;

	int Tjuego;
	Vector2xy PosEnCasillas[6][5];
	

	

	// VARIABLES PARA SELECCIÓN POR RATÓN----------------------------
	float ancho = 6; //Darle un valor al ancho de las casillas
	/*int xcas_sel, ycas_sel;*/	//casilla seleccionada con el ratón 
	
	bool botonDrch;
	bool botonMed;
	// --------------------------------------------------------------

public:
	Vector2xy casillaSelec; //Vector que tiene la casilla seleccionada
	Tablero tablero;

	bool botonIzq;

	void inicializa();
	void dibuja();
	void MouseButton(int x, int y, int boton, bool abajo, bool TeclaSp, bool TeclaCtr);
	int mov_raton();

	// FUNCIONES RELACIONADAS CON LA SELECCIÓN POR RATÓN---------------------------------------------------
	void centro_casilla(int cas_x, int cas_y, float& glx, float& gly);
	void world2cell(double x, double y, int& cas_x, int& cas_y);
	// ----------------------------------------------------------------------------------------------------

};