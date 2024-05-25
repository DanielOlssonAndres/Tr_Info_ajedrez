#include "coordinador.h"


void coordinador::dibuja() {
	switch (estado)
	{
	case coordinador::inicio: //imagen inicio completa
		int x_ojo = 15, y_ojo = 18, z_ojo = 60, x_look = 15, y_look = 18, z_look = 0;
		gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			x_look, y_look, z_look,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,
			ETSIDI::getTexture("bin/imagenes/1_INICIO.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex2d(-15, -4); //inferior izquierda
		glTexCoord2d(1, 1); glVertex2d(45, -4); //Inferior derecha
		glTexCoord2d(1, 0); glVertex2d(45, 40); //Superior derecha
		glTexCoord2d(0, 0); glVertex2d(-15, 40); //Superior izquierda
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;
	case coordinador::start:
		int x_ojo = 15, y_ojo = 18, z_ojo = 60, x_look = 15, y_look = 18, z_look = 0;
		gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			x_look, y_look, z_look,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,
			ETSIDI::getTexture("bin/imagenes/2_START.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex2d(-15, -4); //inferior izquierda
		glTexCoord2d(1, 1); glVertex2d(45, -4); //Inferior derecha
		glTexCoord2d(1, 0); glVertex2d(45, 40); //Superior derecha
		glTexCoord2d(0, 0); glVertex2d(-15, 40); //Superior izquierda
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;
	case coordinador::vs1_menu:
		int x_ojo = 15, y_ojo = 18, z_ojo = 60, x_look = 15, y_look = 18, z_look = 0;
		gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			x_look, y_look, z_look,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,
			ETSIDI::getTexture("bin/imagenes/3_1VS1_MENU.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex2d(-15, -4); //inferior izquierda
		glTexCoord2d(1, 1); glVertex2d(45, -4); //Inferior derecha
		glTexCoord2d(1, 0); glVertex2d(45, 40); //Superior derecha
		glTexCoord2d(0, 0); glVertex2d(-15, 40); //Superior izquierda
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;
	case coordinador::vs1_5x6_menu:
		int x_ojo = 15, y_ojo = 18, z_ojo = 60, x_look = 15, y_look = 18, z_look = 0;
		gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			x_look, y_look, z_look,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,
			ETSIDI::getTexture("bin/imagenes/4_1VS1_5X6_MENU.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex2d(-15, -4); //inferior izquierda
		glTexCoord2d(1, 1); glVertex2d(45, -4); //Inferior derecha
		glTexCoord2d(1, 0); glVertex2d(45, 40); //Superior derecha
		glTexCoord2d(0, 0); glVertex2d(-15, 40); //Superior izquierda
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;
	case coordinador::vs1_5x6_instr:
		int x_ojo = 15, y_ojo = 18, z_ojo = 60, x_look = 15, y_look = 18, z_look = 0;
		gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			x_look, y_look, z_look,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,
			ETSIDI::getTexture("bin/imagenes/5_1VS1_5X6_INSTRUCTIONS.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex2d(-15, -4); //inferior izquierda
		glTexCoord2d(1, 1); glVertex2d(45, -4); //Inferior derecha
		glTexCoord2d(1, 0); glVertex2d(45, 40); //Superior derecha
		glTexCoord2d(0, 0); glVertex2d(-15, 40); //Superior izquierda
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;
	case coordinador::vs1_petty_menu:
		int x_ojo = 15, y_ojo = 18, z_ojo = 60, x_look = 15, y_look = 18, z_look = 0;
		gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			x_look, y_look, z_look,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,
			ETSIDI::getTexture("bin/imagenes/6_1VS1__PETTY_MENU.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex2d(-15, -4); //inferior izquierda
		glTexCoord2d(1, 1); glVertex2d(45, -4); //Inferior derecha
		glTexCoord2d(1, 0); glVertex2d(45, 40); //Superior derecha
		glTexCoord2d(0, 0); glVertex2d(-15, 40); //Superior izquierda
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;
	case coordinador::vs1_petty_instr:
		int x_ojo = 15, y_ojo = 18, z_ojo = 60, x_look = 15, y_look = 18, z_look = 0;
		gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			x_look, y_look, z_look,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,
			ETSIDI::getTexture("bin/imagenes/14_VS1_PETTY_INSTRUCTIONS.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex2d(-15, -4); //inferior izquierda
		glTexCoord2d(1, 1); glVertex2d(45, -4); //Inferior derecha
		glTexCoord2d(1, 0); glVertex2d(45, 40); //Superior derecha
		glTexCoord2d(0, 0); glVertex2d(-15, 40); //Superior izquierda
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;
	case coordinador::juego:
		mundo.dibuja();
		break;
	default:
		break;
	}
}

void coordinador::tecla(unsigned char key) {
	switch (estado)
	{
	case coordinador::inicio: 
		if (key == 's')exit(0);
		estado = start;
		break;
	case coordinador::start:
		if (key == '1') {exit(0); estado = vs1_menu;}
		break;
		/*if (key == '2') { exit(0); estado = vsm_menu; }
		break;*/

	case coordinador::vs1_menu:
		if (key == 'a') { exit(0); estado = vs1_5x6_menu; }
		else if (key == 'b') { exit(0); estado = vs1_petty_menu; }
		break;

	case coordinador::vs1_5x6_menu:
		if (key == 'i') { exit(0); estado = vs1_5x6_instr; }
		else if (key == 'p') { exit(0);	mundo.inicializa(); estado = juego; }
		break;
	case coordinador::vs1_5x6_instr:
		if (key == 'y')exit(0);
		mundo.inicializa();
		estado = juego;
		break;
	case coordinador::vs1_petty_menu:
		if (key == 'i') { exit(0); estado = vs1_petty_instr; }
		else if (key == 'p') { exit(0); estado = juego; }
		break;
	case coordinador::vs1_petty_instr:
		if (key == 'y')exit(0);
		mundo.inicializa();
		estado = juego;
		break;
	case coordinador::juego://de momento no hay teclas durante el juego.
		
		break;
	default:
		break;
	}
}
