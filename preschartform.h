#ifndef PRESCHARTFORM_H
#define PRESCHARTFORM_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "main.h"

#include<QtCharts>
#include<QChartView>
#include<QLineSeries>

#include <QtSql>
#include <QHBoxLayout> // Include this for layout management

QT_BEGIN_NAMESPACE
namespace Ui {
class presChartForm;
}
QT_END_NAMESPACE

class presChartForm : public QWidget
{
    Q_OBJECT

public:
    explicit presChartForm(QWidget *parent = nullptr);
    ~presChartForm();

private:
    Ui::presChartForm *ui;
    QSqlDatabase m_db;
};

#endif // PRESCHARTFORM_H
