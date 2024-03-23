#include <iostream>
using namespace std;

void func_02(){
    int a, b;
    cin >> a;
    cin >> b;
    if (a>b){
        cout << a << " es mayor que " << b << endl;
    } else{
        if (a == b){
            cout << " Son iguales " << endl;
        } else{
            cout << b << " es mayor que " << a << endl;
        }
    }
}