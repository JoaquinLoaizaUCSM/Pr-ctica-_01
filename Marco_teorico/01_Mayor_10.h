#include <iostream>
using namespace std;

void func_01(){
    int x;
    cin >> x;
    if (x>10){
        cout << x << " es mayor que 10. " << endl;
    } else { if (x == 10){
        cout << x << " es igual que 10. ";
    } else {
        cout << x << " es menor que 10. " << endl;
        }
    }
}

