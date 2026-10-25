// ejercicio_propuesto_1.cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <cstdlib>
#include <ctime>

struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo(int val) : dato(val), siguiente(nullptr) {}
};

class ListaEnlazada {
private:
    Nodo* cabeza;
    std::mutex mtx; // Mutex para proteger las operaciones en la lista

public:
    ListaEnlazada() : cabeza(nullptr) {}

    ~ListaEnlazada() {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            Nodo* temp = actual;
            actual = actual->siguiente;
            delete temp;
        }
    }

    void insertar(int val) {
        std::lock_guard<std::mutex> lock(mtx);
        Nodo* nuevo = new Nodo(val);
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
    }

    bool eliminar(int val) {
        std::lock_guard<std::mutex> lock(mtx);
        if (!cabeza) return false;

        if (cabeza->dato == val) {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
            return true;
        }

        Nodo* actual = cabeza;
        while (actual->siguiente && actual->siguiente->dato != val) {
            actual = actual->siguiente;
        }

        if (actual->siguiente) {
            Nodo* temp = actual->siguiente;
            actual->siguiente = actual->siguiente->siguiente;
            delete temp;
            return true;
        }
        return false;
    }

    bool buscar(int val) {
        std::lock_guard<std::mutex> lock(mtx);
        Nodo* actual = cabeza;
        while (actual) {
            if (actual->dato == val) return true;
            actual = actual->siguiente;
        }
        return false;
    }

    bool modificar(int valViejo, int valNuevo) {
        std::lock_guard<std::mutex> lock(mtx);
        Nodo* actual = cabeza;
        while (actual) {
            if (actual->dato == valViejo) {
                actual->dato = valNuevo;
                return true;
            }
            actual = actual->siguiente;
        }
        return false;
    }
};

std::mutex coutMtx; // Mutex exclusivo para evitar solapamientos en consola

void threadEliminar(ListaEnlazada& lista) {
    for (int i = 0; i < 10; ++i) {
        int val = rand() % 20 + 1;
        bool res = lista.eliminar(val);
        std::lock_guard<std::mutex> lock(coutMtx);
        if (res) {
            std::cout << "[Thread 1] Eliminando: " << val << "\n";
        } else {
            std::cout << "[Thread 1] No se eliminó " << val << "\n";
        }
    }
}

void threadInsertar(ListaEnlazada& lista) {
    for (int i = 0; i < 10; ++i) {
        int val = rand() % 20 + 1;
        lista.insertar(val);
        std::lock_guard<std::mutex> lock(coutMtx);
        std::cout << "[Thread 2] Insertando: " << val << "\n";
    }
}

void threadBuscar(ListaEnlazada& lista) {
    for (int i = 0; i < 10; ++i) {
        int val = rand() % 20 + 1;
        bool res = lista.buscar(val);
        std::lock_guard<std::mutex> lock(coutMtx);
        if (res) {
            std::cout << "[Thread 3] Buscado: " << val << "\n";
        } else {
            std::cout << "[Thread 3] No encontrado: " << val << "\n";
        }
    }
}

void threadModificar(ListaEnlazada& lista) {
    for (int i = 0; i < 10; ++i) {
        int valViejo = rand() % 20 + 1;
        int incremento = rand() % 5 + 1;
        int valNuevo = valViejo + incremento;
        bool res = lista.modificar(valViejo, valNuevo);
        std::lock_guard<std::mutex> lock(coutMtx);
        if (res) {
            std::cout << "[Thread 4] Modificando " << valViejo << " a " << valNuevo << "\n";
        } else {
            std::cout << "[Thread 4] No se encontró " << valViejo << "\n";
        }
    }
}

int main() {
    srand(time(NULL));
    ListaEnlazada lista;

    // Precargamos la lista con algunos datos iniciales
    for (int i = 1; i <= 10; ++i) {
        lista.insertar(i * 2);
    }

    // Creación de los 4 hilos en paralelo
    std::thread t1(threadEliminar, std::ref(lista));
    std::thread t2(threadInsertar, std::ref(lista));
    std::thread t3(threadBuscar, std::ref(lista));
    std::thread t4(threadModificar, std::ref(lista));

    // Esperar la sincronización de todos los hilos
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}