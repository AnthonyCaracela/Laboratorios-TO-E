#include <iostream>
#include <string>

// 1. Clase Base 1: Cepa Alfa
class CepaAlfa {
protected:
    std::string origenAlfa;
    float contagiosidadAlfa; // Factor multiplicador de contagio

public:
    CepaAlfa(const std::string& origen = "Reino Unido", float contagio = 1.5f)
        : origenAlfa(origen), contagiosidadAlfa(contagio) {
        std::cout << "[Constructor CepaAlfa] Inicializando atributos de variante Alfa...\n";
    }

    virtual ~CepaAlfa() {}

    void mostrarInfoAlfa() const {
        std::cout << "-> [Cepa Alfa] Origen: " << origenAlfa 
                  << " | Factor Contagio: " << contagiosidadAlfa << "x\n";
    }

    void mutacionSpikeN501Y() const {
        std::cout << "-> [Cepa Alfa] Posee la mutacion Spike N501Y (mayor afinidad al receptor ACE2).\n";
    }
};

// 2. Clase Base 2: Cepa Delta
class CepaDelta {
protected:
    std::string origenDelta;
    float evasionInmuneDelta; // Factor de evasion a anticuerpos

public:
    CepaDelta(const std::string& origen = "India", float evasion = 2.3f)
        : origenDelta(origen), evasionInmuneDelta(evasion) {
        std::cout << "[Constructor CepaDelta] Inicializando atributos de variante Delta...\n";
    }

    virtual ~CepaDelta() {}

    void mostrarInfoDelta() const {
        std::cout << "-> [Cepa Delta] Origen: " << origenDelta 
                  << " | Nivel Evasion Inmune: " << evasionInmuneDelta << "x\n";
    }

    void mutacionSpikeL452R() const {
        std::cout << "-> [Cepa Delta] Posee la mutacion Spike L452R (resistencia a anticuerpos).\n";
    }
};

// 3. Clase Derivada con HERENCIA MÚLTIPLE
// Hereda publicamente de CepaAlfa y CepaDelta a la vez
class CepaRecombinante : public CepaAlfa, public CepaDelta {
private:
    std::string codigoCepa;
    std::string fechaDeteccion;

public:
    // El constructor de la clase derivada llama a los constructores de ambas clases base
    CepaRecombinante(const std::string& codigo, const std::string& fecha,
                      const std::string& origAlfa, float contagioAlfa,
                      const std::string& origDelta, float evasionDelta)
        : CepaAlfa(origAlfa, contagioAlfa), 
          CepaDelta(origDelta, evasionDelta), 
          codigoCepa(codigo), fechaDeteccion(fecha) {
        std::cout << "[Constructor CepaRecombinante] Creando cepa hibrida " << codigoCepa << "...\n";
    }

    void generarReporteGenetico() const {
        std::cout << "\n=========================================================\n";
        std::cout << "  REPORTE GENETICO DE CEPA RECOMBINANTE: " << codigoCepa << "\n";
        std::cout << "  Fecha de Deteccion: " << fechaDeteccion << "\n";
        std::cout << "=========================================================\n";

        std::cout << "\n--- Propiedades Heredadas de la Cepa Alfa ---\n";
        mostrarInfoAlfa();          // Metodo heredado de CepaAlfa
        mutacionSpikeN501Y();       // Metodo heredado de CepaAlfa

        std::cout << "\n--- Propiedades Heredadas de la Cepa Delta ---\n";
        mostrarInfoDelta();         // Metodo heredado de CepaDelta
        mutacionSpikeL452R();       // Metodo heredado de CepaDelta

        std::cout << "\n--- Evaluacion Combinada ---\n";
        std::cout << "-> Al heredar de ambas cepas, presenta un impacto virulento estimado de: " 
                  << (contagiosidadAlfa * evasionInmuneDelta) << "x de severidad global.\n";
        std::cout << "---------------------------------------------------------\n";
    }
};

int main() {
    std::cout << "=========================================================\n";
    std::cout << "   EJERCICIO 2: HERENCIA MULTIPLE DE CEPAS CORONAVIRUS   \n";
    std::cout << "=========================================================\n\n";

    // Instanciacion de la Cepa Recombinante que combina caracteristicas de Alfa y Delta
    CepaRecombinante varianteHibrida("DX-2026-REC", "14/09/2026", 
                                     "Londres", 1.7f, 
                                     "Nueva Delhi", 2.5f);

    // Ejecucion del reporte mostrando los metodos heredados de ambas clases
    varianteHibrida.generarReporteGenetico();

    return 0;
}