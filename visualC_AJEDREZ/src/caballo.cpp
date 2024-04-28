#include "caballo.h"
#include "freeglut.h"

void Caballo::dibuja_blanco()
{
    glPushMatrix();
    glTranslatef(posicion.x - 3, posicion.y - 3, 1);

    sprite_blanco.setSize(5, 5);

    sprite_blanco.draw();
    glPopMatrix();
}

void Caballo::dibuja_negro()
{
    glPushMatrix();
    glTranslatef(posicion.x - 3, posicion.y - 3, 1);

    sprite_negro.setSize(5, 5);

    sprite_negro.draw();
    glPopMatrix();
}
