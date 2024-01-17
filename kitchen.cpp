#include "kitchen.h"
#include "ui_kitchen.h"

Kitchen::Kitchen(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Kitchen)
{
    ui->setupUi(this);
}

Kitchen::~Kitchen()
{
    delete ui;
}
