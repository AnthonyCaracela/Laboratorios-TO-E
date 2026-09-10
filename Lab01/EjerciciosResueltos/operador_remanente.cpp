#include <iostream>

using namespace std;

int main() {
    int a = 9;
    int b = 10;
    int divisor = 8;

    int residuo1 = a % divisor; 
    int residuo2 = b % divisor; 

    cout << "=== OPERADOR REMANENTE (%) ===" << endl;
    cout << a << " % " << divisor << " = " << residuo1 << endl;
    cout << b << " % " << divisor << " = " << residuo2 << endl;

    // Aplicación práctica: Determinar si un número es Par o Impar
    cout << "\n=== APLICACION PRACTICA (PAR / IMPAR) ===" << endl;
    int numero = 15;

    if (numero % 2 == 0) {
        cout << "El numero " << numero << " es PAR." << endl;
    } else {
        cout << "El numero " << numero << " es IMPAR (Residuo: " << numero % 2 << ")." << endl;
    }

    return 0;
}