#include <iostream>
#include <cstring>

using namespace std;

class ClassCuentaBancaria {
private:
    char *Nombre;
    double Saldo;
    double Interes;

public:
    // Constructor: Reserva memoria para el nombre e inicializa los datos
    ClassCuentaBancaria(const char *nombreInicial, double saldoInicial, double interesInicial) {
        Nombre = new char[strlen(nombreInicial) + 1];
        strcpy(Nombre, nombreInicial);
        Saldo = saldoInicial;
        Interes = interesInicial;
    }

    // Destructor: Libera la memoria asignada dinámicamente
    ~ClassCuentaBancaria() {
        delete[] Nombre;
    }

    char *GetNombre() { return Nombre; }
    double GetSaldo() { return Saldo; }
    void SetSaldo(double Ysaldo) { Saldo = Ysaldo; }
    
    void Ingreso(double xxCantidad) {
        SetSaldo(GetSaldo() + xxCantidad);
    }
};

int main() {
    // Crear una instancia (objeto) de la clase
    ClassCuentaBancaria cuenta1("Maria Rodriguez", 1000.00, 0.05);
    // Consultar saldo inicial usando los métodos de la clase
    cout << "=== CUENTA BANCARIA ===" << endl;
    cout << "Cliente: " << cuenta1.GetNombre() << endl;
    cout << "Saldo inicial: S/ " << cuenta1.GetSaldo() << endl;
    // Realizar un depósito mediante el método Ingreso
    cout << "\nDepósito realizado de: S/ 250.50" << endl;
    cuenta1.Ingreso(250.50);
    // Consultar el saldo actualizado
    cout << "Nuevo saldo:   S/ " << cuenta1.GetSaldo() << endl;

    return 0;
}