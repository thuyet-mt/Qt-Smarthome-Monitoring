#ifndef CO2CHARTFORM_H
#define CO2CHARTFORM_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "main.h"

#include<QtCharts>
#include<QChartView>
#include<QLineSeries>

#include <QtSql>
#include <QHBoxLayout> // Include this for layout management
namespace Ui {
class co2ChartForm;
}

class co2ChartForm : public QWidget
{
    Q_OBJECT

public:
    explicit co2ChartForm(QWidget *parent = nullptr);
    ~co2ChartForm();

private:
    Ui::co2ChartForm *ui;
    QSqlDatabase m_db;
};

#endif // CO2CHARTFORM_H
