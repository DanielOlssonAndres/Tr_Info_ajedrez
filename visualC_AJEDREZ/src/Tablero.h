#pragma once

#include <iostream>
#include "vector2xy.h"
#include "Ficha.h"

#include "peon.h"
#include "torre.h"
#include "caballo.h"
#include "alfil.h"
#include "dama.h"
#include "rey.h"

struct CASILLA {
	// Par�metros gr�ficos de casilla
	int vx;
	int vy;
	int colR, colG, colB;
};

class Tablero
{
	int Tjuego;

	CASILLA Mcasillas[6][5]; // Para parte GR�FICA -> Indica posici�n de esquina de las casillas

	Ficha* MatTablero[6][5];

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
	void inicializa(const int& TJ);
	void dibuja();

<<<<<<< Updated upstream
	friend class Ficha;
};

=======
	void Tomar_Pieza(Vector2xy origen); //Obtener los �ndices de la pieza seleccionada seg�n la posici�n del rat�n
	void Soltar_Pieza(Vector2xy destino);  //Dejar la pieza en una posici�n seg�n la posici�n del rat�n
	// Comprobar si los movimientos son posibles seg�n la pieza que estemos moviendo
	bool Selec_Peon(int, int); 
	bool Selec_Rey(int, int);
	bool Selec_Dama(int, int);
	bool Selec_Torre(int, int);
	bool Selec_Caballo(int, int);
	bool Selec_Alfil(int, int);
	bool Selec_Mover(int, int); //Llama a la comprobaci�n correspondiente seg�n la pieza que seleccionemos
	void Selec_Jaque(); //Detecci�n de jaque y jaque mate

	void Consultar_Jaque(bool&, bool&, bool&, bool&); //Se encarga de indicar al programa si se produce jaque o jaque mate
	bool Consultar_Turno(); //Indica al programa de qui�n es el turno
	
};
>>>>>>> Stashed changes
