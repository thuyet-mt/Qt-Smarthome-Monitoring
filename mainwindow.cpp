#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loginform = new loginForm();
    bedroom = new bedroomForm();
    doorcontrol = new doorcontrolForm();
    garden = new gardenForm();
    livingroom = new livingroomForm();
    usermanage = new userManageForm();

    QPixmap pix_icon_bedroom(":/images/bedroom.png");
    int w_icon_bedroom = ui->label_icon_bedroom->width();
    int h_icon_bedroom = ui->label_icon_bedroom->height();
    ui->label_icon_bedroom->setPixmap(pix_icon_bedroom.scaled(w_icon_bedroom,h_icon_bedroom,Qt::KeepAspectRatio));

    QPixmap pix_icon_livingroom(":/images/livingroom.png");
    int w_icon_livingroom = ui->label_icon_livingroom->width();
    int h_icon_livingroom = ui->label_icon_livingroom->height();
    ui->label_icon_livingroom->setPixmap(pix_icon_livingroom.scaled(w_icon_livingroom,h_icon_livingroom,Qt::KeepAspectRatio));

    QPixmap pix_icon_doorcontrol(":/images/door.png");
    int w_icon_doorcontrol = ui ->label_icon_doorcontrol->width();
    int h_icon_doorcontrol = ui -> label_icon_doorcontrol->height();
    ui -> label_icon_doorcontrol ->setPixmap(pix_icon_doorcontrol.scaled(w_icon_doorcontrol, h_icon_doorcontrol, Qt::KeepAspectRatio));

    QPixmap pix_icon_garden(":/images/garden.png");
    int w_icon_garden = ui ->label_icon_garden->width();
    int h_icon_garden = ui -> label_icon_garden->height();
    ui -> label_icon_garden ->setPixmap(pix_icon_garden.scaled(w_icon_garden, h_icon_garden, Qt::KeepAspectRatio));



}

MainWindow::~MainWindow()
{
    delete bedroom;
    delete doorcontrol;
    delete garden;
    delete livingroom;
    delete usermanage;
    delete ui;
}

void MainWindow::on_pushButton_bedroom_clicked()
{
    bedroom->show();

}


void MainWindow::on_pushButton_livingroom_clicked()
{
    livingroom->show();
}


void MainWindow::on_pushButton_doorcontrol_clicked()
{
    doorcontrol->show();
}


void MainWindow::on_pushButton_garden_clicked()
{
    garden->show();

}


void MainWindow::on_pushButton_Logout_clicked()
{
    this->hide();
    emit logoutSignal(); // Phát ra signal đăng xuất

}

void MainWindow::showMainWindow()
{
    this->show(); // Show the main window
}

void MainWindow::on_pushButton_userManagement_clicked()
{
    usermanage->show();
}

