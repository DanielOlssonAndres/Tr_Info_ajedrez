#include "mundo.h"
#include <iostream>
#include <vector>
#include "freeglut.h"
#include <ETSIDI.h>
#include "Tablero.h"
#include "Ficha.h"

using namespace std;
void Mundo::inicializa(int tipo_juego, const int& tipo_oponente)
{

	tablero.inicializa(tipo_juego);
	tablero.Set_Oponente(tipo_oponente);

}
void Mundo::dibuja()
{

	// dibujo de elementos
	tablero.dibuja();

	//INDICADOR DE TURNO
	if (tablero.Consulta_color(139, 69, 19) == TRUE)
	{

		ETSIDI::setTextColor(1, 1, 1);//negro
		ETSIDI::setFont("fuentes/Arial.ttf", 10);
		ETSIDI::printxy("Tierra", -9, 17);
	}
	else {
		ETSIDI::setTextColor(1, 1, 1);//blanco
		ETSIDI::setFont("fuentes/Arial.ttf", 10);
		ETSIDI::printxy("Agua", -9, 17);
	}
	
	//INDICADOR DE JAQUE
	if (tablero.Consulta_color(0, 0, 0) == TRUE)
	{

		ETSIDI::setTextColor(1, 1, 1);//blanco
		ETSIDI::setFont("fuentes/Arial.ttf", 10);
		ETSIDI::printxy("No hay Jaque", -10.5, 8);
	}
	else {
		ETSIDI::setTextColor(0, 0, 0);//negro
		ETSIDI::setFont("fuentes/Arial.ttf", 10);
		ETSIDI::printxy("Si hay Jaque", -10.5, 8);
	}



	//Titulos dentro de la pantalla de juego
	//fichas del mar
	/*ETSIDI::setTextColor(1, 1, 1);//blanco
	ETSIDI::setFont("fuentes/Arial.ttf", 10);
	ETSIDI::printxy("Reina: ballena ", 33, 34);
	ETSIDI::printxy("Rey: tiburón ", 33, 32);
	ETSIDI::printxy("Caballo: caballito mar", 33, 30);
	ETSIDI::printxy("Alfil: pulpo", 33, 28);
	ETSIDI::printxy("Torre: cangrejo", 33, 26);
	ETSIDI::printxy("Peón: gambas", 33, 24);

	ETSIDI::setTextColor(0, 0, 0);//negro
	ETSIDI::setFont("fuentes/Arial.ttf", 10);
	ETSIDI::printxy("Reina: leona ", 33, 12);
	ETSIDI::printxy("Rey: león ", 33, 10);
	ETSIDI::printxy("Caballo: cebra", 33, 8);
	ETSIDI::printxy("Alfil: pato ", 33, 6);
	ETSIDI::printxy("Torre: girafa", 33, 4);
	ETSIDI::printxy("Peón: conejos", 33, 2);*/
}

void Mundo::MouseButton(int tipo_oponente, int x, int y, int boton, bool abajo, bool TeclaSp, bool TeclaCtr) 
{

	tipo_oponente = tablero.Get_Oponente();

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


		if ((posY >= 0 && posY <= 36 && posX >= 0 && posX <= 30) || (tablero.Consultar_Turno() == false) && tipo_oponente == 1) {
			if (tipo_oponente == 0) {
				if (boton == GLUT_LEFT_BUTTON) {

					CasillaOrigen.x = (int)(posY / ancho);
					CasillaOrigen.y = (int)(posX / ancho);
					tablero.Tomar_Pieza_1VS1(CasillaOrigen);
				}

				if (boton == GLUT_RIGHT_BUTTON) {
					CasillaDestino.x = (int)(posY / ancho);
					CasillaDestino.y = (int)(posX / ancho);
					tablero.Soltar_Pieza_1VS1(CasillaDestino);
				}

			}

			if (tipo_oponente == 1){
				if (tablero.Consultar_Turno() == true)
				{
					if (boton == GLUT_LEFT_BUTTON) {

						CasillaOrigen.x = (int)(posY / ancho);
						CasillaOrigen.y = (int)(posX / ancho);
						tablero.Tomar_Pieza_1VS1(CasillaOrigen);
					}

					if (boton == GLUT_RIGHT_BUTTON) {
						CasillaDestino.x = (int)(posY / ancho);
						CasillaDestino.y = (int)(posX / ancho);
						tablero.Soltar_Pieza_1VS1(CasillaDestino);
					}
				}

				if (tablero.Consultar_Turno() == false) {
					tablero.Tomar_Pieza_VSMAQ();
					tablero.Soltar_Pieza_VSMAQ();
				}
				
			}
		}
	}
}

