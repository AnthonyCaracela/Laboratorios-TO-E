#include <QCoreApplication>
#include <QDebug>
#include "Comunicacion.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject *person = new QObject;
    Comunicacion *pepe = new Comunicacion(person);
    Comunicacion *jose = new Comunicacion(person);

    pepe->setNombre("Pepe");
    jose->setNombre("Jose");

    // Conexión con sintaxis moderna (evita errores en Qt 6)
    QObject::connect(pepe, &Comunicacion::enviarmensaje, jose, &Comunicacion::escuchar);
    QObject::connect(jose, &Comunicacion::enviarmensaje, pepe, &Comunicacion::escuchar);

    pepe->conversar("buenos dias");
    jose->conversar("como vas?");

    delete person; // Al borrar al padre, se borran pepe y jose

    return a.exec();
}