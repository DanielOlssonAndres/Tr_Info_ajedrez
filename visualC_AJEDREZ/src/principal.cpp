#include "freeglut.h"
#include "ETSIDI.h"
#include "iostream"

#include "mundo.h"

Mundo mundo;

//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void OnMouseClick(int button, int state, int x, int y); //Control del ratón
void selec_2_casillas(Vector2xy casilla1, Ficha* casilla2[6][5]); //guardar 2 casillas 

int main(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("GambitoDeDama");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(OnMouseClick); //Callback del raton

	//INICIALIZACION

	mundo.inicializa();
	/*selec_2_casillas (mundo.casillaSelec, mundo.tablero.MatTablero[6][5]);*/

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();

	return 0;
}

void OnDraw(void)
{
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//funciones de dibujo

	mundo.dibuja();

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado


	glutPostRedisplay();
}

void OnTimer(int value)
{
	//poner aqui el código de animacion


		//no borrar estas lineas
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}

void OnMouseClick(int b, int state, int x, int y) {
	////////////// 
	//Captura el click con el ratón con o sin teclas especiales (CTRL or SHIFT)
	//Da el control al tablero en la escena
	bool down = (state == GLUT_DOWN);
	int button;
	if (b == GLUT_LEFT_BUTTON) {
		button = MOUSE_LEFT_BUTTON;
	}
	if (b == GLUT_RIGHT_BUTTON) {
		button = MOUSE_RIGHT_BUTTON;
		cout << "MOUSE_RIGHT_BUTTON" << endl;
	}

	int specialKey = glutGetModifiers();
	bool ctrlKey = (specialKey & GLUT_ACTIVE_CTRL) ? true : false;
	bool sKey = specialKey & GLUT_ACTIVE_SHIFT;


	mundo.MouseButton(x, y, b, down, sKey, ctrlKey);
	glutPostRedisplay();
}

void selec_2_casillas( Vector2xy casilla1, Ficha* casilla2 [6][5])
{
	int i, j;
	casilla1.x = i;
	casilla1.y = j;
	Vector2xy casilladestino;
	
	if (casilla2[i][j] != nullptr)
	{
		OnMouseClick; //Callback del raton, se debería de renovar la ubicación de casilla1

		if (casilla2[i][j] != nullptr) 
		{
			std::cout << "Se moverá a esta casilla" << std::endl;
			cout << "(" << casilla1.x << "," << casilla1.y << ")" << endl;

		}
		else 
		{
			std::cout << "Seleccione una casilla vacia" << std::endl;
		}

	}
	else
	{
		std::cout << "Primero seleccione una ficha" << std::endl;
	}

	std::cout << "La función ha sido llamada" << std::endl;

}