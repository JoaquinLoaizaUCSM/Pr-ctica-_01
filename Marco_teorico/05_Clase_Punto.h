#include <iostream>
using namespace std;

class Punto{
public:
    double x, y;
    //Funcion que variará el punto x y el punto y
    void desplazar(double dx, double dy){
        x += dx;
        y += dy;
    }
    void coordenada(){
        cout << "x: " << x << " y: " << y << endl;
    }
};

