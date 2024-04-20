#pragma once
class pantalla {
public:
	float ancho;
	float alto;
	float limx;
	float limy;
	
	unsigned char red;
	unsigned char green;
	unsigned char blue;

	pantalla(); //constructor
	void dibuja(); //función para dibujar la pantalla
	void setcolor(unsigned char r, unsigned char g, unsigned char b); //color pantalla
	
};
