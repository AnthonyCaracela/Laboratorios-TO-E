#include <iostream>
#include <limits>

// Estructura que representa cada nodo de la lista
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Clase que administra la lista doblemente enlazada
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    size_t length;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), length(0) {}

    // Destructor para liberar la memoria
    ~DoublyLinkedList() {
        clear();
    }

    // Insertar al final (push_back)
    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }

    // Insertar al inicio (push_front)
    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        length++;
    }

    // Eliminar un elemento por valor
    bool remove(int val) {
        Node* current = head;
        while (current != nullptr && current->data != val) {
            current = current->next;
        }

        if (current == nullptr) return false; // Elemento no encontrado

        if (current == head) head = current->next;
        if (current == tail) tail = current->prev;

        if (current->prev != nullptr) current->prev->next = current->next;
        if (current->next != nullptr) current->next->prev = current->prev;

        delete current;
        length--;
        return true;
    }

    // Buscar un elemento en la lista
    bool search(int val) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == val) return true;
            current = current->next;
        }
        return false;
    }

    // Vaciar completamente la lista
    void clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = tail = nullptr;
        length = 0;
    }

    // Mostrar de inicio a fin
    void displayForward() const {
        if (head == nullptr) {
            std::cout << "\n [!] La lista esta vacia.\n";
            return;
        }
        std::cout << "\n Lista (Head -> Tail) [Total: " << length << "]:\n nullptr <-> ";
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << "[" << temp->data << "] <-> ";
            temp = temp->next;
        }
        std::cout << "nullptr\n";
    }

    // Mostrar de fin a inicio
    void displayBackward() const {
        if (tail == nullptr) {
            std::cout << "\n [!] La lista esta vacia.\n";
            return;
        }
        std::cout << "\n Lista (Tail -> Head) [Total: " << length << "]:\n nullptr <-> ";
        Node* temp = tail;
        while (temp != nullptr) {
            std::cout << "[" << temp->data << "] <-> ";
            temp = temp->prev;
        }
        std::cout << "nullptr\n";
    }

    size_t size() const {
        return length;
    }
};

// Función auxiliar para leer enteros sin que la consola colapse por texto inválido
int leerEntero(const std::string& mensaje) {
    int valor;
    while (true) {
        std::cout << mensaje;
        if (std::cin >> valor) {
            return valor;
        }
        std::cout << " [!] Entrada invalida. Por favor, ingrese un numero entero.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main() {
    DoublyLinkedList lista;
    int opcion = -1;

    do {
        std::cout << "\n========================================\n";
        std::cout << "   LISTA DOBLEMENTE ENLAZADA - MENU     \n";
        std::cout << "========================================\n";
        std::cout << " 1. Insertar al inicio (push_front)\n";
        std::cout << " 2. Insertar al final (push_back)\n";
        std::cout << " 3. Eliminar un elemento por valor\n";
        std::cout << " 4. Buscar un elemento\n";
        std::cout << " 5. Mostrar lista (Head -> Tail)\n";
        std::cout << " 6. Mostrar lista (Tail -> Head)\n";
        std::cout << " 7. Vaciar lista\n";
        std::cout << " 0. Salir\n";
        std::cout << "----------------------------------------\n";

        opcion = leerEntero(" Seleccione una opcion: ");

        switch (opcion) {
            case 1: {
                int val = leerEntero(" Ingrese el valor a insertar al inicio: ");
                lista.push_front(val);
                std::cout << " [+] Elemento " << val << " insertado al inicio.\n";
                break;
            }
            case 2: {
                int val = leerEntero(" Ingrese el valor a insertar al final: ");
                lista.push_back(val);
                std::cout << " [+] Elemento " << val << " insertado al final.\n";
                break;
            }
            case 3: {
                int val = leerEntero(" Ingrese el valor a eliminar: ");
                if (lista.remove(val)) {
                    std::cout << " [-] Elemento " << val << " eliminado correctamente.\n";
                } else {
                    std::cout << " [!] El elemento " << val << " no se encuentra en la lista.\n";
                }
                break;
            }
            case 4: {
                int val = leerEntero(" Ingrese el valor a buscar: ");
                if (lista.search(val)) {
                    std::cout << " [V] El elemento " << val << " SI existe en la lista.\n";
                } else {
                    std::cout << " [X] El elemento " << val << " NO existe en la lista.\n";
                }
                break;
            }
            case 5:
                lista.displayForward();
                break;
            case 6:
                lista.displayBackward();
                break;
            case 7:
                lista.clear();
                std::cout << " [!] La lista ha sido vaciada completamente.\n";
                break;
            case 0:
                std::cout << "\n ¡Saliendo del programa!\n";
                break;
            default:
                std::cout << " [!] Opcion invalida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 0);

    return 0;
}