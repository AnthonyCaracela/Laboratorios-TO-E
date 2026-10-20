#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Diccionario
    const QMap<QString, QPair<QString, QString>> paises = {
        {"Perú",      {"Español",  "Lima"}},
        {"Argentina", {"Español",  "Buenos Aires"}},
        {"Francia",   {"Francés",  "París"}},
        {"Japón",     {"Japonés",  "Tokio"}},
        {"Italia",    {"Italiano", "Roma"}}
    };

    // Llenar la lista usando las llaves del mapa
    ui->listaPaises->addItems(paises.keys());
    ui->lblIdioma->setText("Selecciona un país");
    ui->lblCapital->clear();

    // Señal: itemClicked. Slot: Lambda compacta
    connect(ui->listaPaises, &QListWidget::itemClicked, this, [=](QListWidgetItem *item) {
        auto info = paises.value(item->text());
        ui->lblIdioma->setText("Idioma: " + info.first);
        ui->lblCapital->setText("Capital: " + info.second);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}