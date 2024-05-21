#pragma once

#include <iostream>
#include <vector>
#include "ETSIDI.h"
#include "vector2xy.h"
#include "Ficha.h"



struct CASILLA
{
	// Par�metros gr�ficos de casilla
	int vx;
	int vy;
	int colR, colG, colB;
};

class Tablero
{
private:

	int Tjuego;
	CASILLA Mcasillas[6][5];	// Para parte GR�FICA -> Indica posici�n de esquina de las casillas
	Vector2xy PosEnCasillas[6][5];	//Para parte GR�FICA -> Indica posici�n del centro de las casilas

	int matriz[6][5];           //std::vector<std::vector<int>> matriz;
	std::vector<Ficha> fichas;
	

	int pInd = -1, pI, pJ;
	bool color = true, jaqB = false, jaqMB = false, jaqN = false, jaqMN = false;


public:
	void inicializa(const int& TJ);
	void dibuja();
	//-------------------------------------
	//Tablero(const int& TJ);
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


	void Actualizar(int, int, bool);
	void Consultar_Jaque(bool&, bool&, bool&, bool&);
	bool Consultar_Turno();
	
};