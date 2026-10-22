// ejercicio_resuelto_a.cpp
#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <time.h>

void* procesoHilo(void* dato) {
    struct timespec tm = {1, 0};
    int contador = 0;

    while (contador < 5) {
        std::cout << "proceso\n";
        nanosleep(&tm, NULL);
        contador++;
    }
    return NULL;
}

int main() {
    pthread_t proceso1;
    pthread_t proceso2;

    pthread_create(&proceso1, NULL, &procesoHilo, NULL);
    pthread_create(&proceso2, NULL, &procesoHilo, NULL);

    pthread_join(proceso1, NULL);
    pthread_join(proceso2, NULL);

    return 0;
}