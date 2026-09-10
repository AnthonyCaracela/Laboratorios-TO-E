#include <iostream>
#include <cstring> // Requerido para utilizar strcpy

using namespace std;

// Estructura original del docente
struct Persona {
    long nroMatricula;
    char nombres[100];
};

int main() {
    // Instanciación de la estructura
    Persona p1;

    // Asignación de datos a los atributos
    p1.nroMatricula = 20260045;
    strcpy(p1.nombres, "Juan Perez"); // Copia el texto dentro del arreglo de caracteres

    // Impresión de los valores
    cout << "=== REGISTRO DE PERSONA ===" << endl;
    cout << "Nro. Matricula: " << p1.nroMatricula << endl;
    cout << "Nombres:        " << p1.nombres << endl;

    return 0;
}