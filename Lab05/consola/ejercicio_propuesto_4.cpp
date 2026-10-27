// ejercicio_propuesto_4.cpp  (Arbol binario de busqueda con plantilla)
#include <iostream>
using namespace std;

template<typename T>
class ArbolBinario {
private:
    struct NodoArbol {
        T dato;
        NodoArbol *izq, *der;
        NodoArbol(const T& v) : dato(v), izq(nullptr), der(nullptr) {}
    };
    NodoArbol* raiz;

    NodoArbol* insertar(NodoArbol* n, const T& v) {
        if (!n) return new NodoArbol(v);
        if (v < n->dato)      n->izq = insertar(n->izq, v);
        else if (v > n->dato) n->der = insertar(n->der, v);
        return n;                                   // se ignoran duplicados
    }
    void inorden(NodoArbol* n) const {
        if (!n) return;
        inorden(n->izq);
        cout << n->dato << " ";
        inorden(n->der);
    }
    void destruir(NodoArbol* n) {
        if (!n) return;
        destruir(n->izq);
        destruir(n->der);
        delete n;
    }
public:
    ArbolBinario() : raiz(nullptr) {}
    ArbolBinario(const ArbolBinario&) = delete;
    ArbolBinario& operator=(const ArbolBinario&) = delete;
    ~ArbolBinario() { destruir(raiz); }
    void insertar(const T& v) { raiz = insertar(raiz, v); }
    bool buscar(const T& v) const {
        NodoArbol* a = raiz;
        while (a) {
            if (v == a->dato) return true;
            a = (v < a->dato) ? a->izq : a->der;
        }
        return false;
    }
    void mostrarInorden() const { inorden(raiz); cout << endl; }
};

int main() {
    ArbolBinario<int> ai;
    for (int v : {50, 30, 70, 20, 40, 60, 80}) ai.insertar(v);
    cout << "Enteros (inorden): ";  ai.mostrarInorden();
    cout << "Buscar 40: " << (ai.buscar(40) ? "encontrado" : "no encontrado") << endl;

    ArbolBinario<double> ad;
    for (double v : {5.5, 2.2, 8.8, 1.1}) ad.insertar(v);
    cout << "Doubles (inorden): ";  ad.mostrarInorden();

    ArbolBinario<char> ac;
    for (char v : {'m', 'c', 'x', 'a', 'e'}) ac.insertar(v);
    cout << "Caracteres (inorden): ";  ac.mostrarInorden();
    return 0;
}
