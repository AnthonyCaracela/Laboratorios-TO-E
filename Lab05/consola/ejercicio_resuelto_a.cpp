// ejercicio_resuelto_a.cpp
#include <iostream>
using namespace std;

template<typename mitipo>
mitipo aritmetica(mitipo x, mitipo y) {
    return x + y;
}

int main() {
    cout << "int:    " << aritmetica<int>(10, 45) << endl;
    cout << "double: " << aritmetica<double>(3.45, 8.10) << endl;
    cout << "float:  " << aritmetica<float>(0.14f, 0.147f) << endl;
    return 0;
}
