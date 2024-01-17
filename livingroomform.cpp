#include "livingroomform.h"
#include "ui_livingroomform.h"

livingroomForm::livingroomForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::livingroomForm)
{
    ui->setupUi(this);
}

livingroomForm::~livingroomForm()
{
    delete ui;
}
