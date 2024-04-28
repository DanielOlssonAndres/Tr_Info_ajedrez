#include "torre.h"
#include "freeglut.h"



void Torre::inicializa_5x6EO(const Vector2xy& posicion, const float tipo)
{
    this->posicion = posicion;
    this->tipo = tipo;
}

void Torre::inicializa_PETTY(const Vector2xy& posicion, const float tipo)
{
    this->posicion = posicion;
    this->tipo = tipo;
}

void Torre::dibuja_blanco()
{
    glPushMatrix();
    glTranslatef(posicion.x - 3, posicion.y - 3, 1);

    sprite_blanco.setSize(5, 5);

    sprite_blanco.draw();
    glPopMatrix();
}

void Torre::dibuja_negro()
{
    glPushMatrix();
    glTranslatef(posicion.x - 3, posicion.y - 3, 1);

    sprite_negro.setSize(5, 5);

    sprite_negro.draw();
    glPopMatrix();
}
