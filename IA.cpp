#include "IA.h"
//MODIFICAR LOS RETURN DE LOS MOVIMIEINTOS PARA QUE SIEMPRE DEVUELVA SOL

/*#include <iostream>


bool IA::movimiento(int E)
{
	//Inicializamos jugadas aleatorias (tiempo)
	srand(time(NULL));
	bool elige_jugada = true;
	time_t t_ini = time(NULL); //LIMITAMOS TIMEPO ELEGIR PARTIDA
	while (time(NULL) <= t_ini + 5) {
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 5; j++)
			{//RECORRE MATRIZ PARA SELECCIONAR FICHA DE SU COLOR
				if (matriz[i][j] > 0 ){
					if (rand() % 10 == 5) {
						bool mover = true;
							while(mover)
								mover=false;
								origen.x=i;origen.y=j;
								//SELECCIONAMOS CASILLAS DE DESTINO
								for (int k = 0; k < 6; k++) {
									for (int l = 0; l < 5; l++) {
										if (tablero.Selec_Mover(k, l) = true)
										{
											mover=true;
											if (rand() % 5 == 3) {
												if (tablero.Selec_Mover) {
													return true;
												}
												}
										}
									}
								}
					}
				}
			}
		}
	}

	return false;
}*/