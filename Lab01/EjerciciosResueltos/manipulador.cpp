#include <iostream>
#include <iomanip> // Librería requerida para manipular el formato (setw)
using namespace std;

int main() {
    long pop1 = 2425785, pop2 = 47, pop3 = 9761;

    // setw(N) define un ancho fijo de N caracteres alineado a la derecha
    cout << left << setw(12) << "UBICACION" << right << setw(10) << "POB." << endl;
    cout << left << setw(12) << "Lima"      << right << setw(10) << pop1 << endl;
    cout << left << setw(12) << "Atora"     << right << setw(10) << pop2 << endl;
    cout << left << setw(12) << "Sicuani"   << right << setw(10) << pop3 << endl;

    return 0;
}