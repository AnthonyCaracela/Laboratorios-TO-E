#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>
using namespace std;

// xlase 1: analiza la operación
class Analizador {
public:
    int*  numeros;
    char* operadores;
    int   cantidad;

    Analizador(const string& op) {
        numeros    = new int[op.size()];    // numeros
        operadores = new char[op.size()];   // operaciones
        cantidad   = 0;
        string parse = "";
        for (char c : op) if (c != ' ') parse += c; //limpieza de espacios
        const char* p = parse.c_str();       // puntero al inicio

        while (*p) {
            if (!isdigit(static_cast<unsigned char>(*p))) throw runtime_error("Se esperaba un numero");
            int numero = 0;

            while (*p && isdigit(static_cast<unsigned char>(*p))) {
                numero = numero * 10 + (*p - '0');
                ++p;
            }

            *(numeros + cantidad) = numero;  // notación de puntero
            ++cantidad;

            if (*p) {
                *(operadores + cantidad - 1) = *p;
                ++p;
                if (!*p) throw runtime_error("Operacion termina en operador");
            }
        }

        if (cantidad == 0) throw runtime_error("Operacion vacia");
    }

    ~Analizador() {
        delete[] numeros;
        delete[] operadores;
    }

    Analizador(const Analizador&) = delete;
    Analizador& operator=(const Analizador&) = delete;
};

// clase 2: realiza las operaciones
class Calculadora {
public:
    int calcular(const int* numeros, const char* operadores, int cantidad) const {
        int resultado = *numeros;            // primer número

        for (int i = 0; i < cantidad - 1; ++i) {
            int siguiente = *(numeros + i + 1);
            switch (*(operadores + i)) {
                case '+': resultado += siguiente; break;
                case '-': resultado -= siguiente; break;
                case '*': resultado *= siguiente; break;
                case '/': if (siguiente == 0) throw runtime_error("Division por cero");
                    resultado /= siguiente;
                    break;
                default: throw runtime_error("Operador invalido");
            }
        }
        return resultado;
    }
};

// Clase 3: procesa la entrada
class Procesador {
public:
    void ejecutar() const {
        string operacion;
        cout << "Ingrese una operacion: ";
        getline(cin, operacion);             // lee toda la línea
        Analizador analizador(operacion);
        Calculadora calculadora;
        int resultado = calculadora.calcular(analizador.numeros, analizador.operadores, analizador.cantidad);
        cout << "Resultado: " << resultado << endl;
    }
};

int main() {
    try {
        Procesador programa;
        programa.ejecutar();
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}