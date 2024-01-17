#include "bedroom.h"
#include "ui_bedroom.h"

Bedroom::Bedroom(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Bedroom)
{
    ui->setupUi(this);
}

Bedroom::~Bedroom()
{
    delete ui;
}
