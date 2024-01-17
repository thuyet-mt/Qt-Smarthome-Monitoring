#include "gardenform.h"
#include "ui_gardenform.h"

gardenForm::gardenForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::gardenForm)
{
    ui->setupUi(this);
}

gardenForm::~gardenForm()
{
    delete ui;
}
