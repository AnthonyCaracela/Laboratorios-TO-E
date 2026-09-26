#include <iostream>
#include <string>
#include <vector>

// 1. Clase Base Abstracta Persona
class Persona {
protected:
    std::string nombre;
    int edad;

public:
    Persona(const std::string& nombre, int edad) 
        : nombre(nombre), edad(edad) {}

    // Destructor virtual para asegurar liberacion correcta de memoria
    virtual ~Persona() {}

    // Metodo virtual puro (Polimorfismo)
    virtual void realizarLabor() const = 0;

    virtual void mostrarInformacion() const {
        std::cout << "Nombre: " << nombre << " | Edad: " << edad << " anos\n";
    }
};

// 2. Subclase Arquitecto
class Arquitecto : public Persona {
private:
    std::string proyectoActual;

public:
    Arquitecto(const std::string& nombre, int edad, const std::string& proyecto)
        : Persona(nombre, edad), proyectoActual(proyecto) {}

    void realizarLabor() const override {
        std::cout << "[Arquitecto] " << nombre 
                  << " esta disenando los planos para: " << proyectoActual << ".\n";
    }
};

// 3. Subclase Doctor
class Doctor : public Persona {
private:
    std::string especialidad;

public:
    Doctor(const std::string& nombre, int edad, const std::string& especialidad)
        : Persona(nombre, edad), especialidad(especialidad) {}

    void realizarLabor() const override {
        std::cout << "[Doctor] " << nombre 
                  << " esta diagnosticando pacientes en el area de " 
                  << especialidad << ".\n";
    }
};

// 4. Subclase Enfermera
class Enfermera : public Persona {
private:
    std::string turno;

public:
    Enfermera(const std::string& nombre, int edad, const std::string& turno)
        : Persona(nombre, edad), turno(turno) {}

    void realizarLabor() const override {
        std::cout << "[Enfermera] " << nombre 
                  << " esta asistiendo a los pacientes en el turno de la " 
                  << turno << ".\n";
    }
};

// 5. Subclase Bombero
class Bombero : public Persona {
private:
    std::string estacion;

public:
    Bombero(const std::string& nombre, int edad, const std::string& estacion)
        : Persona(nombre, edad), estacion(estacion) {}

    void realizarLabor() const override {
        std::cout << "[Bombero] " << nombre 
                  << " esta respondiendo a emergencias en la " 
                  << estacion << ".\n";
    }
};

int main() {
    std::cout << "=========================================================\n";
    std::cout << "   EJERCICIO 1: HERENCIA Y POLIMORFISMO DE OFICIOS      \n";
    std::cout << "=========================================================\n\n";

    // Creamos un vector de punteros a la clase base Persona (Demostracion de Polimorfismo)
    std::vector<Persona*> equipoTrabajo;

    equipoTrabajo.push_back(new Arquitecto("Lucia Gomez", 40, "Centro Comercial Arequipa"));
    equipoTrabajo.push_back(new Doctor("Carlos Mendoza", 48, "Cardiologia"));
    equipoTrabajo.push_back(new Enfermera("Maria Torres", 32, "Noche"));
    equipoTrabajo.push_back(new Bombero("Juan Perez", 29, "Estacion Nro 19"));

    // Recorremos el vector llamando a las funciones virtuales de cada objeto
    for (const auto& persona : equipoTrabajo) {
        persona->mostrarInformacion();
        persona->realizarLabor();
        std::cout << "---------------------------------------------------------\n";
    }

    // Liberamos la memoria asignada dinamicamente
    for (auto& persona : equipoTrabajo) {
        delete persona;
    }
    equipoTrabajo.clear();

    return 0;
}