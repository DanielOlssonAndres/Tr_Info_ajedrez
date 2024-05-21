#include "mundo.h"
#include <iostream>
#include <vector>
#include "freeglut.h"

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

	// M�sica de fondo 
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

<<<<<<< Updated upstream
void Mundo::MouseButton(int x, int y, int button, bool down, bool sKey, bool ctrlKey) {
	// posicona el estado del raton y de las teclas
	GLint viewport[4];
	GLdouble modelview[16];
	GLdouble projection[16];
	GLfloat winX, winY, winZ;
	GLdouble posX, posY, posZ;
=======
void Mundo::MouseButton(int x, int y, int boton, bool abajo, bool TeclaSp, bool TeclaCtr) {
	if (abajo) {
>>>>>>> Stashed changes

		GLint viewport[4];
		GLdouble modelview[16];
		GLdouble projection[16];
		GLfloat winX, winY, winZ;
		GLdouble posX, posY, posZ;

		glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
		glGetDoublev(GL_PROJECTION_MATRIX, projection);
		glGetIntegerv(GL_VIEWPORT, viewport);

<<<<<<< Updated upstream
	world2cell(posX, posY, xcell_sel, ycell_sel);

	//Captura los movimientos del raton
	if (button == MOUSE_LEFT_BUTTON)
		leftButton = down;
	else if (button == MOUSE_RIGHT_BUTTON)
		rightButton = down;
	else if (button == MOUSE_MIDDLE_BUTTON)
		midButton = down;

	//escribir las coordenadas despues de hacer click
	if (down)
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

void Mundo::centro_casilla(int cell_x, int cell_y, float& glx, float& gly) {
	//cell_x, cell_y coordenadas de las casillas en el tablero 
	//glx, gly se refieren al centro de las casillas 
	glx = cell_y * width + width / 2.0f;
	gly = -cell_x * width - width / 2.0f;
}

void Mundo::world2cell(double x, double y, int& cell_x, int& cell_y) {
	//coordenadas globales a la casilla
	cell_x = (int)(y / width);
	cell_y = (int)(x / width);

	//guardo la posici�n de la casilla en un vector
	casillaSelec.x = cell_x;
	casillaSelec.y = cell_y;
}
=======
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

>>>>>>> Stashed changes
