// ejercicio_propuesto_2.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <thread>
#include <mutex>
#include <iomanip>

struct PuntoPair {
    double x1, y1, x2, y2;
    double distManhattan;
    double distEuclides;
};

// Genera un archivo CSV sintético si no existe previamente en la carpeta
void generarCSV() {
    std::ifstream check("datos.csv");
    if (check.good()) return; // El archivo ya existe
    check.close();

    std::ofstream file("datos.csv");
    file << "x1,y1,x2,y2\n";
    for (int i = 1; i <= 100; ++i) {
        file << i * 1.5 << "," << i * 2.0 << "," << (i + 3) * 1.1 << "," << (i + 5) * 2.5 << "\n";
    }
    file.close();
}

void calcularDistanciasRango(std::vector<PuntoPair>& puntos, size_t inicio, size_t fin) {
    for (size_t i = inicio; i < fin; ++i) {
        double dx = std::abs(puntos[i].x1 - puntos[i].x2);
        double dy = std::abs(puntos[i].y1 - puntos[i].y2);

        // Distancia Manhattan: |x1 - x2| + |y1 - y2|
        puntos[i].distManhattan = dx + dy;

        // Distancia Euclídea: sqrt((x1 - x2)^2 + (y1 - y2)^2)
        puntos[i].distEuclides = std::sqrt(dx * dx + dy * dy);
    }
}

int main() {
    generarCSV();

    std::vector<PuntoPair> puntos;
    std::ifstream file("datos.csv");
    std::string line, token;

    // Omitir cabecera
    std::getline(file, line);

    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        PuntoPair p;
        
        std::getline(ss, token, ','); p.x1 = std::stod(token);
        std::getline(ss, token, ','); p.y1 = std::stod(token);
        std::getline(ss, token, ','); p.x2 = std::stod(token);
        std::getline(ss, token, '\n'); p.y2 = std::stod(token);

        puntos.push_back(p);
    }
    file.close();

    size_t totalPuntos = puntos.size();
    unsigned int numThreads = 4;
    std::vector<std::thread> hilos;
    size_t bloque = totalPuntos / numThreads;

    // Distribuir el cálculo de distancias entre los hilos
    for (unsigned int i = 0; i < numThreads; ++i) {
        size_t inicio = i * bloque;
        size_t fin = (i == numThreads - 1) ? totalPuntos : inicio + bloque;
        hilos.emplace_back(calcularDistanciasRango, std::ref(puntos), inicio, fin);
    }

    for (auto& t : hilos) {
        t.join();
    }

    // Mostrar los 5 primeros elementos requeridos
    std::cout << std::fixed << std::setprecision(3);
    std::cout << "===============================================================\n";
    std::cout << "  PRIMEROS 5 ELEMENTOS CALCULADOS EN PARALELO (CSV)\n";
    std::cout << "===============================================================\n";
    std::cout << "Idx |  P1(x, y)      |  P2(x, y)      | Manhattan | Euclides\n";
    std::cout << "---------------------------------------------------------------\n";

    size_t limite = std::min(size_t(5), puntos.size());
    for (size_t i = 0; i < limite; ++i) {
        std::cout << " " << i + 1 << "  | ("
                  << puntos[i].x1 << ", " << puntos[i].y1 << ") | ("
                  << puntos[i].x2 << ", " << puntos[i].y2 << ") |   "
                  << puntos[i].distManhattan << "   |  "
                  << puntos[i].distEuclides << "\n";
    }
    std::cout << "===============================================================\n";

    return 0;
}