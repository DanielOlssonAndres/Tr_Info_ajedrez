#include "caballo.h"
#include "freeglut.h"


void Caballo::inicializa_5x6EO(const Vector2xy& posicion, const float tipo)
{
    this->posicion = posicion;
    this->tipo = tipo;
}

void Caballo::inicializa_PETTY(const Vector2xy& posicion, const float tipo)
{
    this->posicion = posicion;
    this->tipo = tipo;
}

void Caballo::dibuja()
{
    glPushMatrix();
    glColor3f(tipo, tipo, tipo);
    glTranslatef(posicion.x, posicion.y, 0.0f); 
    glutWireCube(2); 
    glPopMatrix();
}