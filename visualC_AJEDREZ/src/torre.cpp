#include "torre.h"
#include "freeglut.h"

void Torre::dibuja()
{
    glPushMatrix();
    glColor3f(tipo, tipo, tipo);
    glTranslatef(posicion.x, posicion.y, 0.0f); 
    glutSolidCube(2); 
    glPopMatrix();
}