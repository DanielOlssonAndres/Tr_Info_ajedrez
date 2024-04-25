#include "alfil.h"
#include "freeglut.h"


void Alfil::inicializa_5x6EO(const Vector2xy& posicion, const float tipo)
{
    this->posicion = posicion;
    this->tipo = tipo;
}

void Alfil::inicializa_PETTY(const Vector2xy& posicion, const float tipo)
{
    this->posicion = posicion;
    this->tipo = tipo;
}

void Alfil::dibuja()
{
    glPushMatrix();
    glColor3f(tipo, tipo, tipo);
    glTranslatef(posicion.x, posicion.y, 0.0f); 
    glutWireSphere(2, 30, 30); 
    glPopMatrix();
}