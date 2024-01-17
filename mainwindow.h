#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore/QDateTime>
#include <QtMqtt/QMqttClient>
#include <QtWidgets/QMessageBox>
#include "logindialog.h"
#include "loginform.h"
#include "gardenform.h"
#include "bedroomform.h"
#include "doorcontrolform.h"
#include "livingroomform.h"
#include "registerform.h"
#include "usermanageform.h"
#include "main.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void logoutSignal(); // Signal mới cho việc đăng xuất
private slots:
    void on_pushButton_bedroom_clicked();

    void on_pushButton_livingroom_clicked();

    void on_pushButton_doorcontrol_clicked();

    void on_pushButton_garden_clicked();

    void on_pushButton_Logout_clicked();

    void showMainWindow(); // Slot to show the main window

    void on_pushButton_userManagement_clicked();

private:
    Ui::MainWindow *ui;
    loginDialog *logindialog;
    loginForm *loginform;
    bedroomForm *bedroom;
    doorcontrolForm *doorcontrol;
    gardenForm *garden;
    livingroomForm *livingroom;
    registerForm *registerform;
    userManageForm *usermanage;
};
#endif // MAINWINDOW_H
