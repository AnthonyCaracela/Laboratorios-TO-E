#include <iostream>
#include <vector>
#include <string>
#include <functional>

using namespace std;

// Clase base abstracta
class Cuenta {
protected:
    string titular;
    float saldo;
    string tipo;
public:
    Cuenta(string t, float s, string tip) : titular(t), saldo(s), tipo(tip) {}
    virtual ~Cuenta() {}
    
    virtual float CalcularInteres() = 0;
    
    void MostrarDatos() {
        cout << "[" << tipo << "] Titular: " << titular 
             << " | Saldo: $" << saldo 
             << " | Interes: " << CalcularInteres() << "%" << endl;
    }
};

// Cuentas Específicas
class Ahorro : public Cuenta {
public:
    Ahorro(string t, float s) : Cuenta(t, s, "Ahorro") {}
    float CalcularInteres() override { return 0.45; }
};

class Joven : public Cuenta {
public:
    Joven(string t, float s) : Cuenta(t, s, "Joven") {}
    float CalcularInteres() override { return 2.50; }
};

class Empresarial : public Cuenta {
public:
    Empresarial(string t, float s) : Cuenta(t, s, "Empresarial") {}
    float CalcularInteres() override { return 1.20; }
};

class TarjetaCredito : public Cuenta {
public:
    TarjetaCredito(string t, float s) : Cuenta(t, s, "Tarjeta de Credito") {}
    float CalcularInteres() override { return 18.50; } // Compras
};

// Uso de Templates y Lambdas para funcionalidad extra (Liquidaciones)
template <typename T>
void LiquidarDeuda(T& cuenta, function<float(float)> descuento) {
    float interes = cuenta.CalcularInteres();
    float montoDescontado = descuento(interes);
    cout << "Liquidando deuda. Interes original: " << interes 
         << "%, Descuento aplicado: " << montoDescontado << "%" << endl;
}

int main() {
    vector<Cuenta*> cuentas;
    cuentas.push_back(new Ahorro("Ana", 1500.0));
    cuentas.push_back(new Joven("Luis", 500.0));
    cuentas.push_back(new Empresarial("ACME SAC", 10000.0));
    cuentas.push_back(new TarjetaCredito("Carlos", -2000.0));

    cout << "=== ESTADO DE CUENTA GLOBAL ===" << endl;
    for (auto c : cuentas) {
        c->MostrarDatos();
    }

    cout << "\n=== LIQUIDACION CON LAMBDA (Descuento 2%) ===" << endl;
    // Lambda que resta 2% de interes
    auto descuento2 = [](float i) { return i * 0.02f; }; 
    LiquidarDeuda(*cuentas[3], descuento2);

    for (auto c : cuentas) delete c;
    return 0;
}