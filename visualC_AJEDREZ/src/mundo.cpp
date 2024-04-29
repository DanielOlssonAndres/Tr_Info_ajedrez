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

	// Música de fondo 
	ETSIDI::play("sonidos/MusicaFondo.wav");

	std::cout << "Seleccione Juego:" << std::endl;
	std::cout << "0. 5x6EO" << std::endl;
	std::cout << "1. PETTY" << std::endl;
	std::cin >> Tjuego;

	ETSIDI::play("sonidos/InicioJuego.wav");

	tablero.inicializa();
	
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 5; j++) {
			PosEnCasillas[i][j] = { 3 + j * 6, 3 + i * 6 };
		}
	}

	//INICIALIZACIÓN DE FICHAS ESPECIALES
	if (Tjuego == 0) { //Modalidad 5x6EO();
		//Blancas
		reyB.inicializa(PosEnCasillas[0][4], BLANCAS);
		damaB.inicializa(PosEnCasillas[0][3], BLANCAS);
		alfilB.inicializa(PosEnCasillas[0][2], BLANCAS);
		caballoB.inicializa(PosEnCasillas[0][1], BLANCAS);
		torreB.inicializa(PosEnCasillas[0][0], BLANCAS);
		//Negras
		reyN.inicializa(PosEnCasillas[5][0], NEGRAS);
		damaN.inicializa(PosEnCasillas[5][1], NEGRAS);
		alfilN.inicializa(PosEnCasillas[5][2], NEGRAS);
		caballoN.inicializa(PosEnCasillas[5][3], NEGRAS);
		torreN.inicializa(PosEnCasillas[5][4], NEGRAS);
	}
	else { //Modalidad PETTY
		//Blancas
		reyB.inicializa(PosEnCasillas[0][1], BLANCAS);
		damaB.inicializa(PosEnCasillas[0][0], BLANCAS);
		alfilB.inicializa(PosEnCasillas[0][2], BLANCAS);
		caballoB.inicializa(PosEnCasillas[0][3], BLANCAS);
		torreB.inicializa(PosEnCasillas[0][4], BLANCAS);
		//Negras
		reyN.inicializa(PosEnCasillas[5][1], NEGRAS);
		damaN.inicializa(PosEnCasillas[5][0], NEGRAS);
		alfilN.inicializa(PosEnCasillas[5][2], NEGRAS);
		caballoN.inicializa(PosEnCasillas[5][3], NEGRAS);
		torreN.inicializa(PosEnCasillas[5][4], NEGRAS);
	}
	//INICIALIZACIÓN DE PEONES
	//Blancos
	peonB1.inicializa(PosEnCasillas[1][0], BLANCAS);
	peonB2.inicializa(PosEnCasillas[1][1], BLANCAS);
	peonB3.inicializa(PosEnCasillas[1][2], BLANCAS);
	peonB4.inicializa(PosEnCasillas[1][3], BLANCAS);
	peonB5.inicializa(PosEnCasillas[1][4], BLANCAS);
	//Negros
	peonN1.inicializa(PosEnCasillas[4][0], NEGRAS);
	peonN2.inicializa(PosEnCasillas[4][1], NEGRAS);
	peonN3.inicializa(PosEnCasillas[4][2], NEGRAS);
	peonN4.inicializa(PosEnCasillas[4][3], NEGRAS);
	peonN5.inicializa(PosEnCasillas[4][4], NEGRAS);
}

void Mundo::dibuja()
{
	// vista
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
		x_look, y_look, z_look,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  

	// dibujo de elementos
	tablero.dibuja();
	
	//Blancas
	reyB.dibuja();
	damaB.dibuja();
	alfilB.dibuja();
	caballoB.dibuja();
	torreB.dibuja();
	peonB1.dibuja();
	peonB2.dibuja();
	peonB3.dibuja();
	peonB4.dibuja();
	peonB5.dibuja();

	//Negras
	reyN.dibuja();
	damaN.dibuja();
	alfilN.dibuja();
	caballoN.dibuja();
	torreN.dibuja();
	peonN1.dibuja();
	peonN2.dibuja();
	peonN3.dibuja();
	peonN4.dibuja();
	peonN5.dibuja();

}

void Mundo::MouseButton(int x, int y, int button, bool down, bool sKey, bool ctrlKey) {
	/////////////////////////
	// posicona el estado del raton y de las teclas

	/////////
	//computa las coordenadas del raton

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

	//finally cell coordinates
	world2cell(posX, posY, xcell_sel, ycell_sel);

	///////////////////////////	
	//Captura los movimientos del raton


	if (button == MOUSE_LEFT_BUTTON)
		leftButton = down;
	else if (button == MOUSE_RIGHT_BUTTON)
		rightButton = down;
	else if (button == MOUSE_MIDDLE_BUTTON)
		midButton = down;
	///////////////////////////

		//*** Escribir acciones relacionadas al raton

		//escribir las coordenadas despues de hacer click
	if (down)
	{
		if (xcell_sel >= 0 && xcell_sel <= 5 && ycell_sel >= 0 && ycell_sel <= 4)
		{
			cout << "(" << xcell_sel << "," << ycell_sel << ")" << endl;   //!!!ESTO ES LO QUE SE ACABA ESCRIBIENDO Y GUARDANDO!!!!
		}
		else
		{
			std::cout << "El raton no se encuentra en el tablero." << std::endl;
		}
	}

}


// Lectura de donde se encuentra el raton

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