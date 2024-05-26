#include "coordinador.h"

void coordinador::MouseButton(int x, int y, int boton, bool abajo, bool TeclaSp, bool TeclaCtr) {
	if(estado==0)mundo.MouseButton(x, y, boton, abajo, TeclaSp, TeclaCtr);
}

void coordinador::dibuja() {
	gluLookAt(15, 18, 60,  // posicion del ojo
		15, 18, 0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  
	switch (estado)
	{
	case INICIO: //imagen inicio completa
	
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,
			ETSIDI::getTexture("imagenes/1_INICIO.png").id);
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
	case ELECCION_ADVERSARIO:

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,
			ETSIDI::getTexture("imagenes/2_START.png").id);
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
	
	case MENU_1VS1:

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,
			ETSIDI::getTexture("imagenes/3_1VS1_MENU.png").id);
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
	case MENU_5X6:

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,
			ETSIDI::getTexture("imagenes/4_1VS1_5X6_MENU.png").id);
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
	case INSTRUCCIONES_5X6:
		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,
			ETSIDI::getTexture("imagenes/5_1VS1_5X6_INSTRUCTIONS.png").id);
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
	case MENU_PETTY:

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,
			ETSIDI::getTexture("imagenes / 6_1VS1__PETTY_MENU.png").id);
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
	case INSTRUCCIONES_PETTY:

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,
			ETSIDI::getTexture("imagenes/14_VS1_PETTY_INSTRUCTIONS.png").id);
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
	case JUEGO:
		// mundo.inicializa();
		mundo.dibuja();
		break;
		
	default:
		break;
	}
}

void coordinador::tecla(unsigned char key) {
	switch (estado)
	{
	case INICIO:
		if (key == 's' || key == 'S') {
			estado = ELECCION_ADVERSARIO;
			ETSIDI::play("sonidos/InicioJuego.wav");
		}
		break;
	case ELECCION_ADVERSARIO:
		if (key == '1') {
			estado = JUEGO;
			mundo.inicializa();
			ETSIDI::play("sonidos/InicioJuego.wav");
		}
		// if (key == '2') { exit(0); estado = MENU_MAQUINA; }
		break;
		
	case MENU_1VS1:
		if (key == 'a') {
			estado = MENU_5X6;
			ETSIDI::play("sonidos/InicioJuego.wav");
		}
		if (key == 'b') {
			estado = MENU_PETTY;
			ETSIDI::play("sonidos/InicioJuego.wav");
		}
		break;

	case MENU_5X6:
		if (key == 'i') estado = INSTRUCCIONES_5X6; 
		if (key == 'p') { 
			mundo.inicializa(); 
			estado = JUEGO; 
		}
		break;
	case INSTRUCCIONES_5X6:
		if (key == 'y') { 
			mundo.inicializa();
			estado = JUEGO; 
		}
		break;
	case MENU_PETTY:
		if (key == 'i') { estado = INSTRUCCIONES_PETTY; }
		if (key == 'p') { estado = JUEGO; }
		break;
	case INSTRUCCIONES_PETTY:
		if (key == 'y') {//exit(0);
			//mundo.inicializa();
			estado = JUEGO;
		}
		break;
	case JUEGO://de momento no hay teclas durante el juego.

		break;
		
	default:
		break;
	}
}
