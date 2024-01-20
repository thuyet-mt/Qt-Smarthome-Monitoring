#ifndef HUMIDCHARTFORM_H
#define HUMIDCHARTFORM_H

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
class humidChartForm;
}

class humidChartForm : public QWidget
{
    Q_OBJECT

public:
    explicit humidChartForm(QWidget *parent = nullptr);
    ~humidChartForm();

private:
    Ui::humidChartForm *ui;
    QSqlDatabase m_db;
};

#endif // HUMIDCHARTFORM_H
