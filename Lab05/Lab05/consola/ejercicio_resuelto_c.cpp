// ejercicio_resuelto_c.cpp
#include <iostream>
using namespace std;

template<typename T>
class Contenedor {
public:
    T metodo1(int xx) { return array[xx]; }
    void metodo2(T val, int i) { array[i] = val; }
    void mostrar() const;
private:
    T array[4];
};

template<typename T>
void Contenedor<T>::mostrar() const {
    for (int i = 0; i < 4; i++) {   // corregido: i < 4 (el original usaba i <= 4)
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    Contenedor<int> z;
    z.metodo2(10, 0);
    z.metodo2(50, 1);
    z.metodo2(60, 2);
    z.metodo2(70, 3);
    z.mostrar();
    cout << "Posicion 2: " << z.metodo1(2) << endl;
    return 0;
}
