#include "co2chartform.h"
#include "ui_co2chartform.h"

co2ChartForm::co2ChartForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::co2ChartForm)
{
    ui->setupUi(this);
}

co2ChartForm::~co2ChartForm()
{
    delete ui;
}
