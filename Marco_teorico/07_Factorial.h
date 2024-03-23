#include <iostream>
using namespace std;

int factorial(int n){
    int i, fact = 1;
    for (i = 1; i <= n; i++){
        fact *= i;
    }
    return fact;
}