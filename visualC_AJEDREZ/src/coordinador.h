#pragma once
#include "mundo.h"
#include "Tablero.h"
#include "ETSIDI.h"

//enum Estado { juego = 0, inicio, vs1_menu, vsm_menu, start, vs1_5x6_menu, vs1_5x6_instr, vs1_petty_menu, vs1_petty_instr };

class coordinador
{
	
	int estado = 1;
	Mundo mundo;

public:
	void tecla(unsigned char key);
	void dibuja();
	void MouseButton(int x, int y, int boton, bool abajo, bool TeclaSp, bool TeclaCtr);
	void inicializa() { mundo.inicializa(); }
	int Get_Estado() { return estado; }

};

