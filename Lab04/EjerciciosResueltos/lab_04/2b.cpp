#include <QCoreApplication>
#include <QDebug>
#include <QObject>
#include <QString>

class adulto : public QObject
{
private:
    QString nombre;

public:
    // Nota: En tu imagen dice "nomb" en la asignación, pero el parámetro se llama "base".
    // Lo he corregido a "base" para que compile.
    adulto(QObject *base = 0): QObject(base) {
    }

    void setNombre(const QString &nomb){
        nombre = nomb;
    }

    QString getNombre() const{
        return nombre;
    }

    ~adulto(){
        qDebug() << "...objeto destruido...";
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Implementación en el main()
    adulto *papa = new adulto;
    adulto *hijo1 = new adulto(papa);
    adulto *hijo2 = new adulto(papa);

    hijo1->setNombre("manuel");
    hijo2->setNombre("Jose");

    // La sentencia “delete” invoca al QObject para destruir todos los objetos hijos y clase base.
    delete papa;

    return a.exec();
}