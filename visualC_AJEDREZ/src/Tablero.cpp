
#include "freeglut.h"
#include "Tablero.h"
#include "mundo.h"
#include <thread>  
#include <chrono>

bool Tablero::Consulta_color(int R, int G, int B) {
	R = colorR;
	G = colorG;
	B = colorB;

	if (((R==139)&&(G==69)&&(B==19)) || ((R == 0) && (G == 0) && (B == 0)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Tablero::dibuja()
{

	//CASILLAS
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 5; j++) {
			glBegin(GL_POLYGON);
			int C_R = Mcasillas[i][j].colR;
			if (pInd >= 0) {
				if (fichas[pInd]->Get_PosicionX() == i && fichas[pInd]->Get_PosicionY() == j)C_R = 100;
			}
			glColor3ub(C_R, Mcasillas[i][j].colG, Mcasillas[i][j].colB);
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
		ETSIDI::getTexture("imagenes/FONDO_V1.png").id);
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
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 5; j++) {
			if (matriz[i][j] == -REY) {
				ETSIDI::Sprite sprite = { "imagenes/A_REY_TIBURON.png" };
				glPushMatrix();
				glTranslatef(PosEnCasillas[i][j].x - 3, PosEnCasillas[i][j].y - 3, 1);
				sprite.setSize(5, 5);
				sprite.draw();
				glPopMatrix();
			}
			if (matriz[i][j] == -DAMA) {
				ETSIDI::Sprite sprite = { "imagenes/A_DAMA_BALLENA.png" };
				glPushMatrix();
				glTranslatef(PosEnCasillas[i][j].x - 3, PosEnCasillas[i][j].y - 3, 1);
				sprite.setSize(5, 5);
				sprite.draw();
				glPopMatrix();
			}
			if (matriz[i][j] == -ALFIL) {
				ETSIDI::Sprite sprite = { "imagenes/A_ALFIL_PULPO.png" };
				glPushMatrix();
				glTranslatef(PosEnCasillas[i][j].x - 3, PosEnCasillas[i][j].y - 3, 1);
				sprite.setSize(5, 5);
				sprite.draw();
				glPopMatrix();
			}
			if (matriz[i][j] == -CABALLO) {
				ETSIDI::Sprite sprite = { "imagenes/A_CABALLO_CABALLITO_DE_MAR.png" };
				glPushMatrix();
				glTranslatef(PosEnCasillas[i][j].x - 3, PosEnCasillas[i][j].y - 3, 1);
				sprite.setSize(5, 5);
				sprite.draw();
				glPopMatrix();
			}
			if (matriz[i][j] == -TORRE) {
				ETSIDI::Sprite sprite = { "imagenes/A_TORRES_CANGREJO.png" };
				glPushMatrix();
				glTranslatef(PosEnCasillas[i][j].x - 3, PosEnCasillas[i][j].y - 3, 1);
				sprite.setSize(5, 5);
				sprite.draw();
				glPopMatrix();
			}
			if (matriz[i][j] == -PEON) {
				ETSIDI::Sprite sprite = { "imagenes/A_PEON_GAMBA.png" };
				glPushMatrix();
				glTranslatef(PosEnCasillas[i][j].x - 3, PosEnCasillas[i][j].y - 3, 1);
				sprite.setSize(5, 5);
				sprite.draw();
				glPopMatrix();
			}
			if (matriz[i][j] == REY) {
				ETSIDI::Sprite sprite = { "imagenes/T_REY_LEON.png" };
				glPushMatrix();
				glTranslatef(PosEnCasillas[i][j].x - 3, PosEnCasillas[i][j].y - 3, 1);
				sprite.setSize(5, 5);
				sprite.draw();
				glPopMatrix();
			}
			if (matriz[i][j] == DAMA) {
				ETSIDI::Sprite sprite = { "imagenes/T_DAMA_LEONA.png" };
				glPushMatrix();
				glTranslatef(PosEnCasillas[i][j].x - 3, PosEnCasillas[i][j].y - 3, 1);
				sprite.setSize(5, 5);
				sprite.draw();
				glPopMatrix();
			}
			if (matriz[i][j] == ALFIL) {
				ETSIDI::Sprite sprite = { "imagenes/T_ALFIL_PATO.png" };
				glPushMatrix();
				glTranslatef(PosEnCasillas[i][j].x - 3, PosEnCasillas[i][j].y - 3, 1);
				sprite.setSize(5, 5);
				sprite.draw();
				glPopMatrix();
			}
			if (matriz[i][j] == CABALLO) {
				ETSIDI::Sprite sprite = { "imagenes/T_CABALLO_CEBRA.png" };
				glPushMatrix();
				glTranslatef(PosEnCasillas[i][j].x - 3, PosEnCasillas[i][j].y - 3, 1);
				sprite.setSize(5, 5);
				sprite.draw();
				glPopMatrix();
			}
			if (matriz[i][j] == TORRE) {
				ETSIDI::Sprite sprite = { "imagenes/T_TORRE_GIRAFA.png" };
				glPushMatrix();
				glTranslatef(PosEnCasillas[i][j].x - 3, PosEnCasillas[i][j].y - 3, 1);
				sprite.setSize(5, 5);
				sprite.draw();
				glPopMatrix();
			}
			if (matriz[i][j] == PEON) {
				ETSIDI::Sprite sprite = { "imagenes/T_PEON_CONEJO_2.png" };
				glPushMatrix();
				glTranslatef(PosEnCasillas[i][j].x - 3, PosEnCasillas[i][j].y - 3, 1);
				sprite.setSize(5, 5);
				sprite.draw();
				glPopMatrix();
			}

		}
	}

	//INDICADOR DE TURNO 
	glPushMatrix();
	if (!color) {
		colorR = 0;
		colorG = 105;
		colorB = 148;
	}
	else {
		colorR = 139;
		colorG = 69;
		colorB = 19;
	}

	glTranslatef(-7, 21.5, 1);
	glColor3ub(colorR, colorG, colorB);
	glutSolidSphere(3, 30, 30);
	glPopMatrix();


	if (color)
	{
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Arial.ttf", 12);
		ETSIDI::printxy("TIERRA", -10, 17);
	}
	if (!color) {
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Arial.ttf", 12);
		ETSIDI::printxy("AGUA", -10, 17);
	}

	//INDICADOR DE JAQUE
	Tablero::Comprobar_Jaque();
	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("fuentes/Arial.ttf", 12);

	if (jaqB) {
		if (jaqMB) {
			ETSIDI::printxy("JAQUE MATE", -12, 9);
			ETSIDI::printxy("A TIERRA", -11.5, 7);
		}
		else
			ETSIDI::printxy("Jaque a Tierra", -12, 8);
	}

	if (jaqN && !jaqB) {
		if (jaqMN) {
			ETSIDI::printxy("JAQUE MATE", -12, 9);
			ETSIDI::printxy("A AGUA", -11.5, 7);
		}
		else
			ETSIDI::printxy("JAQUE a Agua", -12, 8);
	}

	if (tablas) {
		ETSIDI::printxy("TABLAS", -12, 8);
	}

	if (!jaqB && !jaqN && !jaqMB && !jaqMN) {
		ETSIDI::printxy("No hay amenazas", -12, 9);
		ETSIDI::printxy("a los reyes", -10.95, 7);
	}
}



void Tablero::inicializa(const int& TJ)
{
	Tjuego = TJ;

	bool m = false;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 5; j++) {
			Mcasillas[i][j].vx = { j * 6 };
			Mcasillas[i][j].vy = { i * 6 };
			PosEnCasillas[i][j] = { Mcasillas[i][j].vx + 3, Mcasillas[i][j].vy + 3 }; //para hallar el centro de las casillas
			if (m == false) {
				Mcasillas[i][j].colR = { 0 }; //"NEGRA"
				Mcasillas[i][j].colG = { 0 }; //"NEGRA" 
				Mcasillas[i][j].colB = { 0 }; //"NEGRA"
				m = true;
			}
			else {
				Mcasillas[i][j].colR = { 255 }; //"BLANCA"
				Mcasillas[i][j].colG = { 255 }; //"BLANCA"
				Mcasillas[i][j].colB = { 255 }; //"BLANCA"
				m = false;
			}
		}
	}

	if (Tjuego == 0) { //Modalidad 5x6EO
		matriz =
		{
			{ TORRE, CABALLO, ALFIL, DAMA, REY },				// BLANCAS
			{ PEON, PEON, PEON, PEON, PEON },				// BLANCAS
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ -PEON, -PEON, -PEON, -PEON, -PEON },		// NEGRAS
			{ -REY, -DAMA, -ALFIL, -CABALLO, -TORRE }		// NEGRAS

		};
	}
	else { //Modalidad PETTY
		
		matriz =
		{
			{ DAMA, REY, ALFIL, CABALLO, TORRE },				// BLANCAS
			{ PEON, PEON, PEON, PEON, PEON },				// BLANCAS
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ -PEON, -PEON, -PEON, -PEON, -PEON },		// NEGRAS
			{ -DAMA, -REY, -ALFIL, -CABALLO, -TORRE }		// NEGRAS
		};

	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (matriz[i][j] != 0) {
				Ficha* p = new Ficha(i, j, matriz[i][j]); 
				fichas.push_back(p);
			}
		}
	}

	// Inicialización de las variables
	pIA_x = -1, pIA_y = -1;
	pInd = -1;
	pI = -1, pJ = -1;
	pI_IA = 0, pJ_IA = 0;
	color = true;
	jaqB = false, jaqMB = false, jaqN = false, jaqMN = false, tablas = false;

}


void Tablero::Tomar_Pieza_1VS1(Vector2xy origen) //posicion del raton -> origen
{
	pInd = -1;

	if (matriz[origen.x][origen.y] != 0) { //Si hemos seleccionado una casilla con ficha
		for (int z = 0; z < static_cast<int>(fichas.size()); z++) { //Buscamos la ficha que estamos seleccionando y guardamos su índice del vector en pInd
			if (fichas[z]->Get_PosicionX() == origen.x && fichas[z]->Get_PosicionY() == origen.y) {
				pInd = z;
				break;
			}
		}
		if (pInd != -1) {
			if ((color && fichas[pInd]->Get_Valor() < 0) || (!color && fichas[pInd]->Get_Valor() > 0)) { //Si la pieza no corresponde con el color del turno
				pInd = -1;
				ETSIDI::play("sonidos/SonidoError.wav");
			}

			if (pInd != -1) {
				pI = origen.x;
				pJ = origen.y;

			}
		}
	}
}

void Tablero::Soltar_Pieza_1VS1(Vector2xy destino) //posición del ratón -> destino
{

	if (pInd != -1) { // Si es una casilla permitida

		//Si el movimiento que quieres hacer está permitido 
		if (((color && matriz[destino.x][destino.y] <= 0) || (!color && matriz[destino.x][destino.y] >= 0)) && Selec_Mover(destino.x, destino.y, true)) { //CAMBIAR  Selec_Mover por TRUE PARA DESHABILITAR LAS LIMITACIONES DE MOVIMIENTO

			ETSIDI::play("sonidos/MoverFicha.wav");

			//Código que haga que si hay una ficha del otro color en el destino, que se elimine (comer)
			if ((color && matriz[destino.x][destino.y] < 0) || (!color && matriz[destino.x][destino.y] > 0)) {

				for (int z = 0; z < static_cast<int>(fichas.size()); z++) {
					if (fichas[z]->Get_PosicionX() == destino.x && fichas[z]->Get_PosicionY() == destino.y) {
						ETSIDI::play("sonidos/ComerFicha.wav");

						delete fichas[z];
						if (z < pInd) pInd--;
						fichas.erase(fichas.begin() + z);
					}
				}

			}


			fichas[pInd]->Set_Posicion(destino.x, destino.y);

			Promocion (pInd,pI,pJ, destino);//Verificar si un peón ha llegado a la última casilla

			//Actualización de los valores
			matriz[destino.x][destino.y] = matriz[pI][pJ];
			matriz[pI][pJ] = 0;

			Comprobar_Jaque();				// Comprobar si el contrario esta en jaque

			//Cambio de turno
			if (color) color = false;		// Ahora es turno de las NEGRAS
			else color = true;				// Ahora es turno de las BLANCAS 

			Comprobar_JaqueMate();			// Comprobar si el contrario esta en jaque mate

		}
		else
			ETSIDI::play("sonidos/SonidoError.wav");

	}

	pInd = -1;
}

void Tablero::Auto_Mov() {

	bool flag = false;
	
		for (int i = 0; i < 6 && !flag; i++) {
			for (int j = 4; j >= 0 && !flag; j--) {

				if (matriz[i][j] < 0) {
					pI = i;
					pJ = j;
					for (int z = 0; z < static_cast<int>(fichas.size()); z++) { //Buscamos la ficha que estamos seleccionando y guardamos su índice del vector en pInd
						if (fichas[z]->Get_PosicionX() == pI && fichas[z]->Get_PosicionY() == pJ) {
							pInd = z;
							break;
						}
					}

					for (int l = 0; l < 6 && !flag; l++) {
						for (int k = 0; k < 5 && !flag; k++) {

							if (Selec_Mover(l, k, true)) {
								pIA_x = l;
								pIA_y = k;
								flag = true;
								
							}
						}

					}

				}
			}
		}
		ETSIDI::play("sonidos/MoverFicha.wav");

		if (matriz[pIA_x][pIA_y] > 0) {
			for (int z = 0; z < static_cast<int>(fichas.size()); z++) {
				if (fichas[z]->Get_PosicionX() == pIA_x && fichas[z]->Get_PosicionY() == pIA_y) {
					ETSIDI::play("sonidos/ComerFicha.wav");
					delete fichas[z];
					if (z < pInd) pInd--;
					fichas.erase(fichas.begin() + z);
				}
			}
		}

		Promocion(pInd, pI, pJ, { pIA_x, pIA_y });
		fichas[pInd]->Set_Posicion(pIA_x, pIA_y);

		//Actualización de los valores
		matriz[pIA_x][pIA_y] = matriz[pI][pJ];
		matriz[pI][pJ] = 0;

		Comprobar_Jaque();		// Comprobar si el jugador esta en jaque

		color = true;			// Cambio de turno al jugador

		Comprobar_JaqueMate();	// Comprobar si el jugador esta en jaque mate
		pInd = -1;

}

bool Tablero::Selec_Mover(int i, int j, bool f) {			// i = FILAS, j = COLUMNAS

	bool flag = false;

	switch (abs(matriz[pI][pJ])) {
	case PEON: flag = Selec_Peon(i, j); break;
	case REY: flag = Selec_Rey(i, j); break;
	case DAMA: flag = Selec_Dama(i, j); break;
	case ALFIL: flag = Selec_Alfil(i, j); break;
	case CABALLO: flag = Selec_Caballo(i, j); break;
	case TORRE: flag = Selec_Torre(i, j); break;
	default: flag = false; break;
	}
	
	if (f) {
		int aux = matriz[i][j];
		matriz[i][j] = matriz[pI][pJ];
		matriz[pI][pJ] = 0;

		if (Jaque(color)) {			// Comprueba si el rey de su mismo color esta en jaque
			flag = false;
		}

		matriz[pI][pJ] = matriz[i][j];
		matriz[i][j] = aux;
	}
	
	return flag;

}

bool Tablero::Jaque(bool col) {		// Comprueba si el rey del color que le mandes está en jaque

	int iR = 0, jR = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 5; j++) {

			if ((col && matriz[i][j] == REY) || (!col && matriz[i][j] == -REY)) {
				iR = i; jR = j;
			}

		}
	}

	bool flag = color;
	color = !col;
	int npI = pI; int npJ = pJ;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 5; j++) {


			if ((col && matriz[i][j] < 0) || (!col && matriz[i][j] > 0)) {

				pI = i;
				pJ = j;

				if (Selec_Mover(iR, jR, false)) {
					pI = npI; pJ = npJ;
					color = flag;
					return true;
				}
			}


		}
	}
	pI = npI; pJ = npJ;
	color = flag;

	return false;

}

void Tablero::Comprobar_Jaque() {

	if (Jaque(!color)) {
		if (color)
			jaqN = true;
		else
			jaqB = true;
	}
	else {
		if (color)
			jaqN = false;
		else
			jaqB = false;
	}

}

void Tablero::Comprobar_JaqueMate() {
    bool jaque_mate = true;
    bool flag = false;

    for (int i = 0; i < 6 && !flag; i++) {
        for (int j = 0; j < 5 && !flag; j++) {

            // Verifica todas las piezas del jugador en turno
            if ((color && matriz[i][j] > 0) || (!color && matriz[i][j] < 0)) {

                pI = i;
                pJ = j;

                for (int l = 0; l < 6 && !flag; l++) {
                    for (int k = 0; k < 5 && !flag; k++) {
                        // Guarda las posiciones de destino posibles
                        int destI = l, destJ = k;

                        // Intenta mover la pieza a la posición (l, k)
                        if (Selec_Mover(l, k, true)) {  // Asume que Selec_Mover verifica el movimiento legal
                            jaque_mate = false;  // Si puede mover sin quedar en jaque, no es jaque mate
                            flag = true;
                        }

                        // Restaura la posición original de la pieza (opcional, depende de cómo funcione Selec_Mover)
                        // Podrías necesitar una función que revierta los movimientos
                    }
                }
            }
        }
    }

    // Actualiza el estado de jaque mate
    if (jaque_mate) {
        if (color) {
            jaqMB = true;
        } else {
            jaqMN = true;
        }
    } else {
		jaqMB = false, jaqMN = false;
    }

	if ((jaqMN && !jaqN) || (jaqMB && !jaqB))
		tablas = true;
}

bool Tablero::Selec_Peon(int i, int j) {
	bool sol = false;

	if (color) { //blancas
		if (matriz[i][j] == 0 && j == pJ && i == (pI + 1)) { sol = true; } //movimiento sin comer
		if (matriz[i][j] < 0 && (j == (pJ + 1) || j == (pJ - 1)) && i == (pI + 1)) {sol = true;} //movimiento comiendo
	}
	else{ //negras
		if (matriz[i][j] == 0 && j == pJ && i == (pI - 1)) { sol = true; } //movimiento sin comer
		if (matriz[i][j] > 0 && (j == (pJ + 1) || j == (pJ - 1)) && i == (pI - 1)) { sol = true; }; //movimiento comiendo
	}
	return sol;
}

bool Tablero::Selec_Rey(int i, int j) {
	bool sol = false;
	if (matriz[i][j] == 0 && (abs(pI - i) < 2) && (abs(pJ - j) < 2) ) { sol = true; }                       
	if (color && matriz[i][j] < 0 && (abs(pI - i) < 2) && (abs(pJ - j) < 2)) { sol = true; } //Blanco
	if (!color && matriz[i][j] > 0 && (abs(pI - i) < 2) && (abs(pJ - j) < 2)) { sol = true; } //Negro
	return sol;
}

bool Tablero::Selec_Caballo(int i, int j) {
	bool sol = false;
	if (color) {
		if (matriz[i][j] <= 0 && ((abs(pI - i) == 2 && abs(pJ - j) == 1) || (abs(pI - i) == 1) && abs(pJ - j) == 2)) sol = true;
	}
	else {
		if (matriz[i][j] >= 0 && ((abs(pI - i) == 2 && abs(pJ - j) == 1) || (abs(pI - i) == 1) && abs(pJ - j) == 2)) sol = true;
	}
	return sol;
}

bool Tablero::Selec_Torre(int i, int j) { 
	if (pJ == j) {
		
		for (int I = std::min(pI, i) + 1; I < std::max(pI, i); I++) {
			if (matriz[I][pJ] != 0) return false;
		}
		
		if (matriz[i][j] == 0) return true;
		if (color && matriz[i][j] < 0) return true;
		if (!color && matriz[i][j] > 0)return true;
	}
	if (pI == i) {
		
		for (int J = std::min(pJ, j) + 1; J < std::max(pJ, j); J++) {
			if (matriz[pI][J] != 0) return false;
		}
		
		if (matriz[i][j] == 0) return true;
		if (color && matriz[i][j] < 0) return true;
		if (!color && matriz[i][j] > 0) return true;
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
			if (I < 0 || J < 0)return false;
			else if (matriz[I][J] != 0)return false;
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

bool Tablero::Consultar_Turno(){
	return color;
}


void Tablero::Promocion(int pInd, int pI, int pJ, Vector2xy destino) {

	if (destino.x == 5 && fichas[pInd]->Get_Valor() == 6) {
	

		fichas[pInd]->Cambiar_Valor(DAMA);
		matriz[pI][pJ] = DAMA;
	}

	if (destino.x == 0 && fichas[pInd]->Get_Valor() == -6) {


		fichas[pInd]->Cambiar_Valor(-DAMA);
		matriz[pI][pJ] = -DAMA;
	}
}


void Tablero:: Borrar() {
	for (int z = 0; z < static_cast<int>(fichas.size()); z++) {
		
		delete fichas[z];
		fichas.erase(fichas.begin() + z);

		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				matriz[i][j] = 0;
			}
		}
		
	}
}
