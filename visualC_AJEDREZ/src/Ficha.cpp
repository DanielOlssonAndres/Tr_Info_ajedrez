/*#include "Ficha.h"

void Ficha::inicializa(const Vector2xy& posicion, const Tipo& tipo)
{
    this->posicion = posicion;
    this->tipo = tipo;
}*/
#include "Ficha.h"
#include "freeglut.h"

void Ficha::inicializa(const int Tjuego) {

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 5; j++) {
			PosEnCasillas[i][j] = { 3 + j * 6, 3 + i * 6 };
		}
	}

	//INICIALIZACIÓN DE FICHAS ESPECIALES
	if (Tjuego == 0) { //Modalidad 5x6EO();
		//Blancas
		reyB.inicializa_5x6EO(PosEnCasillas[0][4], (const float)1.0);
		damaB.inicializa_5x6EO(PosEnCasillas[0][3], (const float)1.0);
		alfilB.inicializa_5x6EO(PosEnCasillas[0][2], (const float)1.0);
		caballoB.inicializa_5x6EO(PosEnCasillas[0][1], (const float)1.0);
		torreB.inicializa_5x6EO(PosEnCasillas[0][0], (const float)1.0);
		//Negras
		reyN.inicializa_5x6EO(PosEnCasillas[5][0], (const float)0.3);
		damaN.inicializa_5x6EO(PosEnCasillas[5][1], (const float)0.3);
		alfilN.inicializa_5x6EO(PosEnCasillas[5][2], (const float)0.3);
		caballoN.inicializa_5x6EO(PosEnCasillas[5][3], (const float)0.3);
		torreN.inicializa_5x6EO(PosEnCasillas[5][4], (const float)0.3);
	}
	else { //Modalidad PETTY
		//Blancas
		reyB.inicializa_PETTY(PosEnCasillas[0][1], (const float)1.0);
		damaB.inicializa_PETTY(PosEnCasillas[0][0], (const float)1.0);
		alfilB.inicializa_PETTY(PosEnCasillas[0][2], (const float)1.0);
		caballoB.inicializa_PETTY(PosEnCasillas[0][3], (const float)1.0);
		torreB.inicializa_PETTY(PosEnCasillas[0][4], (const float)1.0);
		//Negras
		reyN.inicializa_PETTY(PosEnCasillas[5][1], (const float)0.3);
		damaN.inicializa_PETTY(PosEnCasillas[5][0],(const float) 0.3);
		alfilN.inicializa_PETTY(PosEnCasillas[5][2], (const float)0.3);
		caballoN.inicializa_PETTY(PosEnCasillas[5][3], (const float)0.3);
		torreN.inicializa_PETTY(PosEnCasillas[5][4], (const float)0.3);
	}
	//INICIALIZACIÓN DE PEONES
	//Blancos
	peonB1.inicializa(PosEnCasillas[1][0], (const float)1.0);
	peonB2.inicializa(PosEnCasillas[1][1], (const float)1.0);
	peonB3.inicializa(PosEnCasillas[1][2], (const float)1.0);
	peonB4.inicializa(PosEnCasillas[1][3], (const float)1.0);
	peonB5.inicializa(PosEnCasillas[1][4], (const float)1.0);
	//Negros
	peonN1.inicializa(PosEnCasillas[4][0], (const float)0.3);
	peonN2.inicializa(PosEnCasillas[4][1], (const float)0.3);
	peonN3.inicializa(PosEnCasillas[4][2], (const float)0.3);
	peonN4.inicializa(PosEnCasillas[4][3], (const float)0.3);
	peonN5.inicializa(PosEnCasillas[4][4], (const float)0.3);

}

void Ficha::dibuja() {
	//Blancas
	reyB.dibuja_blanco();
	damaB.dibuja_blanco();
	alfilB.dibuja_blanco();
	caballoB.dibuja_blanco();
	torreB.dibuja_blanco();
	peonB1.dibuja_blanco();
	peonB2.dibuja_blanco();
	peonB3.dibuja_blanco();
	peonB4.dibuja_blanco();
	peonB5.dibuja_blanco();

	//Negras
	reyN.dibuja_negro();
	damaN.dibuja_negro();
	alfilN.dibuja_negro();
	caballoN.dibuja_negro();
	torreN.dibuja_negro();
	peonN1.dibuja_negro();
	peonN2.dibuja_negro();
	peonN3.dibuja_negro();
	peonN4.dibuja_negro();
	peonN5.dibuja_negro();

}


