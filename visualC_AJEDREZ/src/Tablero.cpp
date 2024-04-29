#include <iostream>
#include <vector>
#include "freeglut.h"
#include "vector2xy.h"
#include "ETSIDI.h"

#include "Tablero.h"
#include "Casilla.h"

void Tablero::inicializa() {
	bool m = FALSE;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 5; j++) {
			Mcasillas[i][j].vx = { j*6 };
			Mcasillas[i][j].vy = { i*6 };
			//CentroCasillas[i][j] = { Mcasillas[i][j].vx + 3, Mcasillas[i][j].vy + 3 }; //para hallar el centro de las casillas
			if (m == FALSE) {
				Mcasillas[i][j].colR = { 0 }; //"NEGRA"
				Mcasillas[i][j].colG = { 0}; //"NEGRA" 
				Mcasillas[i][j].colB = { 0 }; //"NEGRA"
				m = TRUE;
			}
			else {
				Mcasillas[i][j].colR = { 255 }; //"BLANCA"
				Mcasillas[i][j].colG = { 255 }; //"BLANCA"
				Mcasillas[i][j].colB = { 255 }; //"BLANCA"
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

	//FONDO
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,
		ETSIDI::getTexture("bin/imagenes/FONDO_V1.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex2d(-15, -4); //inferior izquierda
	glTexCoord2d(1, 1); glVertex2d(45, -4); //Inferior derecha
	glTexCoord2d(1, 0); glVertex2d(45, 40); //Superior derecha
	glTexCoord2d(0, 0); glVertex2d(-15, 40); //Superior izquierda
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

}

void Tablero::casilla(Vector2xy casilla) 
{
	
	

}