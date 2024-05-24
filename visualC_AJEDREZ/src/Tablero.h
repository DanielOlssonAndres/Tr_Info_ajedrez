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

	int Tjuego; //Tipo de juego al que vamos a jugar

	CASILLA Mcasillas[6][5];	// Para parte GR�FICA -> Indica posici�n de esquina inferior izquierda de las casillas
	Vector2xy PosEnCasillas[6][5];	// Para parte GR�FICA -> Indica posici�n del centro de las casilas
        
	std::vector<std::vector<int>> matriz;    //int matriz[6][5];
	std::vector<Ficha*> fichas;
	
	int pInd = -1; //�ndice de la pieza que estamos seleccionando (-1 en caso de no seleccionar ninguna)
	int pI= -1, pJ= -1; //Guardar la posici�n de la pieza seleccionada
	bool color = true; //Indica de qui�n es el turno TRUE = BLANCAS (MARR�N) / FALSE = NEGRAS (AZUL)
	bool jaqB = false, jaqMB = false, jaqN = false, jaqMN = false; //Identificaci�n de Jaque y Jaque mate de NEGRAS y BLANCAS

	int colorR, colorG, colorB; //Para indicador de turno

public:
	void inicializa(const int& TJ);
	void dibuja();

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