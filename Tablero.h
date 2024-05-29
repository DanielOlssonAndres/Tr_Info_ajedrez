#pragma once

#include <iostream>
#include <vector>
#include "ETSIDI.h"
#include "Ficha.h"
#include <vector2xy.h>



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

	int Tjuego, Toponente; //Tipo de juego al que vamos a jugar

	CASILLA Mcasillas[6][5];	// Para parte GRÁFICA -> Indica posición de esquina inferior izquierda de las casillas
	Vector2xy PosEnCasillas[6][5];	// Para parte GRÁFICA -> Indica posición del centro de las casilas

	// i = FILAS , j = COLUMNAS		[filas][columnas]

	enum {REY = 1, DAMA, ALFIL, CABALLO, TORRE, PEON};
        
	std::vector<std::vector<int>> matriz;    //int matriz[6][5];
	std::vector<Ficha*> fichas;
	
	int pInd = -1; //Índice de la pieza que estamos seleccionando (-1 en caso de no seleccionar ninguna)
	int pI= -1, pJ= -1; //Guardar la posición de la pieza seleccionada
	bool color = true; //Indica de quién es el turno TRUE = BLANCAS (MARRÓN) / FALSE = NEGRAS (AZUL)
	bool jaqB = false, jaqMB = false, jaqN = false, jaqMN = false; //Identificación de Jaque y Jaque mate de NEGRAS y BLANCAS

	int colorR, colorG, colorB; //Para indicador de turno
	int colorJR, colorJG, colorJB; //Para indicar el turno

public:
	void inicializa(const int& TJ);
	void dibuja();

	void Tomar_Pieza_1VS1(Vector2xy origen); //Obtener los índices de la pieza seleccionada según la posición del ratón
	void Soltar_Pieza_1VS1(Vector2xy destino);  //Dejar la pieza en una posición según la posición del ratón

	void Tomar_Pieza_VSMAQ(Vector2xy origen); //Obtener los índices por raton o IA
	void Soltar_Pieza_VSMAQ(Vector2xy destino);  //Dejar la pieza por raton o IA

	// Comprobar si los movimientos son posibles según la pieza que estemos moviendo
	bool Selec_Peon(int, int); 
	bool Selec_Rey(int, int);
	bool Selec_Dama(int, int);
	bool Selec_Torre(int, int);
	bool Selec_Caballo(int, int);
	bool Selec_Alfil(int, int);
	bool Selec_Mover(int, int, bool); //Llama a la comprobación correspondiente según la pieza que seleccionemos
	void Selec_Jaque(); //Detección de jaque y jaque mate

	bool Consulta_color(int R, int G, int B);
	void Consultar_Jaque(); //Se encarga de indicar al programa si se produce jaque o jaque mate
	bool Consultar_Turno(); //Indica al programa de quién es el turno
	bool Mirar_Jaque(int iR, int jR);
	void Promocion(int, int, int, Vector2xy);

	void Set_Oponente(const int& TIPO_OPO) { Toponente = TIPO_OPO; }
	int Get_Oponente() { return Toponente; }


	int Consulta_Oponente(){ return Toponente; }

	bool Jaque(bool col);
};
