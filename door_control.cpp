#include "door_control.h"
#include "ui_door_control.h"

Door_control::Door_control(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Door_control)
{
    ui->setupUi(this);
}

Door_control::~Door_control()
{
    delete ui;
}
