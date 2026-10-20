#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Conexión del botón al slot
    connect(ui->addTaskButton, &QPushButton::clicked, this, &MainWindow::addTask);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTask()
{
    // Imprime en consola como pide la guía
    qDebug() << "Slot corresponde al clic en el boton ...";

    // Actualiza el texto en la pantalla (como en la imagen del paso 4)
    ui->statusLabel->setText("Status: 0 todo / 0 hecho");
}