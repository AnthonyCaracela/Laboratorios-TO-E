#include <QCoreApplication>
#include <QDebug>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 1. Función lambda: sumar 3 a un número y mostrarlo
    int (*s)(int) = [](int valor){ return valor+3;};
    int u = 5;
    qDebug() << "Resultado de la suma:" << s(u);

    // 2. Función lambda: recorrer elementos de un vector
    vector<int> v {5,2,3,7,1,0,14,20};
    qDebug() << "Elementos del vector:";
    for_each(v.begin(), v.end(), [](int valor){
        qDebug() << valor;
    });

    return a.exec();
}