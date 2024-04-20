#include "freeglut.h"
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "ETSIDI.h"
#include "Inicio.h"
#include "Pantalla.h"

using namespace std;

pantalla::pantalla(){
    ancho=40;
    alto=20;
    red=0;
    green=0;
    blue=255; //color azul para la pantalla
}

void pantalla::setcolor(unsigned char r, unsigned char g, unsigned char b){
    r=red;
    g=green;
    b=blue;
}
