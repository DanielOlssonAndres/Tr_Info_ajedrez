#include "rey.h"
#include "freeglut.h"


void Rey::inicializa_5x6EO(const Vector2xy& posicion, const float tipo)
{
	this->posicion = posicion;
    this->tipo = tipo;
}

void Rey::inicializa_PETTY(const Vector2xy& posicion, const float tipo)
{
	this->posicion = posicion;
    this->tipo = tipo;
}

void Rey::dibuja()
{
    glPushMatrix();
    glColor3f(tipo, tipo, tipo); 
    glTranslatef(posicion.x, posicion.y, 0.0f); 
    glutSolidTeapot(1.5); 
    glPopMatrix();
}