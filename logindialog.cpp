#include "logindialog.h"
#include "ui_logindialog.h"

loginDialog::loginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::loginDialog)

{
    ui->setupUi(this);
    registerform = new registerForm();

    QPixmap pix_icon_logo_smarthome(":/images/logosmarthome.png");
    int w_logo_smarthome = ui->label_logo_smarthome->width();
    int h_logo_smarthome = ui->label_logo_smarthome->height();
    ui->label_logo_smarthome->setPixmap(pix_icon_logo_smarthome.scaled(w_logo_smarthome,h_logo_smarthome,Qt::KeepAspectRatio));
}

loginDialog::~loginDialog()
{
    delete ui;
    delete registerform;
}

void loginDialog::on_pushButton_login_clicked()
{
    QString username_input, password_input;
    username_input = ui -> lineEdit_input_username->text();
    password_input = ui -> lineEdit_input_password -> text();

    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("\F:/Smart-home-monitor-with-Node-RED-Qt-Framework-and-ESP32/user.db");
    //mydb.setDatabaseName("/home/pi/Desktop/sqlite/user.db");
    mydb.open();
    if (!mydb.isOpen()) {
        qDebug() << "Can't open database. Error:" << mydb.lastError().text();
        //ui->label->setText("Can't open database. Error: " + mydb.lastError().text());
        return;
    }
    else{
        qDebug() << "Open database done";
    }
    QSqlQuery query;

    if(query.exec("select * from listuser where name='"+username_input+"'and password='"+password_input+"'")){
        int count=0;
        while(query.next()){
            count++;
        }
        if(count==1){
            ui->label_status_login_display->setText("username and password is correct");
            qDebug() << "username and password is correct";
            accept();
            mydb.close();
            mydb.removeDatabase(QSqlDatabase::defaultConnection);
        }
        else if (count >1){
            ui->label_status_login_display->setText("Duplicate username and password");
            qDebug() << "Duplicate username and password";
        }
        else {
            ui->label_status_login_display->setText("Wrong username and password");
            qDebug() << "Wrong username and password";
        }
    }
    if (!query.exec()) {
        qDebug() << "Error executing query: " << query.lastError().text();
        ui->label_status_login_display->setText("Error executing query");
        return;
    }
}





void loginDialog::on_pushButton_signup_clicked()
{
    registerform->show();

}


void loginDialog::on_pushButton_forgotpass_clicked()
{

}

