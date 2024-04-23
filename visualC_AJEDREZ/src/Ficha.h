#pragma once

#include "peon.h"
#include "torre.h"
#include "caballo.h"
#include "alfil.h"
#include "rey.h"
#include "dama.h"

enum {BLANCA = 0, NEGRA = 1};

class Ficha
{
	bool color;

public:
	void inicializa();
	void dibuja();

};

