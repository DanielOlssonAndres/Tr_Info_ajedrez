#pragma once
#include "mundo.h"
#include "Tablero.h"
#include "ETSIDI.h"

enum { JUEGO = 0, INICIO, START, VS1_MENU, VS1_5x6_MENU, VS1_PETTY_MENU, VS1_5x6_INSTR, VS1_PETTY_INSTR };

class coordinador {
	
	int estado = 1;
	Mundo mundo;

public:
	void tecla(unsigned char key);
	void dibuja();
	void MouseButton(int x, int y, int boton, bool abajo, bool TeclaSp, bool TeclaCtr);
	int Get_Estado() { return estado; }

};

