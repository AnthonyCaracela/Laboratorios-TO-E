#include <iostream>
#include <string>

// Clase Base Abstracta
class NodoExpresion {
public:
    virtual ~NodoExpresion() {}
    virtual double evaluar() const = 0;
    virtual void imprimirConsola(const std::string& prefijo = "", bool esUltimo = true) const = 0;
};

// Clase para Números (Hojas)
class NodoNumero : public NodoExpresion {
private:
    double valor;

public:
    NodoNumero(double val) : valor(val) {}

    double evaluar() const override {
        return valor;
    }

    void imprimirConsola(const std::string& prefijo = "", bool esUltimo = true) const override {
        std::cout << prefijo;
        std::cout << (esUltimo ? " +-- " : " |-- ");
        std::cout << "[" << valor << "]\n";
    }
};

// Clase para Operadores (+, *)
class NodoOperador : public NodoExpresion {
private:
    char operador;
    NodoExpresion* izquierdo;
    NodoExpresion* derecho;

public:
    NodoOperador(char op, NodoExpresion* izq, NodoExpresion* der)
        : operador(op), izquierdo(izq), derecho(der) {}

    ~NodoOperador() override {
        delete izquierdo;
        delete derecho;
    }

    double evaluar() const override {
        if (operador == '+') return izquierdo->evaluar() + derecho->evaluar();
        if (operador == '*') return izquierdo->evaluar() * derecho->evaluar();
        return 0.0;
    }

    void imprimirConsola(const std::string& prefijo = "", bool esUltimo = true) const override {
        std::cout << prefijo;
        std::cout << (esUltimo ? " +-- " : " |-- ");
        std::cout << "(" << operador << ")\n";

        std::string nuevoPrefijo = prefijo + (esUltimo ? "     " : " |   ");

        if (izquierdo) izquierdo->imprimirConsola(nuevoPrefijo, false);
        if (derecho) derecho->imprimirConsola(nuevoPrefijo, true);
    }
};

int main() {
    std::cout << "=========================================================\n";
    std::cout << "    EJERCICIO 3: BINARY EXPRESSION TREE (CONSOLA)       \n";
    std::cout << "=========================================================\n\n";

    // Expresion: 54 + ( (5 * 34) + (1 * 2) )
    NodoExpresion* mult1 = new NodoOperador('*', new NodoNumero(5), new NodoNumero(34));
    NodoExpresion* mult2 = new NodoOperador('*', new NodoNumero(1), new NodoNumero(2));
    NodoExpresion* sumaDer = new NodoOperador('+', mult1, mult2);
    NodoExpresion* raiz = new NodoOperador('+', new NodoNumero(54), sumaDer);

    std::cout << "REPRESENTACION DEL ARBOL EN CONSOLA:\n\n";
    raiz->imprimirConsola();

    std::cout << "\n---------------------------------------------------------\n";
    std::cout << "EVALUACION MATEMATICA:\n";
    std::cout << "54 + 5 * 34 + 1 * 2 = " << raiz->evaluar() << "\n";
    std::cout << "---------------------------------------------------------\n";

    delete raiz;
    return 0;
}