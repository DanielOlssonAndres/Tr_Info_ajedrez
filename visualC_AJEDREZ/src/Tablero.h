#pragma once

#include <iostream>
#include <vector>
#include "ETSIDI.h"
#include "vector2xy.h"
#include "Ficha.h"



struct CASILLA
{
	// Parámetros gráficos de casilla
	int vx;
	int vy;
	int colR, colG, colB;
};

class Tablero
{
private:

	int Tjuego; //Tipo de juego al que vamos a jugar

	CASILLA Mcasillas[6][5];	// Para parte GRÁFICA -> Indica posición de esquina inferior izquierda de las casillas
	Vector2xy PosEnCasillas[6][5];	// Para parte GRÁFICA -> Indica posición del centro de las casilas
        
	std::vector<std::vector<int>> matriz;    //int matriz[6][5];
	std::vector<Ficha*> fichas;
	
	int pInd = -1; //Índice de la pieza que estamos seleccionando (-1 en caso de no seleccionar ninguna)
	int pI= -1, pJ= -1; //Guardar la posición de la pieza seleccionada
	bool color = true; //Indica de quién es el turno TRUE = BLANCAS (MARRÓN) / FALSE = NEGRAS (AZUL)
	bool jaqB = false, jaqMB = false, jaqN = false, jaqMN = false; //Identificación de Jaque y Jaque mate de NEGRAS y BLANCAS

	int colorR, colorG, colorB; //Para indicador de turno

public:
	void inicializa(const int& TJ);
	void dibuja();

	void Tomar_Pieza(Vector2xy origen); //Obtener los índices de la pieza seleccionada según la posición del ratón
	void Soltar_Pieza(Vector2xy destino);  //Dejar la pieza en una posición según la posición del ratón
	// Comprobar si los movimientos son posibles según la pieza que estemos moviendo
	bool Selec_Peon(int, int); 
	bool Selec_Rey(int, int);
	bool Selec_Dama(int, int);
	bool Selec_Torre(int, int);
	bool Selec_Caballo(int, int);
	bool Selec_Alfil(int, int);
	bool Selec_Mover(int, int); //Llama a la comprobación correspondiente según la pieza que seleccionemos
	void Selec_Jaque(); //Detección de jaque y jaque mate

	void Consultar_Jaque(bool&, bool&, bool&, bool&); //Se encarga de indicar al programa si se produce jaque o jaque mate
	bool Consultar_Turno(); //Indica al programa de quién es el turno

	
};