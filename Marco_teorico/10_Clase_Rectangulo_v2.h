#include <iostream>
using namespace std;

class Rectangulo_2{
private:
    int ancho, alto;
public:
    void setAncho(int a){
        ancho = a;
    }

    void setAlto(int h){
        alto = h;
    }

    int area(){
        return ancho*alto;
    }

    int perimetro(){
        return 2*(ancho+alto);
    }

};

