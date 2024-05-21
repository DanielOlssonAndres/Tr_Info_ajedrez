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

	std::cout << "Seleccione Juego:" << std::endl;
	std::cout << "0. 5x6EO" << std::endl;
	std::cout << "1. PETTY" << std::endl;
	std::cin >> Tjuego;

	ETSIDI::play("sonidos/InicioJuego.wav");

	tablero.inicializa(Tjuego);

}

void Mundo::dibuja()
{
	// vista
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		x_look, y_look, z_look,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  

	// dibujo de elementos
	tablero.dibuja();

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

		if (boton == GLUT_LEFT_BUTTON) {
			CasillaOrigen.x = (int)(posY / ancho);
			CasillaOrigen.y = (int)(posX / ancho);
			tablero.Tomar_Pieza(CasillaOrigen);
		}

		if (boton == GLUT_RIGHT_BUTTON) {
			CasillaDestino.x = (int)(posY / ancho);
			CasillaDestino.y = (int)(posX / ancho);
			cout << "CASILLA DESTINO: (" << CasillaDestino.x << "," << CasillaDestino.y << ")" << endl;
			tablero.Soltar_Pieza(CasillaDestino);
		}
	}

}

