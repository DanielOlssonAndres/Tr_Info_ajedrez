#include "rey.h"
#include "freeglut.h"


void Rey::dibuja()
{
    glPushMatrix();
    glColor3f(tipo, tipo, tipo); 
    glTranslatef(posicion.x, posicion.y, 0.0f); 
    glutSolidTeapot(1.5); 
    glPopMatrix();
}