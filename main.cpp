#include "mainwindow.h"
#include "loginform.h"
#include "registerform.h"
#include "forgotpassform.h"
#include <QApplication>
#include <QDebug>
#include <QFile>
#include <QString>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    loginForm loginform;
    registerForm registerform;
    forgotpassForm forgotpassform;
    // Kết nối signal loginSuccess từ loginform với slot show của MainWindow
    QObject::connect(&loginform, &loginForm::loginSuccess, &w, &MainWindow::show);
    QObject::connect(&w, &MainWindow::logoutSignal, &loginform, &loginForm::show);
    QObject::connect(&registerform, &registerForm::registerClosed, &loginform, &loginForm::show);
    QObject::connect(&forgotpassform, &forgotpassForm::forgotpassFormClosed, &loginform, &loginForm::show);
    QFile file(":/styleSheet/SpyBot.qss");
    file.open(QFile::ReadOnly);

    QString styleSheet { QLatin1String(file.readAll()) };

    //setup stylesheet
    app.setStyleSheet(styleSheet);

    // Hiển thị cửa sổ đăng nhập
    loginform.show();

    return app.exec();
}
