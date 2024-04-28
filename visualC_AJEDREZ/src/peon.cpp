#include "peon.h"
#include "freeglut.h"

void Peon::dibuja_blanco()
{
    glPushMatrix();
    glTranslatef(posicion.x - 3, posicion.y - 3, 1);

    sprite_blanco.setSize(5, 5);

    sprite_blanco.draw();
    glPopMatrix();
}

void Peon::dibuja_negro()
{
    glPushMatrix();
    glTranslatef(posicion.x-3, posicion.y-3 , 1);

    sprite_negro.setSize(5, 5);

    sprite_negro.draw();
    glPopMatrix();
}
