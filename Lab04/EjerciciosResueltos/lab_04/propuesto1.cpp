#include <QCoreApplication>
#include <QDebug>
#include <vector>
#include <algorithm>
#include <random>

bool esPrimo(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) if (n % i == 0) return false;
    return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::vector<int> v(50);
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> dis(0, 1500);

    for (int& n : v) n = dis(gen);

    for (int n : v) qDebug() << n << (n < 1000 && esPrimo(n) ? "(Primo)" : "");

    int primos = std::count_if(v.begin(), v.end(), [](int n) { return n < 1000 && esPrimo(n); });
    qDebug() << "Total primos < 1000:" << primos;

    return a.exec();
}