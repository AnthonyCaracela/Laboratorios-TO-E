#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDebug>

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
    Task* task = new Task();
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
