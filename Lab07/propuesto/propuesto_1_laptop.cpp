#include <iostream>
#include <vector>
#include <string>

using namespace std;

// --- Componentes Base ---
class item {
public:
    virtual ~item() {}
    virtual string GetName() = 0;
    virtual float GetPrice() = 0;
    virtual void GetConfiguration() = 0;
};

// --- Componentes Básicos (reutilizados) ---
class Processor : public item {};
class IntelI5 : public Processor {
public:
    string GetName() override { return "Intel i5"; }
    float GetPrice() override { return 3000.00; }
    void GetConfiguration() override { cout << "1.50 Ghz, 4 threads" << endl; }
};
class IntelI7 : public Processor {
public:
    string GetName() override { return "Intel i7"; }
    float GetPrice() override { return 4700.00; }
    void GetConfiguration() override { cout << "1.6 Ghz, 8 threads" << endl; }
};

class Drive : public item {};
class HDD : public Drive {
public:
    string GetName() override { return "HDD"; }
    float GetPrice() override { return 150.00; }
    void GetConfiguration() override { cout << "1 TB" << endl; }
};
class SSD : public Drive {
public:
    string GetName() override { return "SSD"; }
    float GetPrice() override { return 270.00; }
    void GetConfiguration() override { cout << "250 GB" << endl; }
};

class DisplayType : public item {};
class Normal : public DisplayType {
public:
    string GetName() override { return "Normal"; }
    float GetPrice() override { return 195.00; }
    void GetConfiguration() override { cout << "15.6 inch FHD" << endl; }
};
class Plasma : public DisplayType {
public:
    string GetName() override { return "Plasma"; }
    float GetPrice() override { return 800.00; }
    void GetConfiguration() override { cout << "17.3 inch Plasma" << endl; }
};

// --- NUEVOS COMPONENTES (Ejercicio 1) ---
class Color : public item {};
class Negro : public Color {
public:
    string GetName() override { return "Color Negro"; }
    float GetPrice() override { return 50.00; }
    void GetConfiguration() override { cout << "Mate" << endl; }
};

class Marca : public item {};
class Lenovo : public Marca {
public:
    string GetName() override { return "Marca Lenovo"; }
    float GetPrice() override { return 200.00; }
    void GetConfiguration() override { cout << "Garantia extendida" << endl; }
};

class Impresora : public item {};
class HP : public Impresora {
public:
    string GetName() override { return "Impresora HP"; }
    float GetPrice() override { return 450.00; }
    void GetConfiguration() override { cout << "Multifuncional" << endl; }
};

// --- Producto ---
class laptop {
private:
    vector<item*> mLaptopParts;
public:
    ~laptop() {
        for (auto p : mLaptopParts) delete p;
    }
    void AddParts(item* item) { mLaptopParts.push_back(item); }
    float GetCost() {
        float cost = 0.0;
        for (auto i : mLaptopParts) cost += i->GetPrice();
        return cost;
    }
    void GetConfiguration() {
        for (auto i = 0; i < mLaptopParts.size(); i++) {
            cout << mLaptopParts[i]->GetName() << ": ";
            mLaptopParts[i]->GetConfiguration();
        }
    }
};

// --- Builder ---
class laptopBuilder {
public:
    laptop* opcionBasica() {
        laptop* lap = new laptop();
        lap->AddParts(new IntelI5());
        lap->AddParts(new Normal());
        lap->AddParts(new HDD());
        lap->AddParts(new Negro());
        return lap;
    }
    
    laptop* opcionCompleta() {
        laptop* lap = new laptop();
        lap->AddParts(new IntelI7());
        lap->AddParts(new Plasma());
        lap->AddParts(new SSD());
        lap->AddParts(new Negro());
        lap->AddParts(new Lenovo());
        lap->AddParts(new HP());
        return lap;
    }
};

int main() {
    laptopBuilder cotizar;
    
    cout << "--- Opcion Basica ---" << endl;
    laptop* basic = cotizar.opcionBasica();
    basic->GetConfiguration();
    cout << "Total: " << basic->GetCost() << endl;
    delete basic;

    cout << "\n--- Opcion Completa (con extras) ---" << endl;
    laptop* full = cotizar.opcionCompleta();
    full->GetConfiguration();
    cout << "Total: " << full->GetCost() << endl;
    delete full;

    return 0;
}