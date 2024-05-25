#pragma once
#include "mundo.h"
#include "Tablero.h"
#include "ETSIDI.h"

enum {JUEGO = 0, INICIO, MENU_1VS1, MENU_MAQUINA, ELECCION_ADVERSARIO, MENU_5X6, INSTRUCCIONES_5X6, MENU_PETTY, INSTRUCCIONES_PETTY};

class coordinador {
	
	int estado = 1;
	Mundo mundo;

public:
	void tecla(unsigned char key);
	void dibuja();
	void MouseButton(int x, int y, int boton, bool abajo, bool TeclaSp, bool TeclaCtr);
	void inicializa() { mundo.inicializa(); }
	int Get_Estado() { return estado; }

};

