#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "registerdialog.h"
#include "registerform.h"
#include "forgotpassform.h"
#include "main.h"
namespace Ui {
class loginForm;
}

class loginForm : public QWidget
{
    Q_OBJECT

public:
    explicit loginForm(QWidget *parent = nullptr);
    ~loginForm();
signals:
    void loginSuccess(); // Signal to indicate successful login

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_signup_clicked();

    void on_pushButton_forgotpass_clicked();

private:
    Ui::loginForm *ui;
    QSqlDatabase mydb;
    registerForm *registerform;
    forgotpassForm *forgotpassform;
};

#endif // LOGINFORM_H
