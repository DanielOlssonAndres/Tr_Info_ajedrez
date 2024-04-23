#include <iostream>
#include <vector>
#include "freeglut.h"

#include "Tablero.h"
#include "Casilla.h"

void Tablero::inicializa() {
	bool m = FALSE;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 5; j++) {
			Mcasillas[i][j].vx = { j*6 };
			Mcasillas[i][j].vy = { i*6 };
			Mcasillas[i][j].PosF = { Mcasillas[i][j].vx + 3, Mcasillas[i][j].vy + 3 };
			if (m == FALSE) {
				Mcasillas[i][j].colR = { 139 }; //"NEGRA"
				Mcasillas[i][j].colG = { 69 }; //"NEGRA"
				Mcasillas[i][j].colB = { 19 }; //"NEGRA"
				m = TRUE;
			}
			else {
				Mcasillas[i][j].colR = { 255 }; //"BLANCA"
				Mcasillas[i][j].colG = { 204 }; //"BLANCA"
				Mcasillas[i][j].colB = { 153 }; //"BLANCA"
				m = FALSE;
			}
		}
	}
}


void Tablero::dibuja() 
{
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 5; j++) {
			Mcasillas[i][j].dibuja();
		}
	}

}

