#ifndef PASSFORM_H
#define PASSFORM_H

#include <QWidget>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QMqttClient>
#include "main.h"
#include <QSqlTableModel>

namespace Ui {
class passForm;
}

class passForm : public QWidget
{
    Q_OBJECT

public:
    explicit passForm(QWidget *parent = nullptr);
    ~passForm();

private:
    Ui::passForm *ui;
};

#endif // PASSFORM_H
