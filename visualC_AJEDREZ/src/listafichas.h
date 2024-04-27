#pragma once
#include <vector>
#include "ficha.h"

using std::vector;

class Listafichas
{
	vector<Ficha*> lista;

public:
	void agregar(Ficha* f) { lista.push_back(f); }
	void dibuja() { for (auto f : lista)f->dibuja(); }
	
};

