#ifndef TASK_H
#define TASK_H

#include <QWidget>
#include <QString>

namespace Ui { class Task; }

class Task : public QWidget
{
    Q_OBJECT
public:
    explicit Task(const QString& name = "Subir - Ascender", QWidget *parent = nullptr);
    ~Task();
    void setName(const QString& name);
signals:
    void removed(Task* task);
private slots:
    void editar();
private:
    Ui::Task *ui;
};

#endif // TASK_H
