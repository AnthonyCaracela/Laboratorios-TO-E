#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct EquipoDeportivo {
    string nombre;
    int partidosJugados;
    int victorias;
    int derrotas;
    double porcentajeVictorias;
};

int main() {
    EquipoDeportivo equipos[] = {
        {"Los Angeles Lakers", 82, 47, 35, 57.3},
        {"Boston Celtics",     82, 64, 18, 78.0},
        {"Golden State W.",   82, 46, 36, 56.1},
        {"Miami Heat",         82, 46, 36, 56.1}
    };

    cout << "================ TABLA DE ESTADISTICAS NBA ================" << endl;
    cout << left  << setw(22) << "EQUIPO" 
         << right << setw(6)  << "PJ" 
         << setw(6)  << "PG" 
         << setw(6)  << "PP" 
         << setw(12) << "% VICT." << endl;
    cout << string(52, '-') << endl;

    for (const auto& eq : equipos) {
        cout << left  << setw(22) << eq.nombre 
             << right << setw(6)  << eq.partidosJugados 
             << setw(6)  << eq.victorias 
             << setw(6)  << eq.derrotas 
             << setw(11) << fixed << setprecision(1) << eq.porcentajeVictorias << "%" << endl;
    }

    return 0;
}