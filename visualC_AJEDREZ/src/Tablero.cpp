
#include "freeglut.h"

#include "Tablero.h"
#include "mundo.h"
using std::cout;
using std::endl;

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
			int C_R;
			if (pI == i && pJ == j)C_R = 100;
			else C_R = Mcasillas[i][j].colR;
			glColor3ub(C_R, Mcasillas[i][j].colG, Mcasillas[i][j].colB);
			glVertex3f(Mcasillas[i][j].vx, Mcasillas[i][j].vy, 0.0f);
			glVertex3f(Mcasillas[i][j].vx, Mcasillas[i][j].vy + 6, 0.0f);
			glVertex3f(Mcasillas[i][j].vx + 6, Mcasillas[i][j].vy + 6, 0.0f);
			glVertex3f(Mcasillas[i][j].vx + 6, Mcasillas[i][j].vy, 0.0f);
			glEnd();
		}
	}

	//INDICADOR DE TURNO 
	glPushMatrix();
	if (!color) {
		colorR = 0;
		colorG = 105;
		colorB = 148;
	}
	else{
		colorR = 139;
		colorG = 69;
		colorB = 19;
	}

	glTranslatef(-7, 21.5, 1);
	glColor3ub(colorR, colorG, colorB);
	glutSolidSphere(3, 30, 30);
	glPopMatrix();

	//INDICADOR DE JAQUE
	/*
	glPushMatrix();

	if ( jaqN || jaqB || jaqMN || jaqMB ) {
		colorJR = 0;
		colorJG = 0;
		colorJB = 0;
	}
	else {
		colorJR = 255;
		colorJG = 255;
		colorJB = 255;
	}
	glTranslatef(-7, 12, 1);
	glColor3ub(colorJR, colorJG, colorJB);
	glutSolidSphere(2, 30, 30);
	glPopMatrix();
	*/

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
			{-ALFIL, -PEON, -PEON, -PEON, -PEON },		// NEGRAS
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

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			Fichas_IA[i][j] = 1;
		}
	}

}


void Tablero::Tomar_Pieza_1VS1(Vector2xy origen) //posicion del raton -> origen
{
	pInd = -1;
	pIA = -1;
	pI = -1;
	pJ = -1;

	if (origen.x != -1 && origen.y != -1 && matriz[origen.x][origen.y] != 0) { //Si hemos seleccionado una casilla con ficha
		for (int z = 0; z < static_cast<int>(fichas.size()); z++) { //Buscamos la ficha que estamos seleccionando y guardamos su índice del vector en pInd
			if (fichas[z]->Get_PosicionX() == origen.x && fichas[z]->Get_PosicionY() == origen.y) {
				pInd = z;
				break;
			}
		}
		if (pInd != -1) {
			if ((color && fichas[pInd]->Get_Valor() < 0) || (!color && fichas[pInd]->Get_Valor() > 0)) { //Si la pieza no corresponde con el color del turno
				pInd = -1;
				std::cout << "No puedes mover esa ficha en tu turno." << std::endl;
				ETSIDI::play("sonidos/SonidoError.wav");
			}

			if (pInd != -1) {
				pI = origen.x;
				pJ = origen.y;
				std::cout << "Se ha seleccionado la ficha " << matriz[pI][pJ] << std::endl;
			}
		}
	}
}

void Tablero::Soltar_Pieza_1VS1(Vector2xy destino) //posición del ratón -> destino
{
	int a;
	cout << "Soltar_Pieza_1VS1" << endl;

	if (pInd != -1) { // Si es una casilla permitida

		//Si el movimiento que quieres hacer está permitido 
		if (((color && matriz[destino.x][destino.y] <= 0) || (!color && matriz[destino.x][destino.y] >= 0)) && Selec_Mover(destino.x, destino.y, color)) { //CAMBIAR  Selec_Mover por TRUE PARA DESHABILITAR LAS LIMITACIONES DE MOVIMIENTO

			ETSIDI::play("sonidos/MoverFicha.wav");

			//Código que haga que si hay una ficha del otro color en el destino, que se elimine (comer)
			if ((color && matriz[destino.x][destino.y] < 0) || (!color && matriz[destino.x][destino.y] > 0)) {

				for (int z = 0; z < static_cast<int>(fichas.size()); z++) {
					if (fichas[z]->Get_PosicionX() == destino.x && fichas[z]->Get_PosicionY() == destino.y) {
						std::cout << "se elimina la ficha " << matriz[destino.x][destino.y] << std::endl;
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

			if (jaqN)cout << "El rey negro esta en jaque" << endl;
			if (jaqB)cout << "El rey blanco esta en jaque" << endl;
			if (jaqMN)cout << "El rey negro esta en jaque MATE" << endl;
			if (jaqMB)cout << "El rey blanco esta en jaque MATE" << endl;
		

			// Selec_Jaque(); // LA COMPROBACIÓN DE LOS JAQUES AÚN NO FUNCIONA BIEN
			// Consultar_Jaque();

			//Cambio de turno
			if (color) color = false;		// Ahora es turno de las NEGRAS
			else color = true;				// Ahora es turno de las BLANCAS 

			if (Toponente == 1)
				pIA = 1;

		}
		else
			ETSIDI::play("sonidos/SonidoError.wav");

	}

	pInd = -1;

}

void Tablero::Tomar_Pieza_VSMAQ() {
	cout << "Tomar_Pieza_1VS1" << endl;
	pInd = -1;
	pI = -1;
	pJ = -1;
	int l, k;


	if (color == false && pIA == 1) { //Bucle que recorra todas las casillas
		cout << "Se esta pensando la jugada" << endl;
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (matriz[i][j] < 0 && Fichas_IA[i][j] == 1)
				{
					for (int z = 0; z < static_cast<int>(fichas.size()); z++) { //Buscamos la ficha que estamos seleccionando y guardamos su índice del vector en pInd
						if (fichas[z]->Get_PosicionX() == i && fichas[z]->Get_PosicionY() == j) {
							l = i;
							k = j;

							for (i - 5; i < i + 5; i++) {
								for (j - 5; j < j + 5; j++){
									if ((matriz[i][j] >= 0) && Selec_Mover(i, j, color) == false) {
										pInd = -1;
										Fichas_IA[l][k] = -1;
										cout << "-------" << endl;
									}
									if ((matriz[i][j] >= 0) && Selec_Mover(i, j, color) == true) {
										pInd = z;
										pIA_x = i;
										pIA_y = j;
										pI = l;
										pJ = k;
										std::cout << "Se ha seleccionado la ficha " << matriz[pI][pJ] << std::endl;
									}
								
								}
									
							}

							break;
						}
					}
				}
			}
		}
		Tomar_Pieza_VSMAQ();
	}
				
	
}



void Tablero::Soltar_Pieza_VSMAQ() {
	
	cout << "Soltar_Pieza_VSMAQ" << endl;

	if (pInd != -1 && pIA == 1) { // Si es una casilla permitida

		if (color == false) {

			// Relleno el vector de Fichas_IA
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					Fichas_IA[i][j] = 1;
				}
			}

			ETSIDI::play("sonidos/MoverFicha.wav");

			if (matriz[pIA_x][pIA_y] > 0){

				for (int z = 0; z < static_cast<int>(fichas.size()); z++) {
					if (fichas[z]->Get_PosicionX() == pI && fichas[z]->Get_PosicionY() == pJ) {
						std::cout << "se elimina la ficha " << matriz[pIA_x][pIA_y] << std::endl;
						ETSIDI::play("sonidos/ComerFicha.wav");

						delete fichas[z];
						if (z < pInd) pInd--;
						fichas.erase(fichas.begin() + z);
					}
				}
			}

			Vector2xy destino{
				pIA_x,pIA_y
			};

			fichas[pInd]->Set_Posicion(pIA_x, pIA_y);

			Promocion(pInd, pI, pJ, destino);//Verificar si un peón ha llegado a la última casilla

			//Actualización de los valores
			matriz[pIA_x][pIA_y] = matriz[pI][pJ];
			matriz[pI][pJ] = 0;

			if (jaqN)cout << "El rey negro esta en jaque" << endl;
			if (jaqB)cout << "El rey blanco esta en jaque" << endl;
			if (jaqMN)cout << "El rey negro esta en jaque MATE" << endl;
			if (jaqMB)cout << "El rey blanco esta en jaque MATE" << endl;

			//Cambio de turno
			if (color) color = false;		// Ahora es turno de las NEGRAS
			else color = true;				// Ahora es turno de las BLANCAS 

		}
		else {
			ETSIDI::play("sonidos/SonidoError.wav");
			cout << "El rey blanco esta en jaque MATE" << endl;
		}
		pIA = -1;
	}

	pInd = -1;
}


bool Tablero::Selec_Mover(int i, int j, bool f) {			// i = FILAS, j = COLUMNAS

	bool flag = false;

	switch (abs(matriz[pI][pJ])) {
	case PEON: flag = Selec_Peon(i, j);
		break;
	case REY: flag = Selec_Rey(i, j); break;
	case DAMA: flag = Selec_Dama(i, j);
		break;
	case ALFIL: flag = Selec_Alfil(i, j); break;
	case CABALLO: flag = Selec_Caballo(i, j); break;
	case TORRE: flag = Selec_Torre(i, j); break;
	default: flag = false; break;
	}

	if (flag) {
		//matriz[i][j] = matriz[pI][pJ];
		//matriz[pI][pJ] = 0;

		if (Jaque(color)) {
			flag = false;
			cout << "No puedo moverlo, estaria en jaque" << endl;
		}

		//matriz[pI][pJ] = matriz[i][j];
		//matriz[i][j] = 0;
	}

	return flag;

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
	//NO SE TIENE EN CUENTA EL POSIBLE JAQUE EN EL MOVIMIENTO, HABRÍA QUE AÑADIRLO
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

/*

despues de jaq = true;

if (color) {
	if (jaqN) jaqMN = true;
	jaqN = true;
}
else {
	if (jaqB) jaqMB = true;
	jaqB = true;
}

*/

void Tablero::Selec_Jaque() {
	int iR = -1, jR = -1;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 5; j++) {

			if ((color && matriz[i][j] == -REY) || (!color && matriz[i][j] == REY)) {
				iR = i; jR = j;
			}

		}
	}

	bool jaq = false;
	if (Mirar_Jaque(iR, jR)) {
		jaq = true;

		if (color) {
			jaqN = true;
			jaqMN = true;
		}
		else {
			jaqB = true;
			jaqMB = true;
		}

		for (int k = -1; k <= 1; k++) {
			for (int l = -1; l <= 1; l++) {
				if (k == 0 && l == 0)continue;

				if ((iR + l >= 0 && iR + l <= 5 && jR + k >= 0 && jR <= 4) && (color && matriz[iR + l][jR + k] >= 0 || !color && matriz[iR + l][jR + k] <= 0)) {
					if (!Mirar_Jaque(iR + l, jR + k)) {
						if (color) jaqMN = false;
						else jaqMB = false;
					}
				}

			}
		}

	}

	if (color && !jaq) {
		jaqB = false;
		jaqMB = false;
	}
	else if (!jaq) {
		jaqN = false;
		jaqMN = false;
	}
}

bool Tablero::Jaque(bool col) {

	int iR = -1, jR = -1;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 5; j++) {

			if ((col && matriz[i][j] == REY) || (!col && matriz[i][j] == -REY)) {
				iR = i; jR = j;
			}

		}
	}

	int npI = pI; int npJ = pJ;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 5; j++) {

			if ((col && matriz[i][j] >= 0) || (!col && matriz[i][j] <= 0)) {
				pI = i; 
				pJ = j;
			}

			if (Selec_Mover(iR, jR, false)) {
				pI = npI; pJ = npJ;
				return true;
			}

		}
	}
	pI = npI; pJ = npJ;
	return false;

}

bool Tablero::Mirar_Jaque(int iR, int jR) {

	int npI = pI; int npJ = pJ;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 5; j++) {

			if ((color && matriz[i][j] <= 0) || (!color && matriz[i][j] >= 0)) continue;
			pI = i; pJ = j;

			if (Selec_Mover(iR, jR, false)) {
				pI = npI; pJ = npJ;
				return true;
			}

		}
	}
	pI = npI; pJ = npJ;
	return false;
}


void Tablero::Consultar_Jaque() {
	if (jaqB)
		if (jaqMB)
			cout << "Las blancas estan en jaque mate" << endl;
		else
			cout << "Las blancas estan en jaque" << endl;

	if (jaqN)
		if (jaqMN)
			cout << "Las negras estan en jaque mate" << endl;
		else
			cout << "Las negras estan en jaque" << endl;
}

bool Tablero::Consultar_Turno(){
	return color;
}


void Tablero::Promocion(int pInd, int pI, int pJ, Vector2xy destino) {

	if (destino.x == 5 && fichas[pInd]->Get_Valor() == 6) {
		std::cout << "Se llama a promocion correctamente " << std::endl;

		fichas[pInd]->Cambiar_Valor(DAMA);
		matriz[pI][pJ] = DAMA;
	}

	if (destino.x == 0 && fichas[pInd]->Get_Valor() == -6) {
		std::cout << "Se llama a promocion correctamente " << std::endl;

		fichas[pInd]->Cambiar_Valor(-DAMA);
		matriz[pI][pJ] = -DAMA;
	}
}



