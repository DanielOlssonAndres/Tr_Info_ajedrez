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

void Mundo::MouseButton(int x, int y, int boton, bool abajo, bool TeclaSp, bool TeclaCtr) { // Probar si funciona eliminando los últimos bool
	// posicona el estado del raton y de las teclas
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

	world2cell(posX, posY, xcas_sel, ycas_sel);

	//Captura los movimientos del raton
	if (boton == BOTON_RATON_IZQ)
		botonIzq = abajo;
	else if (boton == BOTON_RATON_DRCH)
		botonDrch = abajo;
	else if (boton == BOTON_RATON_MED)
		botonMed = abajo;

	//escribir las coordenadas despues de hacer click
	if (abajo)
	{
		if (casillaSelec.x >= 0 && casillaSelec.x <= 5 && casillaSelec.y >= 0 && casillaSelec.y <= 4)
		{
			cout << "(" << casillaSelec.x << "," << casillaSelec.y << ")" << endl;
		}
		else
		{
			casillaSelec.x = 0;
			casillaSelec.y = 0;
			std::cout << "El raton no se encuentra en el tablero." << std::endl;
		}
	}
}

int Mundo::mov_raton() {

	POINT cursorPos;

	while (true)
	{
		// Obtener la posicion del cursor
		(GetCursorPos(&cursorPos));

		// Esperar un tiempo antes de volver a obtener la posicion del raton
		Sleep(200); // Espera 200 milisegundos (0.2 segundos)
	}

	return 0;
}

void Mundo::centro_casilla(int cas_x, int cas_y, float& glx, float& gly) {
	//cell_x, cell_y coordenadas de las casillas en el tablero 
	//glx, gly se refieren al centro de las casillas 
	glx = cas_y * ancho + ancho / 2.0f;
	gly = -cas_x * ancho - ancho / 2.0f;
}

void Mundo::world2cell(double x, double y, int& cas_x, int& cas_y) {
	//coordenadas globales a la casilla
	cas_x = (int)(y / ancho);
	cas_y = (int)(x / ancho);

	//guardo la posición de la casilla en un vector
	casillaSelec.x = cas_x;
	casillaSelec.y = cas_y;
}

