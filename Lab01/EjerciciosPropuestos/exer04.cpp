#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Estructura CitaMedica con 4 métodos integrados
struct CitaMedica {
    int idCita;
    string numeroAsegurado;
    string nombrePaciente;
    string fechaHora;
    string especialidad;
    double costo;
    bool confirmada;

    // Método 1: Registrar o inicializar la cita
    void registrarCita(int id, string asegurado, string paciente, string fecha, string esp, double precio) {
        idCita = id;
        numeroAsegurado = asegurado;
        nombrePaciente = paciente;
        fechaHora = fecha;
        especialidad = esp;
        costo = precio;
        confirmada = false; // Por defecto inicia sin confirmar
    }

    // Método 2: Confirmar la cita médica
    void confirmarCita() {
        confirmada = true;
        cout << ">> La cita #" << idCita << " ha sido CONFIRMADA con exito.\n";
    }

    // Método 3: Cancelar la cita
    void cancelarCita() {
        confirmada = false;
        cout << ">> La cita #" << idCita << " ha sido CANCELADA.\n";
    }

    // Método 4: Imprimir el ticket de atención
    void imprimirTicket() {
        cout << "\n================ TICKET DE CITA MEDICA ================\n";
        cout << "ID Cita:          " << idCita << "\n";
        cout << "Nro. Asegurado:   " << numeroAsegurado << "\n";
        cout << "Paciente:         " << nombrePaciente << "\n";
        cout << "Fecha y Hora:     " << fechaHora << "\n";
        cout << "Especialidad:     " << especialidad << "\n";
        cout << "Costo Consulta:   S/ " << fixed << setprecision(2) << costo << "\n";
        cout << "Estado:           " << (confirmada ? "CONFIRMADA" : "PENDIENTE/CANCELADA") << "\n";
        cout << "=======================================================\n";
    }
};

int main() {
    // Instanciación del struct
    CitaMedica cita1;

    // Uso de los métodos del struct
    cita1.registrarCita(101, "ESSALUD-98765", "Carlos Mendoza", "15/10/2026 09:30 AM", "Cardiologia", 85.00);
    cita1.imprimirTicket();

    // Confirmación y nuevo reporte
    cita1.confirmarCita();
    cita1.imprimirTicket();

    return 0;
}