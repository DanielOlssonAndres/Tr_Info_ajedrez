#include "coordinador.h"

void coordinador::MouseButton(int tipo_oponente, int x, int y, int boton, bool abajo, bool TeclaSp, bool TeclaCtr) {
	tipo_oponente = mundo.get_oponente();
	if(estado==0)mundo.MouseButton(tipo_oponente, x, y, boton, abajo, TeclaSp, TeclaCtr);
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
	case START:

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
	
	case VS1_MENU:

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
	case VS1_5x6_MENU:

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
	case VS1_5x6_INSTR:
		
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
	case VS1_PETTY_MENU:

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,
			ETSIDI::getTexture("imagenes/6_1VS1__PETTY_MENU.png").id);
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
	case VS1_PETTY_INSTR:

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

	case VSM_MENU:

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,
			ETSIDI::getTexture("imagenes/8_MACHINE_MENU.png").id);
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
	case VSM_5x6_MENU:

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,
			ETSIDI::getTexture("imagenes/9_MACHINE_5X6_MENU.png").id);
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
	case VSM_5x6_INSTR:

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,
			ETSIDI::getTexture("imagenes/10_MACHINE_5X6_INSTRUCTIONS.png").id);
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
	case VSM_PETTY_MENU:

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,
			ETSIDI::getTexture("imagenes/11_MACHINE_PETTY_MENU.png").id);
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
	case VSM_PETTY_INSTR:

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,
			ETSIDI::getTexture("imagenes/12_MACHINE_PETTY_INSTRUCTIONS.png").id);
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
	case RATON:

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,
			ETSIDI::getTexture("imagenes/RATON_.png").id); 
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
	case GANA_TIERRA:
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,
			ETSIDI::getTexture("imagenes/GANA_TIERRA.png").id);
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
	case GANA_AGUA:
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,
			ETSIDI::getTexture("imagenes/GANA_AGUA.png").id);
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
	}
}

void coordinador::tecla(unsigned char key) {
	switch (estado)
	{
	case INICIO:
		if (key == 's' || key == 'S') {
			estado = START;
			ETSIDI::play("sonidos/InicioJuego.wav");
		}
		break;
	case START:
		if (key == 'v'||key=='V') {
			estado = VS1_MENU;
			ETSIDI::play("sonidos/InicioJuego.wav");
		}
		if (key == 'm' || key == 'M') {
			estado = VSM_MENU;
			ETSIDI::play("sonidos/InicioJuego.wav");
		}
		break;
		
	case VS1_MENU:
		if (key == 'a' || key == 'A') {
			estado = VS1_5x6_MENU;
			ETSIDI::play("sonidos/InicioJuego.wav");
		}
		else if (key == 'b' || key == 'B') {
			estado = VS1_PETTY_MENU;
			ETSIDI::play("sonidos/InicioJuego.wav");
		}
		
		break;

	case VS1_5x6_MENU:
		if (key == 'i' || key == 'I') { 
			estado = VS1_5x6_INSTR; 
			ETSIDI::play("sonidos/InicioJuego.wav");
		}
		else if (key == 'p' || key == 'P') {
			//tablero.inicializa(0);//Tablero 5x6
			mundo.inicializa(0,0); 
			estado = RATON; 
			ETSIDI::play("sonidos/InicioJuego.wav");
		}
		
		break;
	case VS1_5x6_INSTR:
		if (key == 'y' || key == 'Y') {
			ETSIDI::play("sonidos/InicioJuego.wav");
			estado = VS1_5x6_MENU;
		}
		break;
	case VS1_PETTY_MENU:
		if (key == 'i' || key == 'I') {
			estado = VS1_PETTY_INSTR; 
			ETSIDI::play("sonidos/InicioJuego.wav");
		}
		else if (key == 'p' || key == 'P') {
			mundo.inicializa(1,0);
			estado = RATON; 
			ETSIDI::play("sonidos/InicioJuego.wav");
		}
		break;
		
	case VS1_PETTY_INSTR:
		if (key == 'y' || key == 'Y') {
			ETSIDI::play("sonidos/InicioJuego.wav");
			estado = VS1_PETTY_MENU;
		}
		break;

	case VSM_MENU:
		if (key == 'a' || key == 'A') {
			estado = VSM_5x6_MENU;
			ETSIDI::play("sonidos/InicioJuego.wav");
		}
		else if (key == 'b' || key == 'B') {
			estado = VSM_PETTY_MENU;
			ETSIDI::play("sonidos/InicioJuego.wav");
		}

		break;

	case VSM_5x6_MENU:
		if (key == 'i' || key == 'I') {
			estado = VSM_5x6_INSTR;
			ETSIDI::play("sonidos/InicioJuego.wav");
		}
		else if (key == 'p' || key == 'P') {
			mundo.inicializa(0,1);
			estado = RATON;
			ETSIDI::play("sonidos/InicioJuego.wav");
		}

		break;
	case VSM_5x6_INSTR:
		if (key == 'y' || key == 'Y') {
			ETSIDI::play("sonidos/InicioJuego.wav");
			estado = VSM_5x6_MENU;
		}
		break;
	case VSM_PETTY_MENU:
		if (key == 'i' || key == 'I') {
			estado = VSM_PETTY_INSTR;
			ETSIDI::play("sonidos/InicioJuego.wav");
		}
		else if (key == 'p' || key == 'P') {
			mundo.inicializa(1,1);
			estado = RATON;
			ETSIDI::play("sonidos/InicioJuego.wav");
		}
		break;

	case VSM_PETTY_INSTR:
		if (key == 'y' || key == 'Y') {
			ETSIDI::play("sonidos/InicioJuego.wav");
			estado = VSM_PETTY_MENU;
		}
		break;
	case RATON:
		if (key == 'o' || key == 'O') {
		
			ETSIDI::play("sonidos/InicioJuego.wav");
			estado = JUEGO;
		}
		break;

	case JUEGO:
		if (mundo.get_JMB())
		{
			estado = GANA_AGUA;
		}
		break;
		if (mundo.get_JMN())
		{
			estado = GANA_TIERRA;
		}
		break;
	case GANA_AGUA:
		ETSIDI::play("sonidos/Perder.wav");
		if (key == 'r'||key=='R')
		{
			estado = START;
		}
		if (key == 'e' || key == 'E')
		{
			exit;
		}
		break;
	case GANA_TIERRA:
		ETSIDI::play("sonidos/Ganar.wav");
		if (key == 'r' || key == 'R')
		{
			estado = START;
		}
		if (key == 'e'|| key == 'E')
		{
			exit;
		}
		break;
		
	default:
		break;
	}
}
