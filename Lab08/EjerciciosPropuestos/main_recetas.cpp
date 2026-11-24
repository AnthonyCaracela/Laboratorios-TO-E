// main_recetas.cpp
#include <iostream>
#include "RecetaFactory.cpp"

using namespace std;

int main() {
    int tipo;
    while (1) {
        cout << endl << "Selecciona una receta (1: Ceviche, 2: Rocoto Relleno, 3: Lomo Saltado) o '0' para salir: ";
        cin >> tipo;
        if (!tipo) {
            break;
        }
        Receta* plato = RecetaFactory::crearReceta(tipo);
        if (plato) {
            cout << "--- FICHA DE RECETA ---" << endl;
            plato->mostrarReceta();
            delete plato;
        }
    }
    cout << "Cerrando cocina..." << endl;
    return 0;
}