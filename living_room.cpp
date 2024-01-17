#include "living_room.h"
#include "ui_living_room.h"

Living_Room::Living_Room(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Living_Room)
{
    ui->setupUi(this);
}

Living_Room::~Living_Room()
{
    delete ui;
}
