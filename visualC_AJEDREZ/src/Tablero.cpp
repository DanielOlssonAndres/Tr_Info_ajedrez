#include <iostream>
#include <vector>
#include "freeglut.h"
#include "vector2xy.h"
#include "ETSIDI.h"

#include "Tablero.h"


void Tablero::inicializa(const int& TJ) {
	Tjuego = TJ;
	//Inicializamos la matriz de punteros tipo FICHA para gestión de movimientos
	//for (int i = 0; i < 6; i++) {
	//	for (int j = 0; j < 5; j++) {
	//		MatTablero[i][j] = nullptr;
	//	}
	//}

	//if (Tjuego == 0) { //Modalidad 5x6EO();
	//	//blancas
	//	MatTablero[0][4] = &reyB;
	//	reyB.inicializa({ 0, 4 }, BLANCAS);
	//	MatTablero[0][3] = &damaB;
	//	damaB.inicializa({ 0, 3 }, BLANCAS);
	//	MatTablero[0][2] = &alfilB;
	//	alfilB.inicializa({ 0, 2 }, BLANCAS);
	//	MatTablero[0][1] = &caballoB;
	//	caballoB.inicializa({ 0, 2 }, BLANCAS);
	//	MatTablero[0][0] = &torreB;
	//	torreB.inicializa({ 0, 0 }, BLANCAS);
	//	//negras
	//	MatTablero[5][0] = &reyN;
	//	reyN.inicializa({ 5, 0 }, NEGRAS);
	//	MatTablero[5][1] = &damaN;
	//	damaN.inicializa({ 5, 1 }, NEGRAS);
	//	MatTablero[5][2] = &alfilN;
	//	alfilN.inicializa({ 5, 2 }, NEGRAS);
	//	MatTablero[5][3] = &caballoN;
	//	caballoN.inicializa({ 5, 3 }, NEGRAS);
	//	MatTablero[5][4] = &torreN;
	//	torreN.inicializa({ 5, 4 }, NEGRAS);
	//}
	//else { //Modalidad PETTY
	//	//blancas
	//	MatTablero[0][1] = &reyB;
	//	reyB.inicializa({ 0, 1 }, BLANCAS);
	//	MatTablero[0][0] = &damaB;
	//	damaB.inicializa({ 0, 0 }, BLANCAS);
	//	MatTablero[0][2] = &alfilB;
	//	alfilB.inicializa({ 0, 2 }, BLANCAS);
	//	MatTablero[0][3] = &caballoB;
	//	caballoB.inicializa({ 0, 3 }, BLANCAS);
	//	MatTablero[0][4] = &torreB;
	//	torreB.inicializa({ 0, 4 }, BLANCAS);
	//	//negras
	//	MatTablero[5][1] = &reyN;
	//	reyN.inicializa({ 5, 1 }, NEGRAS);
	//	MatTablero[5][0] = &damaN;
	//	damaN.inicializa({ 5, 0 }, NEGRAS);
	//	MatTablero[5][2] = &alfilN;
	//	alfilN.inicializa({ 5, 2 }, NEGRAS);
	//	MatTablero[5][3] = &caballoN;
	//	caballoN.inicializa({ 5, 3 }, NEGRAS);
	//	MatTablero[5][4] = &torreN;
	//	torreN.inicializa({ 5, 4 }, NEGRAS);
	//}
	////peones blancos
	//MatTablero[1][0] = &peonB1;
	//peonB1.inicializa({ 1, 0 }, BLANCAS);
	//MatTablero[1][1] = &peonB2;
	//peonB2.inicializa({ 1, 1 }, BLANCAS);
	//MatTablero[1][2] = &peonB3;
	//peonB3.inicializa({ 1, 2 }, BLANCAS);
	//MatTablero[1][3] = &peonB4;
	//peonB4.inicializa({ 1, 3 }, BLANCAS);
	//MatTablero[1][4] = &peonB5;
	//peonB5.inicializa({ 1, 4 }, BLANCAS);
	////peones negros
	//MatTablero[4][0] = &peonN1;
	//peonN1.inicializa({ 4, 0 }, NEGRAS);
	//MatTablero[4][1] = &peonN2;
	//peonN2.inicializa({ 4, 1 }, NEGRAS);
	//MatTablero[4][2] = &peonN3;
	//peonN3.inicializa({ 4, 2 }, NEGRAS);
	//MatTablero[4][3] = &peonN4;
	//peonN4.inicializa({ 4, 3 }, NEGRAS);
	//MatTablero[4][4] = &peonN5;
	//peonN5.inicializa({ 4, 4 }, NEGRAS);

	//inicialización de las casillas del tablero
	bool m = FALSE;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 5; j++) {
			Mcasillas[i][j].vx = { j * 6 };
			Mcasillas[i][j].vy = { i * 6 };
			//PosEnCasillas[i][j] = { Mcasillas[i][j].vx + 3, Mcasillas[i][j].vy + 3 }; //para hallar el centro de las casillas
			if (m == FALSE) {
				Mcasillas[i][j].colR = { 0 }; //"NEGRA"
				Mcasillas[i][j].colG = { 0 }; //"NEGRA" 
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
	//CASILLAS
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 5; j++) {
			glBegin(GL_POLYGON);
			glColor3ub(Mcasillas[i][j].colR, Mcasillas[i][j].colG, Mcasillas[i][j].colB);
			glVertex3f(Mcasillas[i][j].vx, Mcasillas[i][j].vy, 0.0f);
			glVertex3f(Mcasillas[i][j].vx, Mcasillas[i][j].vy + 6, 0.0f);
			glVertex3f(Mcasillas[i][j].vx + 6, Mcasillas[i][j].vy + 6, 0.0f);
			glVertex3f(Mcasillas[i][j].vx + 6, Mcasillas[i][j].vy, 0.0f);
			glEnd();
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

	//Fichas
	/*for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 5; j++) {
			if (MatTablero[i][j] != nullptr) {
				MatTablero[i][j]->dibuja();
			}
		}
	}*/
}
Tablero::Tablero()
{
	//Poner las texturas del tablero
	matriz =
	{
		{-1,-2,-3,-4,-5},
		{-6,-6,-6,-6,-6},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{6, 6, 6, 6, 6},
		{5, 4, 3, 2, 1}
	};

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (matriz[i][j] != 0) {
				Ficha p(56 + j * 56, 56 + i * 56, matriz[i][j]);
				ficha.push_back(p);
			}
		}
	}
}


void Tablero::Tomar_Pieza(int x, int y) //posicion del raton
{

	if (color && ficha[pInd].Get_Valor() < 0) //Si es blanca y es el turno del negro 
		pInd = -1;
	else if (!color && ficha[pInd].Get_Valor() > 0) //Si es negra y es el turno del blanco 
		pInd = -1;
	if (pInd = -1) std::cout << "No puedes mover esa ficha en tu turno." << std::endl;

	if (pInd > 0) {
		pI = x;
		pJ = y;
		std::cout << "Se ha seleccionado la ficha" << std::endl;
	}
	
}

void Tablero::Soltar_Pieza(int x, int y) {
	bool flag = 1;
	int k, l;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 6; j++) {
			if (((color && matriz[i][j] <= 0) || (!color && matriz[i][j] >= 0) && Poder_Mover(i, j)) {
				ficha[pInd].Set_Posicion(i,j); //Se mueve la ficha a la nueva posicion
				//Cambiamos los valores de la matriz dejando la nueva casilla con la ficha y la otra dejandola en 0
				matriz[k][l] = matriz[pI][pJ];
				matriz[pI][pJ] = 0;
				matriz[i][j] =matriz[k][l];
				flag=0;
				
				for (int h = 0; h < (int)ficha.size(); h++) {
					int val = ficha[h].Get_Valor();
					if (ficha[h].Contener_Posicion(x, y) && ((color && val < 0) || (!color && val > 0)))//Si hay una ficha en la nueva posición se elimina
						delete ficha[h];
				}

				Selec_Jaque();

				if (color) color = false;
				else color = true;


			}
		}
	}
}