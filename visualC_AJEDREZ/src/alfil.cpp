#include "alfil.h"
#include "freeglut.h"

void Alfil::dibuja()
{
    glPushMatrix();
    glColor3f(tipo, tipo, tipo);
    glTranslatef(posicion.x, posicion.y, 0.0f); 
    glutWireSphere(2, 30, 30); 
    glPopMatrix();
}