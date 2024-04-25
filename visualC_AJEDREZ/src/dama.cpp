#include "dama.h"
#include "freeglut.h"


void Dama::inicializa_5x6EO(const Vector2xy& posicion, const float tipo)
{
    this->posicion = posicion;
    this->tipo = tipo;
}

void Dama::inicializa_PETTY(const Vector2xy& posicion, const float tipo)
{
    this->posicion = posicion;
    this->tipo = tipo;
}

void Dama::dibuja()
{
    glPushMatrix();
    glColor3f(tipo, tipo, tipo);
    glTranslatef(posicion.x, posicion.y, 0.0f); 
    glutWireTeapot(1.5); 
    glPopMatrix();
}