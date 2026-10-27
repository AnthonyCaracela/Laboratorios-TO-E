#include "Task.h"
#include "ui_Task.h"

Task::Task(const QString& name, QWidget *parent)
    : QWidget(parent), ui(new Ui::Task)
{
    ui->setupUi(this);
    setName(name);
    connect(ui->removeButton, &QPushButton::clicked, [this]{ emit removed(this); });
}

Task::~Task() { delete ui; }

void Task::setName(const QString& name) { ui->Mitext->setText(name); }
