#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Introducción a datos y funciones cadena Qt
    int x = 47;
    double y = 3.2478;
    char t = 'A';

    QString qtcadena = QString("%1 %2 %3").arg(t).arg(y).arg(x);
    string cadena = qtcadena.toStdString();

    qDebug() << "Cadena std::string:" << cadena.c_str();
    qDebug() << "Cadena QString:" << qtcadena;

    qtcadena = "arequipa ciudad blanca 2021";
    qDebug() << "Contiene 'ciudad'?:" << qtcadena.contains("ciudad");
    qDebug() << "Posicion de '2021':" << qtcadena.indexOf("2021");

    return a.exec();
}