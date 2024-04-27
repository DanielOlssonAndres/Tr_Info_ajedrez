#include "caballo.h"
#include "freeglut.h"


void Caballo::dibuja()
{
    glPushMatrix();
    glColor3f(tipo, tipo, tipo);
    glTranslatef(posicion.x, posicion.y, 0.0f); 
    glutWireCube(2); 
    glPopMatrix();
}