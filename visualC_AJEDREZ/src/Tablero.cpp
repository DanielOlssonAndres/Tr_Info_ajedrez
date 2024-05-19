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
Tablero::Tablero(const int& TJ)
{
	Tjuego = TJ;

	//Poner las texturas del tablero
	//Este sería el tablero del 5x6

	if (Tjuego == 0) { //Modalidad 5x6EO();
		matriz =
		{
			{-1,-2,-3,-4,-5},
			{-6,-6,-6,-6,-6},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{6, 6, 6, 6, 6},
			{5, 4, 3, 2, 1}
		};
	}
	else {//Modalidad PETTY
		matriz =
		{
			{-2,-1,-3,-4,-5},
			{-6,-6,-6,-6,-6},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{6, 6, 6, 6, 6},
			{2, 1, 3, 4, 5}
		};
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (matriz[i][j] != 0) {
				Ficha p (56 + j * 56, 56 + i * 56, matriz[i][j]);
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
			if (((color && matriz[i][j] <= 0) || (!color && matriz[i][j] >= 0) && Poder_Mover(i, j))) {
				ficha[pInd].Set_Posicion(i,j); //Se mueve la ficha a la nueva posicion
				//Cambiamos los valores de la matriz dejando la nueva casilla con la ficha y la otra dejandola en 0
				matriz[k][l] = matriz[pI][pJ];
				matriz[pI][pJ] = 0;
				matriz[i][j] =matriz[k][l];
				flag=0;
				
				for (int h = 0; h < (int)ficha.size(); h++) { //Si hay una ficha en la nueva posición se elimina
					int val = ficha[h].Get_Valor();
					if (ficha[h].Contener_Posicion(x, y) && ((color && val < 0) || (!color && val > 0)))
						delete ficha[h];
				}

				Selec_Jaque();
				//Cambio de turno
				if (color) color = false;
				else color = true;
			}
		}
	}
	pInd = -1;
}

//Creo que esta no hace falta pero la dejo por si nos puede servir
void Tablero::Actualizar(int x, int y, bool presionado) { 
	Selec_Jaque();
	if (pInd != -1 && presionado) {
		ficha[pInd].Set_Posicion(x, y);
	}
	else if (pInd != -1 && !presionado) {
		Soltar_Pieza(x,y);
	}
	else if (pInd == -1 && presionado) {
		Tomar_Pieza(x, y);
	}
}

bool Tablero::Selec_Peon(int i, int j) {
	if (color) {
		if (matriz[i][j] == 0 && pI - i == 1 && j == pJ) return true;
		else if (matriz[i][j] == 0 && pI - i == 2 && j == pJ && pI == 6 && matriz[i + 1][j] == 0) return true;
		else if (matriz[i][j] > 0 && pI - i == -1 && abs(j - pJ) == 1)return true;
	}
	return false;
}

bool Tablero::Selec_Rey(int i, int j) {
	if (color) {
		if (matriz[i][j] == 0 && abs(pI - i)<= 1 && abs(pJ-j)<=0) return true;
		else {
			if (abs(pI - i) <= 1 && abs(pJ - j) && matriz[i][j] >= 0) return true;
		}
	}
	return false;
}

bool Tablero::Selec_Caballo(int i, int j) {
	if (color) {
		if (matriz[i][j] <= 0 && ((abs(pI - i) == 2 && abs(pJ - j) == 1) || (abs(pI - i) == 1) && abs(pJ - j) == 2));
	}
	else {
		if (matriz[i][j] >= 0 && ((abs(pI - i) == 2 && abs(pJ - j) == 1) || (abs(pI - i) == 1) && abs(pJ - j) == 2));
	}
}

bool Tablero::Selec_Torre(int i, int j) {
	if (pJ == j) {
		for (int I = std::min(pI, i) + 1; I < std::max(pI, i); I++) {
			if (matriz[I][pJ] != 0) return false;
		}
		if (color && matriz[i][j] <= 0) return true;
		else if (!color && matriz[i][j] >= 0)return true;
	}
	else if (pI == i) {
		for (int J = std::min(pJ, j) + 1; J < std::max(pJ, j); J++) {
			if (matriz[pI][J] != 0) return false;
		}
		if (color && matriz[i][j] <= 0) return true;
		else if (!color && matriz[i][j] >= 0) return true;
	}
	return false;
}

bool Tablero::Selec_Alfil(int i, int j) {
	if (abs(pJ - j) == abs(pI - i)) {
		int difI = (pI - i < 0 ? 1 : -1);
		int difJ = (pJ - j < 0 ? 1 : -1);
		int I = pI;
		int J = pJ;

		while (I != i - difI && J != j - difJ) {
			I += difI;
			J += difJ;
			if (matriz[I][J] != 0)return false;
		}
		if (color && matriz[i][j] <= 0) return true;
		else if (!color && matriz[i][j] >= 0)return true;
	}
	return false;
}

bool Tablero::Selec_Dama(int i, int j) {
	if (Selec_Torre(i, j) || Selec_Alfil(i, j))return true;
	return false;
}

bool Tablero::Selec_Mover(int i, int j) {

	switch (abs(matriz[pI][pJ])) {
	case 6: return Selec_Peon(i, j); break;
	case 1: return Selec_Rey(i, j); break;
	case 2: return Selec_Dama(i, j); break;
	case 3: return Selec_Alfil(i, j); break;
	case 4: return Selec_Caballo(i, j); break;
	case 5: return Selec_Torre(i, j); break;
	}
	return false;
}

void Tablero::Selec_Jaque() {
	int iR = -1, jR = -1;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 6; j++) {
			if ((color && matriz[i][j] == -5) || (!color && matriz[i][j] == 5)) {
				iR = i; jR = j;
			}
		}
	}

	int npI = pI; int npJ = pJ;
	bool jaq = false;
	for (int i = 0; i < 5; i++) 
	{
		for (int j = 0; j < 6; j++){
			if ((color && matriz[i][j] < 0) || (!color && matriz[i][j < 0])) continue;
			pI = i; pJ = j;
			if(Selec_Mover(iR,jR))
			{
				jaq = true;
				if(color){
					if (jaqN) jaqMN = true;
					jaqN = true;
				}
				else{
					if (jaqB) jaqMB = true;
					jaqB = true;
				}

			}
		}
	}
	pI = npI; pJ = npJ;
	if (color && !jaq) jaqB = false;
	else if (!jaq) jaqN = false;
}

void Tablero::Consultar_Jaque(bool& jB, bool& jN, bool& jMB, bool& jMN) {
	jB = jaqB;
	jN = jaqN;
	jMB = jaqMB;
	jMN = jaqMN;
}

bool Tablero::Consultar_Turno(){
	return color;
}

