#include "Task.h"
#include "ui_Task.h"

Task::Task(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Task)
{
    ui->setupUi(this);
}

Task::~Task()
{
    delete ui;
}
