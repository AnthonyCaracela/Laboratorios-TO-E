#include <iostream>
#include <cstdlib> // Requerido para rand() y srand()
#include <ctime>   // Requerido para time()

using namespace std;

// Función para ordenar un arreglo de mayor a menor (Algoritmo Burbuja)
void ordenarMayorAMenor(int arreglo[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arreglo[j] < arreglo[j + 1]) { // Cambio para orden descendente
                int aux = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = aux;
            }
        }
    }
}

int main() {
    int N;
    char opcion;

    do {
        cout << "Ingrese el tamano N (numero entero positivo): ";
        cin >> N;
        if (N <= 0) {
            cout << "Error: N debe ser un entero positivo mayor a 0.\n";
        }
    } while (N <= 0);

    int numeros[N];

    cout << "Elija una opcion ('g' = autogenerar aleatorios, 'i' = ingreso manual): ";
    cin >> opcion;

    if (opcion == 'g' || opcion == 'G') {
        // Inicializar la semilla para números aleatorios diferentes en cada ejecución
        srand(time(NULL));
        cout << "\nGenerando " << N << " numeros aleatorios entre 1 y " << N << "...\n";
        for (int i = 0; i < N; i++) {
            // rand() % N genera un número entre 0 y N-1, sumando 1 queda entre 1 y N
            numeros[i] = (rand() % N) + 1;
        }
    } else if (opcion == 'i' || opcion == 'I') {
        cout << "\nIngrese los " << N << " numeros enteros:\n";
        for (int i = 0; i < N; i++) {
            cout << "Numero [" << i + 1 << "]: ";
            cin >> numeros[i];
        }
    } else {
        cout << "Opcion no valida. Saliendo del programa.\n";
        return 1;
    }

    // Mostrar arreglo original
    cout << "\nArreglo original: ";
    for (int i = 0; i < N; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    ordenarMayorAMenor(numeros, N);

    // Mostrar resultado ordenado
    cout << "Arreglo ordenado (Mayor a Menor): ";
    for (int i = 0; i < N; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    return 0;
}