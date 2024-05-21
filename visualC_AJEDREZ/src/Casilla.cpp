#include "Casilla.h"
#include "freeglut.h"

void Casilla::dibuja() 
{
	glBegin(GL_POLYGON);
	glColor3ub(colR, colG, colB);
	glVertex3f(vx, vy, 0.0f);
	glVertex3f(vx, vy + 6, 0.0f);
	glVertex3f(vx + 6, vy + 6, 0.0f);
	glVertex3f(vx + 6, vy, 0.0f);
	glEnd();

	// La casilla es un 6*6
}
