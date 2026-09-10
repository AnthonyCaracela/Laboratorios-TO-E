#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class CitaMedica {
private:
    // Atributos encapsulados (privados)
    int idCita;
    string numeroAsegurado;
    string nombrePaciente;
    string fechaHora;
    string especialidad;
    double costo;
    bool confirmada;

public:
    // Constructor
    CitaMedica(int id, string asegurado, string paciente, string fecha, string esp, double precio) {
        idCita = id;
        numeroAsegurado = asegurado;
        nombrePaciente = paciente;
        fechaHora = fecha;
        especialidad = esp;
        costo = precio;
        confirmada = false;
    }

    // Getters y Setters
    int getIdCita() const { return idCita; }
    bool isConfirmada() const { return confirmada; }
    void setFechaHora(const string &nuevaFecha) { fechaHora = nuevaFecha; }

    // Métodos de negocio
    void confirmarCita() {
        confirmada = true;
        cout << ">> [CLASE] Cita #" << idCita << " marcada como CONFIRMADA.\n";
    }

    void cancelarCita() {
        confirmada = false;
        cout << ">> [CLASE] Cita #" << idCita << " ha sido CANCELADA.\n";
    }

    void imprimirTicket() const {
        cout << "\n================ TICKET CITA (CLASE POO) ================\n";
        cout << "ID Cita:          " << idCita << "\n";
        cout << "Nro. Asegurado:   " << numeroAsegurado << "\n";
        cout << "Paciente:         " << nombrePaciente << "\n";
        cout << "Fecha y Hora:     " << fechaHora << "\n";
        cout << "Especialidad:     " << especialidad << "\n";
        cout << "Costo Consulta:   S/ " << fixed << setprecision(2) << costo << "\n";
        cout << "Estado:           " << (confirmada ? "CONFIRMADA" : "PENDIENTE/CANCELADA") << "\n";
        cout << "=========================================================\n";
    }
};

int main() {
    // Creación de objeto vía constructor
    CitaMedica cita2(202, "SIS-12345678", "Ana Gomez", "20/10/2026 11:00 AM", "Pediatria", 50.00);

    cita2.imprimirTicket();
    
    // Cambio de fecha mediante setter y confirmación
    cita2.setFechaHora("21/10/2026 03:00 PM");
    cita2.confirmarCita();
    
    cita2.imprimirTicket();

    return 0;
}