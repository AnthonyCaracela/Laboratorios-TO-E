// RecetaFactory.cpp
#ifndef RECETAFACTORY_CPP
#define RECETAFACTORY_CPP

#include <iostream>
#include "Receta.cpp"

using namespace std;

class RecetaFactory {
public:
    static Receta* crearReceta(int tipo) {
        Receta* receta = NULL;
        switch (tipo) {
            case 1:
                receta = new Ceviche();
                break;
            case 2:
                receta = new RocotoRelleno();
                break;
            case 3:
                receta = new LomoSaltado();
                break;
            default:
                cout << "Tipo de receta invalido, ingresa otra opcion." << endl;
                return NULL;
        }
        receta->prepararIngredientes();
        receta->cocinar();
        receta->emplatar();
        return receta;
    }
};

#endif