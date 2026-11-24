#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Estructura de Componente
struct Pieza {
    string nombre;
    string color;
    float precio;
};

// Producto Final
class Automovil {
public:
    string modelo;
    string pais;
    string colorGeneral;
    vector<Pieza> piezas;
    float costoTotal = 0.0;

    void AgregarPieza(string n, string c, float p) {
        piezas.push_back({n, c, p});
        costoTotal += p;
    }

    void MostrarAuto() {
        cout << "=== Automovil: " << modelo << " (" << pais << ") ===" << endl;
        cout << "Color principal: " << colorGeneral << endl;
        for (auto& p : piezas) {
            cout << "- " << p.nombre << " | Color: " << p.color << " | Precio: $" << p.precio << endl;
        }
        cout << "PRECIO TOTAL: $" << costoTotal << endl;
    }
};

// Interfaz Builder
class IAutoBuilder {
public:
    virtual ~IAutoBuilder() {}
    virtual void construirModelo() = 0;
    virtual void construirMotor() = 0;
    virtual void construirLlantas() = 0;
    virtual void construirInterior() = 0;
    virtual Automovil* ObtenerAuto() = 0;
};

// Builder Concreto: Auto Deportivo
class DeportivoBuilder : public IAutoBuilder {
private:
    Automovil* autoCreado;
public:
    DeportivoBuilder() { autoCreado = new Automovil(); }
    ~DeportivoBuilder() { delete autoCreado; }

    void construirModelo() override {
        autoCreado->modelo = "Deportivo Coupe";
        autoCreado->pais = "Alemania";
        autoCreado->colorGeneral = "Rojo";
    }
    void construirMotor() override {
        autoCreado->AgregarPieza("Motor V8", "Negro", 12000.0);
    }
    void construirLlantas() override {
        autoCreado->AgregarPieza("Llantas Deportivas", "Cromado", 1500.0);
    }
    void construirInterior() override {
        autoCreado->AgregarPieza("Asientos de Cuero", "Rojo", 2000.0);
        autoCreado->AgregarPieza("Timon", "Negro", 500.0);
    }
    Automovil* ObtenerAuto() override { return autoCreado; }
};

// Builder Concreto: Auto Familiar
class FamiliarBuilder : public IAutoBuilder {
private:
    Automovil* autoCreado;
public:
    FamiliarBuilder() { autoCreado = new Automovil(); }
    ~FamiliarBuilder() { delete autoCreado; }

    void construirModelo() override {
        autoCreado->modelo = "SUV Familiar";
        autoCreado->pais = "Japon";
        autoCreado->colorGeneral = "Blanco";
    }
    void construirMotor() override {
        autoCreado->AgregarPieza("Motor Híbrido", "Gris", 8000.0);
    }
    void construirLlantas() override {
        autoCreado->AgregarPieza("Llantas ATR", "Negro", 800.0);
    }
    void construirInterior() override {
        autoCreado->AgregarPieza("Asientos Familiares", "Beige", 1200.0);
        autoCreado->AgregarPieza("Espejos Electricos", "Blanco", 400.0);
    }
    Automovil* ObtenerAuto() override { return autoCreado; }
};

// Director
class Director {
public:
    Automovil* ConstruirAutoCompleto(IAutoBuilder* builder) {
        builder->construirModelo();
        builder->construirMotor();
        builder->construirLlantas();
        builder->construirInterior();
        return builder->ObtenerAuto();
    }
};

int main() {
    Director director;

    cout << "--- CONSTRUYENDO AUTO DEPORTIVO ---" << endl;
    DeportivoBuilder depBuilder;
    Automovil* deportivo = director.ConstruirAutoCompleto(&depBuilder);
    deportivo->MostrarAuto();

    cout << "\n--- CONSTRUYENDO AUTO FAMILIAR ---" << endl;
    FamiliarBuilder famBuilder;
    Automovil* familiar = director.ConstruirAutoCompleto(&famBuilder);
    familiar->MostrarAuto();

    return 0;
}