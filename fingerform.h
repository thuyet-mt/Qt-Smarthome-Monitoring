#ifndef FINGERFORM_H
#define FINGERFORM_H

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
#include <QTableView>
namespace Ui {
class fingerForm;
}

class fingerForm : public QWidget
{
    Q_OBJECT

public:
    explicit fingerForm(QWidget *parent = nullptr);
    ~fingerForm();

private:
    Ui::fingerForm *ui;
    QSqlDatabase mydb_finger;
    QMqttClient *m_client_finger;
};

#endif // FINGERFORM_H
