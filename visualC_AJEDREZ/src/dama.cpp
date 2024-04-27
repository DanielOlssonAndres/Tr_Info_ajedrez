#include "dama.h"
#include "freeglut.h"


void Dama::dibuja()
{
    glPushMatrix();
    glColor3f(tipo, tipo, tipo);
    glTranslatef(posicion.x, posicion.y, 0.0f); 
    glutWireTeapot(1.5); 
    glPopMatrix();
}