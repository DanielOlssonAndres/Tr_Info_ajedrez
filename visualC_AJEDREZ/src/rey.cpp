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

void Rey::dibuja_blanco()
{
    glPushMatrix();
    glTranslatef(posicion.x - 3, posicion.y - 3, 1);

    sprite_blanco.setSize(5, 5);

    sprite_blanco.draw();
    glPopMatrix();
}

void Rey::dibuja_negro()
{
    glPushMatrix();
    glTranslatef(posicion.x - 3, posicion.y - 3, 1);
    
    sprite_negro.setSize(5, 5);

    sprite_negro.draw();
    glPopMatrix();
}
