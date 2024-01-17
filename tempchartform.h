#ifndef TEMPCHARTFORM_H
#define TEMPCHARTFORM_H

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
class tempChartForm;
}
QT_END_NAMESPACE

class tempChartForm : public QWidget
{
    Q_OBJECT

public:
    explicit tempChartForm(QWidget *parent = nullptr);
    ~tempChartForm();

private:
    Ui::tempChartForm *ui;
    QSqlDatabase m_db;
};

#endif // TEMPCHARTFORM_H
