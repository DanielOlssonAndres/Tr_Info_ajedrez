#include "torre.h"
#include "freeglut.h"

void Torre::dibuja()
{
    if (tipo == BLANCAS) {
        glPushMatrix();
        glTranslatef(posicion.x - 3, posicion.y - 3, 1);

        sprite_blanco.setSize(5, 5);

        sprite_blanco.draw();
        glPopMatrix();
    }
    else {
        glPushMatrix();
        glTranslatef(posicion.x - 3, posicion.y - 3, 1);

        sprite_negro.setSize(5, 5);

        sprite_negro.draw();
        glPopMatrix();
    }
}