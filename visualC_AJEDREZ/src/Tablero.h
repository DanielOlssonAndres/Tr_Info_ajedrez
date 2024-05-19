#pragma once

#include <iostream>
#include <vector>

#include "vector2xy.h"
#include "Ficha.h"


 struct MI_CASILLA {
	// Parámetros gráficos de casilla
	int vx;
	int vy;
	int colR, colG, colB;
};

class Tablero
{
	int Tjuego;

	MI_CASILLA Mcasillas[6][5];// Para parte GRÁFICA -> Indica posición de esquina de las casillas

	////Fichas blancas
	//Peon peonB1, peonB2, peonB3, peonB4, peonB5;
	//Torre torreB;
	//Caballo caballoB;
	//Alfil alfilB;
	//Dama damaB;
	//Rey reyB;
	////Fichas negras
	//Peon peonN1, peonN2, peonN3, peonN4, peonN5;
	//Torre torreN;
	//Caballo caballoN;
	//Alfil alfilN;
	//Dama damaN;
	//Rey reyN;

	std::vector<std::vector<int>> matriz;
	std::vector<Ficha> ficha;

	int pInd = -1, pI, pJ;
	bool color = true, jaqB = false, jaqMB = false, jaqN = false, jaqMN = false;
	void Tomar_Pieza(int, int);
	void Soltar_Pieza(int, int);

	bool Selec_Peon(int, int);
	bool Selec_Rey(int, int);
	bool Selec_Dama(int, int);
	bool Selec_Torre(int, int);
	bool Selec_Caballo(int, int);
	bool Selec_Alfil(int, int);
	bool Selec_Mover(int, int);
	void Selec_Jaque();

public:
	void inicializa(const int& TJ);
	void dibuja();
	//-------------------------------------
	Tablero(const int& TJ);
	void Actualizar(int, int, bool);
	void Consultar_Jaque(bool&, bool&, bool&, bool&);
	bool Consultar_Turno();

	
};