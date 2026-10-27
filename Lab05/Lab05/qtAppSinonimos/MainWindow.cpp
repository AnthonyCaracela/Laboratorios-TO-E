#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDebug>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), mTasks()
{
    ui->setupUi(this);
    connect(ui->addTaskButton, &QPushButton::clicked, this, &MainWindow::addTask);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::addTask()
{
    qDebug() << "Slot corresponde al clic en el boton ...";
    static const QStringList sinonimos = {
        "Subir - Ascender", "Bajar - Descender", "Grande - Enorme",
        QString::fromUtf8("R\u00e1pido - Veloz"), "Feliz - Alegre"
    };
    static int contador = 0;
    Task* task = new Task(sinonimos.at(contador++ % sinonimos.size()));
    mTasks.append(task);
    ui->tasksLayout->addWidget(task);
    connect(task, &Task::removed, this, &MainWindow::removeTask);
}

void MainWindow::removeTask(Task* task)
{
    qDebug() << "objeto eliminado...";
    mTasks.removeOne(task);
    ui->tasksLayout->removeWidget(task);
    task->deleteLater();
}
