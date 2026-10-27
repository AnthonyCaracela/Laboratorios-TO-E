// ejercicio_resuelto_b.cpp
#include <iostream>
using namespace std;

// Versiones sin plantilla (una por tipo)
char mayorLetras(char a, char b) { return (a > b ? a : b); }
int  mayorNumeros(int a, int b)  { return (a > b ? a : b); }

// Version generica
template <typename Tipo>
Tipo mayorDe(Tipo a, Tipo b) {
    return (a > b ? a : b);
}

int main() {
    char x = mayorDe<char>('e', 'z');
    int  y = mayorDe<int>(9, 4);
    cout << "caracter mayor: " << x << endl;
    cout << "numero mayor: " << y << endl;
    return 0;
}
