#include "peon.h"
#include "freeglut.h"

void Peon::dibuja()
{
    glPushMatrix();
    glColor3f(tipo, tipo, tipo);
    glTranslatef(posicion.x, posicion.y, 0.0f); 
    glutSolidSphere(2, 30, 30);
    glPopMatrix();
}