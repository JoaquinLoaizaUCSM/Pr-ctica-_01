#include <iostream>
#include <string>

using namespace std;


// validacion
float validaCantidad(float& cant,float stock){
    cout << "Ingrese cantidad de productos de pedido: ";
    cin >> cant;
    while (cant > stock || cant <1) {
        cout << "Cantidad no valida\n vuelva a ingresar:";
        cin >> cant;
    }
    return cant;
}
// informe de pedido
void informePedido(string descr,float cant, float prec){
    cout << "\nInforme de Pedido" << endl;
    cout << "-descricion:   " << descr << endl;
    cout << "-cantidad:     " << cant << endl;
    cout << "-precio total  " << prec*cant << endl;
}
//informe de stock
void informeStock(string descr,float stock){
    cout << "\nInforme de Stock" << endl;
    cout << "-descricion:       " << descr << endl;
    cout << "-Stock disponible: " << stock << endl;
}

int main()
{
    float precio1, precio2, precio3;
    float stock1, stock2, stock3;
    int op;
    string descr1, descr2, descr3;
    float cant1 = 0, cant2 = 0, cant3 = 0;

    precio1 = 1200;
    stock1 = 4;
    descr1 = "Celular";

    precio2 = 80.5;
    stock2 = 2;
    descr2 = "radio";

    precio3 = 1450;
    stock3 = 1;
    descr3 = "Televisor";
    //Pedido

    cout << "Lista de productos" << endl;
    cout << "--   producto 1.   --" << endl;
    cout << "-descricion: " << descr1 << endl;
    cout << "-precio:     " << precio1 << endl;
    cout << "-stock:      " << stock1 << endl;

    cout << "--   producto 2.   --" << endl;
    cout << "-descricion: " << descr2 << endl;
    cout << "-precio:     " << precio2 << endl;
    cout << "-stock:      " << stock2 << endl;

    cout << "--   producto 3.   --" << endl;
    cout << "-descricion: " << descr3 << endl;
    cout << "-precio:     " << precio3 << endl;
    cout << "-stock:      " << stock3 << endl;
    do {
        cout << "ingrese (1, 2, 3) :" ;
        cin >> op ;
    } while (op < 1 || op > 3);

    switch (op) {
        case 1:
            validaCantidad(cant1,stock1);
            // actualizacion de stock
            stock1 -=cant1;
            // informe de pedido
            informePedido(descr1,cant1,precio1);
            // informe de Stock
            informeStock(descr1,stock1);
            break;
        case 2:
            validaCantidad(cant2,stock2);
            // actualizacion de stock
            stock2 -=cant2;
            // informe de pedido
            informePedido(descr2,cant2,precio2);
            // informe de Stock
            informeStock(descr2,stock2);
            break;
        case 3:
            validaCantidad(cant3,stock3);
            // actualizacion de stock
            stock1 -=cant3;
            // informe de pedido
            informePedido(descr3,cant3,precio3);
            // informe de Stock
            informeStock(descr3,stock3);
            break;

    }
}