// Object.cpp
#ifndef OBJECT_CPP
#define OBJECT_CPP

#include <iostream>
#include <string>

using namespace std;

class Toy {
protected:
    string name;
    float price;
public:
    virtual ~Toy() {}
    virtual void prepareParts() = 0;
    virtual void combineParts() = 0;
    virtual void assembleParts() = 0;
    virtual void applyLabel() = 0;
    virtual void showProduct() = 0;
};

class Car : public Toy {
public:
    Car() {
        name = "Auto Deportivo";
        price = 25.50f;
    }
    void prepareParts() override { cout << "Preparando partes de Car" << endl; }
    void combineParts() override { cout << "Combinando partes de Car" << endl; }
    void assembleParts() override { cout << "Ensamblando partes de Car" << endl; }
    void applyLabel() override { cout << "Aplicando etiquetado de Car" << endl; }
    void showProduct() override { 
        cout << "Name: " << name << endl << "Price: $" << price << endl; 
    }
};

class Bike : public Toy {
public:
    Bike() {
        name = "Bicicleta de Montana";
        price = 45.00f;
    }
    void prepareParts() override { cout << "Preparando partes de Bike" << endl; }
    void combineParts() override { cout << "Combinando partes de Bike" << endl; }
    void assembleParts() override { cout << "Ensamblando partes de Bike" << endl; }
    void applyLabel() override { cout << "Aplicando etiquetado de Bike" << endl; }
    void showProduct() override { 
        cout << "Name: " << name << endl << "Price: $" << price << endl; 
    }
};

class Plane : public Toy {
public:
    Plane() {
        name = "Avion Comercial";
        price = 60.75f;
    }
    void prepareParts() override { cout << "Preparando partes de Plane" << endl; }
    void combineParts() override { cout << "Combinando partes de Plane" << endl; }
    void assembleParts() override { cout << "Ensamblando partes de Plane" << endl; }
    void applyLabel() override { cout << "Aplicando etiquetado de Plane" << endl; }
    void showProduct() override { 
        cout << "Name: " << name << endl << "Price: $" << price << endl; 
    }
};

#endif
