#include <iostream>
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
        {"LA Lakers",      82, 47, 35, 57.3},
        {"Boston Celtics", 82, 64, 18, 78.0},
        {"Golden State",   82, 46, 36, 56.1},
        {"Miami Heat",     82, 46, 36, 56.1}
    };

    cout << "================ TABLA DE ESTADISTICAS NBA ================" << endl;
    cout << "EQUIPO\t\t\tPJ\tPG\tPP\t% VICT." << endl;
    cout << "-----------------------------------------------------------" << endl;

    for (const auto& eq : equipos) {
        // Control manual de espacios de tabulación según la longitud del texto
        string tabSeparador = (eq.nombre.length() >= 12) ? "\t" : "\t\t";
        
        cout << eq.nombre << tabSeparador
             << eq.partidosJugados << "\t"
             << eq.victorias << "\t"
             << eq.derrotas << "\t"
             << eq.porcentajeVictorias << "%" << endl;
    }

    return 0;
}