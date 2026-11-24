// Receta.cpp
#ifndef RECETA_CPP
#define RECETA_CPP

#include <iostream>
#include <string>

using namespace std;

class Receta {
protected:
    string nombre;
    string lugarOrigen;
    string ingredientes;
    int tiempoMinutos;
public:
    virtual ~Receta() {}
    virtual void prepararIngredientes() = 0;
    virtual void cocinar() = 0;
    virtual void emplatar() = 0;
    virtual void mostrarReceta() = 0;
};

class Ceviche : public Receta {
public:
    Ceviche() {
        nombre = "Ceviche Clasico";
        lugarOrigen = "Costa del Peru";
        ingredientes = "Pescado fresco, limon, cebolla roja, aji limo, cilantro, camote";
        tiempoMinutos = 20;
    }
    void prepararIngredientes() override {
        cout << "[Ceviche] Cortando pescado en cubos y exprimiendo limones..." << endl;
    }
    void cocinar() override {
        cout << "[Ceviche] Macerando el pescado en jugo de limon y aji por 5 min..." << endl;
    }
    void emplatar() override {
        cout << "[Ceviche] Sirviendo frio acompanado de camote glaseado y choclo." << endl;
    }
    void mostrarReceta() override {
        cout << "Plato: " << nombre << " | Origen: " << lugarOrigen << endl
             << "Ingredientes: " << ingredientes << endl
             << "Tiempo estimado: " << tiempoMinutos << " min" << endl;
    }
};

class RocotoRelleno : public Receta {
public:
    RocotoRelleno() {
        nombre = "Rocoto Relleno";
        lugarOrigen = "Arequipa, Peru";
        ingredientes = "Rocoto, carne picada, mani, pasas, queso fresco, leche, huevo";
        tiempoMinutos = 65;
    }
    void prepararIngredientes() override {
        cout << "[Rocoto Relleno] Desvenando rocotos y picando carne con especias..." << endl;
    }
    void cocinar() override {
        cout << "[Rocoto Relleno] Sofriendo el relleno y horneando con queso gratinado..." << endl;
    }
    void emplatar() override {
        cout << "[Rocoto Relleno] Sirviendo caliente junto con pastel de papa." << endl;
    }
    void mostrarReceta() override {
        cout << "Plato: " << nombre << " | Origen: " << lugarOrigen << endl
             << "Ingredientes: " << ingredientes << endl
             << "Tiempo estimado: " << tiempoMinutos << " min" << endl;
    }
};

class LomoSaltado : public Receta {
public:
    LomoSaltado() {
        nombre = "Lomo Saltado";
        lugarOrigen = "Lima, Peru (Fusion Chifa)";
        ingredientes = "Lomo fino, cebolla, tomate, aji amarillo, sillao, vinagre, papas fritas";
        tiempoMinutos = 30;
    }
    void prepararIngredientes() override {
        cout << "[Lomo Saltado] Cortando lomo en tiras y vegetales en gajos gruesos..." << endl;
    }
    void cocinar() override {
        cout << "[Lomo Saltado] Salteando al wok a fuego alto con sillao y vinagre..." << endl;
    }
    void emplatar() override {
        cout << "[Lomo Saltado] Sirviendo con arroz blanco graneado y papas fritas." << endl;
    }
    void mostrarReceta() override {
        cout << "Plato: " << nombre << " | Origen: " << lugarOrigen << endl
             << "Ingredientes: " << ingredientes << endl
             << "Tiempo estimado: " << tiempoMinutos << " min" << endl;
    }
};

#endif