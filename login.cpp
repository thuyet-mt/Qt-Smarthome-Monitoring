#include "login.h"
#include "ui_login.h"
#include <QPixmap>
#include <QMessageBox>
login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);

    QPixmap pix_smarthome(":/images/logosmarthome.jpeg");
    int w_smarthome = ui->label_icon_smarthome->width();
    int h_smarthome = ui->label_icon_smarthome->height();
    ui->label_icon_smarthome->setPixmap(pix_smarthome.scaled(w_smarthome,h_smarthome,Qt::KeepAspectRatio));

    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("/home/pi/Desktop/sqlite/user.db");
    mydb.open();
    if (!mydb.isOpen()) {
        qDebug() << "Can't open database. Error:" << mydb.lastError().text();
        //ui->label->setText("Can't open database. Error: " + mydb.lastError().text());
    }
    else{
        //ui->label->setText("Open database");

    }
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    QString username, password;
    username = ui -> lineEdit_username->text();
    password = ui -> lineEdit_password -> text();
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
    // query.prepare("SELECT * FROM listuser WHERE username = :username AND password = :password");
    // query.bindValue(":username", username);
    // query.bindValue(":password", password);

    if(query.exec("select * from listuser where name='"+username+"'and password='"+password+"'")){
        int count=0;
        while(query.next()){
            count++;
        }
        if(count==1){
            ui->label_status_login_display->setText("username and password is correct");
            qDebug() << "username and password is correct";
            this->hide();
            Smart_Home_Dashboard smartHomeDashboard;
            smartHomeDashboard.setModal(true);
            smartHomeDashboard.exec();
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

