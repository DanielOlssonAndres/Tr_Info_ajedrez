#include "mundo.h"
#include <iostream>
#include <vector>
#include "freeglut.h"
#include <ETSIDI.h>
#include "Tablero.h"
#include "Ficha.h"
#include <thread>  
#include <chrono>  

using namespace std;
void Mundo::inicializa(int tipo_juego, const int& tipo_oponente)
{

	tablero.inicializa(tipo_juego);
	tablero.Set_Oponente(tipo_oponente);

}
void Mundo::dibuja()
{
	// dibujo de elementos y avisos
	tablero.dibuja();

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


		if ((posY >= 0 && posY <= 36 && posX >= 0 && posX <= 30) || ((!tablero.Consultar_Turno()) && tipo_oponente == 1)) {
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
		
			}
		}
	}
	if (!abajo && tipo_oponente == 1 && !tablero.Consultar_Turno()) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		tablero.Auto_Mov();
	}
}

