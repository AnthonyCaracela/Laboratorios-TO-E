#include <iostream>
#include <string>

using namespace std;

// Clase Base 1
class infante {
protected:
    string nombre;
public:
    infante(const string &nom) : nombre(nom) {}
    void gatear() const {
        cout << nombre << " gateando...\n";
    }
};

// Clase Base 2
class joven {
protected:
    string nombre;
public:
    joven(const string &nom) : nombre(nom) {}
    void correr() const {
        cout << nombre << " corriendo...\n";
    }
};

// Clase Derivada mediante Herencia Múltiple
class adulto : public infante, public joven {
private:
    string nombre;
public:
    adulto(const string &nom) 
        : infante(nom), joven(nom), nombre(nom) {}

    void caminar() const {
        cout << nombre << " caminando...\n";
    }
};

int main() {
    cout << "=== EJERCICIO RESUELTO 1: HERENCIA MULTIPLE ===\n\n";

    adulto persona("Carlos");

    // Métodos heredados de infante y joven
    persona.gatear();
    persona.correr();
    
    // Método propio de adulto
    persona.caminar();

    return 0;
}