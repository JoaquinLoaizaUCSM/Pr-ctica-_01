#include <iostream>
using namespace std;
#include "01_Mayor_10.h"
#include "03_Mayor_Menor.h"
#include "05_Clase_Punto.h"
#include "07_Factorial.h"
#include "08_Clase_Rectangulo.h"
#include "10_Clase_Rectangulo_v2.h"

int main() {
    //Creamos un objeto del .h "P_03"
    Punto C1; //C1 de coordenada 1
    C1.x = 1;
    C1.y = 3;
    C1.coordenada();

    C1.desplazar(5,4);
    cout << "Nueva coordenada: " << endl;
    C1.coordenada();

    //Creamos un objeto del .h "P_05"
    Rectangulo R1;
    R1.setAncho(4);
    R1.setAlto(10);
    cout << "El area del rectangulo 1 es: "<< R1.area() << " y su perimetro es de " << R1.perimetro() << endl;

    //Creamos un objeto del .h "P_06"
    Rectangulo_2 R2;
    R2.setAncho(5);
    R2.setAlto(140);
    cout << "El area del rectangulo 2 es: "<< R2.area() << " y su perimetro es de " << R2.perimetro() << endl;



    return 0;
}
