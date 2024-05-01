#include "Ficha.h"

void Ficha::inicializa(const Posicion& posicion, const Tipo& tipo)
{
    this->pos = posicion;
    this->tipo = tipo;

    //Inicializaci�n de las posiciones GR�FICAS
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            PosEnCasillas[i][j] = { 3 + i * 6, 3 + j * 6 };
        }
    }

}



