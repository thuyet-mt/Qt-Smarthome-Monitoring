#include "humidchartform.h"
#include "ui_humidchartform.h"

humidChartForm::humidChartForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::humidChartForm)
{
    ui->setupUi(this);
}

humidChartForm::~humidChartForm()
{
    delete ui;
}
