#include "usermanageform.h"
#include "ui_usermanageform.h"

userManageForm::userManageForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::userManageForm)
{
    ui->setupUi(this);
}

userManageForm::~userManageForm()
{
    delete ui;
}

void userManageForm::on_pushButton_addUser_clicked()
{

}


void userManageForm::on_pushButton_changeInfo_clicked()
{

}


void userManageForm::on_pushButton_deleteUser_clicked()
{

}

