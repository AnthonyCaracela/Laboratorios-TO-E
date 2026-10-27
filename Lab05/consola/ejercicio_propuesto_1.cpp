// ejercicio_propuesto_1.cpp
#include <iostream>
#include <string>
using namespace std;

template<typename T>
struct Nodo {
    T dato;
    Nodo<T>* siguiente;
    Nodo(const T& v) : dato(v), siguiente(nullptr) {}
};

template<typename T>
class ListaEnlazada {
private:
    Nodo<T>* cabeza;
public:
    ListaEnlazada() : cabeza(nullptr) {}
    ListaEnlazada(const ListaEnlazada&) = delete;
    ListaEnlazada& operator=(const ListaEnlazada&) = delete;
    ~ListaEnlazada() {
        while (cabeza) {
            Nodo<T>* t = cabeza;
            cabeza = cabeza->siguiente;
            delete t;
        }
    }
    void insertar(const T& v) {          // inserta al final
        Nodo<T>* nuevo = new Nodo<T>(v);
        if (!cabeza) { cabeza = nuevo; return; }
        Nodo<T>* a = cabeza;
        while (a->siguiente) a = a->siguiente;
        a->siguiente = nuevo;
    }
    bool eliminar(const T& v) {
        Nodo<T>** p = &cabeza;
        while (*p && (*p)->dato != v) p = &(*p)->siguiente;
        if (!*p) return false;
        Nodo<T>* t = *p;
        *p = t->siguiente;
        delete t;
        return true;
    }
    void mostrar() const {
        for (Nodo<T>* a = cabeza; a; a = a->siguiente) cout << a->dato << " -> ";
        cout << "NULL" << endl;
    }
};

int main() {
    ListaEnlazada<int> edades;
    edades.insertar(20); edades.insertar(25); edades.insertar(31); edades.insertar(18);
    cout << "Edades: ";  edades.mostrar();
    edades.eliminar(25);
    cout << "Edades (sin 25): ";  edades.mostrar();

    ListaEnlazada<string> palabras;
    palabras.insertar("hola"); palabras.insertar("mundo"); palabras.insertar("plantillas");
    cout << "Palabras: ";  palabras.mostrar();
    return 0;
}
