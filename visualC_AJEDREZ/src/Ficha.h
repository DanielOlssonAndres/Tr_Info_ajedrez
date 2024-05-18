#pragma once
#include "vector2xy.h"

struct Posicion {
	int x;
	int y;
};

enum Tipo {NEGRAS = 0, BLANCAS};
enum Forma {Peon = 1, Caballo, Alfil, Torre, Dama, Rey};


class Ficha
{
private:
	int valor;
	Vector2xy posicion;
	bool contenido;

public:

	Ficha(int x, int y, int val);
	void Contener_Posicion(int, int);
	void Set_Posicion(int, int);
	Vector2xy Get_Posicion();
	int Get_Valor();

	/*virtual void dibuja() = 0;*/
}

//
//ETSIDI::Sprite sprite_blanco{ "bin/imagenes/T_ALFIL_PATO.png" };
//ETSIDI::Sprite sprite_negro{ "bin/imagenes/A_ALFIL_PULPO.png" };
//
//ETSIDI::Sprite sprite_blanco{ "bin/imagenes/T_CABALLO_CEBRA.png" };
//ETSIDI::Sprite sprite_negro{ "bin/imagenes/A_CABALLO_CABALLITO_DE_MAR.png" };
//
//ETSIDI::Sprite sprite_blanco{ "bin/imagenes/T_DAMA_LEONA.png" };
//ETSIDI::Sprite sprite_negro{ "bin/imagenes/A_DAMA_BALLENA.png" };
//
//ETSIDI::Sprite sprite_blanco{ "bin/imagenes/T_PEON_CONEJO_2.png" };
//ETSIDI::Sprite sprite_negro{ "bin/imagenes/A_PEON_GAMBA.png" };
//
//ETSIDI::Sprite sprite_blanco{ "bin/imagenes/T_REY_LEON.png" };
//ETSIDI::Sprite sprite_negro{ "bin/imagenes/A_REY_TIBURON.png" };
//
//ETSIDI::Sprite sprite_blanco{ "bin/imagenes/T_TORRE_GIRAFA.png" };
//ETSIDI::Sprite sprite_negro{ "bin/imagenes/A_TORRES_CANGREJO.png" };