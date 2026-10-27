#include "Task.h"
#include "ui_Task.h"
#include <QInputDialog>
#include <QLineEdit>

Task::Task(const QString& name, QWidget *parent)
    : QWidget(parent), ui(new Ui::Task)
{
    ui->setupUi(this);
    ui->checkbox->setChecked(false);
    setName(name);
    connect(ui->editButton,   &QPushButton::clicked, this, &Task::editar);
    connect(ui->removeButton, &QPushButton::clicked, [this]{ emit removed(this); });
}

Task::~Task() { delete ui; }

void Task::setName(const QString& name) { ui->Mitext->setText(name); }

void Task::editar()
{
    bool ok = false;
    QString texto = QInputDialog::getText(this, tr("Editar sin\u00f3nimos"),
                        tr("Sin\u00f3nimos (palabra1 - palabra2):"),
                        QLineEdit::Normal, ui->Mitext->text(), &ok);
    if (ok && !texto.trimmed().isEmpty())
        setName(texto.trimmed());
}
