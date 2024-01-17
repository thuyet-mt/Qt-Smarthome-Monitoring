#include "garden.h"
#include "ui_garden.h"

Garden::Garden(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Garden)
{
    ui->setupUi(this);
}

Garden::~Garden()
{
    delete ui;
}
