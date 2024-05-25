#include "mundo.h"
#include <iostream>
#include <vector>
#include "freeglut.h"
#include <ETSIDI.h>
#include "Tablero.h"
#include "Ficha.h"

using namespace std;

void Mundo::inicializa()
{
	// Punto de vista
	x_ojo = 15;
	y_ojo = 18;
	z_ojo = 60;
	x_look = 15;
	y_look = 18;
	z_look = 0;

	// Música de fondo 
	ETSIDI::play("sonidos/MusicaFondo.wav");

	tablero.inicializa(Tjuego);

}

void Mundo::dibuja()
{

	// dibujo de elementos
	tablero.dibuja();

	//INDICADOR DE TURNO
	if (tablero.Consulta_color(139,69,19)==TRUE)
	{
	
		ETSIDI::setTextColor(0, 0, 0);//negro
		ETSIDI::setFont("bin/fuentes/Arial.ttf", 10);
		ETSIDI::printxy("Turno: Tierra", -10, 22);
	}
	else {
		ETSIDI::setTextColor(1, 1, 1);//blanco
		ETSIDI::setFont("bin/fuentes/Arial.ttf", 10);
		ETSIDI::printxy("Turno: Agua", -10, 22);
	}

	//Titulos dentro de la pantalla de juego
	//fichas del mar
	ETSIDI::setTextColor(1, 1, 1);//blanco
	ETSIDI::setFont("bin/fuentes/Arial.ttf", 10);
	ETSIDI::printxy("Reina: ballena ", 33, 34);
	ETSIDI::printxy("Rey: tiburón ", 33, 32);
	ETSIDI::printxy("Caballo: caballito mar", 33, 30);
	ETSIDI::printxy("Alfil: pulpo", 33, 28);
	ETSIDI::printxy("Torre: cangrejo", 33, 26);
	ETSIDI::printxy("Peón: gambas", 33, 24);

	ETSIDI::setTextColor(0, 0, 0);//negro
	ETSIDI::setFont("bin/fuentes/Arial.ttf", 10);
	ETSIDI::printxy("Reina: leona ", 33, 12);
	ETSIDI::printxy("Rey: león ", 33, 10);
	ETSIDI::printxy("Caballo: cebra", 33, 8);
	ETSIDI::printxy("Alfil: pato ", 33, 6);
	ETSIDI::printxy("Torre: girafa", 33, 4);
	ETSIDI::printxy("Peón: conejos", 33, 2);
}

void Mundo::MouseButton(int x, int y, int boton, bool abajo, bool TeclaSp, bool TeclaCtr) {
	if (abajo) {

		GLint viewport[4];
		GLdouble modelview[16];
		GLdouble projection[16];
		GLfloat winX, winY, winZ;
		GLdouble posX, posY, posZ;

		glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
		glGetDoublev(GL_PROJECTION_MATRIX, projection);
		glGetIntegerv(GL_VIEWPORT, viewport);

		winX = (float)x;
		winY = (float)viewport[3] - (float)y;
		glReadPixels(x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);
		gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);

		if (posY >= 0 && posY <= 36 && posX >= 0 && posX <= 30) {
			if (boton == GLUT_LEFT_BUTTON) {

				CasillaOrigen.x = (int)(posY / ancho);
				CasillaOrigen.y = (int)(posX / ancho);
				tablero.Tomar_Pieza(CasillaOrigen);
			}

			if (boton == GLUT_RIGHT_BUTTON) {
				CasillaDestino.x = (int)(posY / ancho);
				CasillaDestino.y = (int)(posX / ancho);
				tablero.Soltar_Pieza(CasillaDestino);
			}
		}
	}

}

