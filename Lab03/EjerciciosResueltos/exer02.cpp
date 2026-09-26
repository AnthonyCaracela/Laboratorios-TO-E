#include <iostream>

using namespace std;

// Clase Base
class Mamifero {
protected:
    int edad;
public:
    Mamifero() : edad(0) { 
        cout << "mamifero constructor...\n"; 
    }
    virtual ~Mamifero() { 
        cout << "mamifero destructor...\n"; 
    }

    void Move() const { 
        cout << "mamifero move one step\n"; 
    }

    // Función Virtual (Polimorfismo)
    virtual void Speak() const { 
        cout << "mamifero speak!\n"; 
    }
};

// Clase Derivada
class Dog : public Mamifero {
public:
    Dog() { 
        cout << "Dog Constructor...\n"; 
    }
    ~Dog() override { 
        cout << "Dog destructor...\n"; 
    }

    void WagTail() const { 
        cout << "Wagging Tail...\n"; 
    }

    void Speak() const override { 
        cout << "Woof!\n"; 
    }

    void Move() const { 
        cout << "Dog moves 5 steps...\n"; 
    }
};

int main() {
    cout << "=== EJERCICIO RESUELTO 2: POLIMORFISMO ===\n\n";

    // Puntero de tipo base apuntando a objeto derivado
    Mamifero* miMascota = new Dog();

    cout << "\n--- Probando llamadas a metodos ---\n";
    miMascota->Move();   // Llama a Mamifero::Move() al no ser virtual
    miMascota->Speak();  // Llama a Dog::Speak() gracias al Polimorfismo

    cout << "\n--- Liberando memoria ---\n";
    delete miMascota; // Activa destructores en orden correcto por ser destructor virtual

    return 0;
}