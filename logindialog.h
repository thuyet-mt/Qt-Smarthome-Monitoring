#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "registerdialog.h"
#include "registerform.h"
namespace Ui {
class loginDialog;
}

class loginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit loginDialog(QWidget *parent = nullptr);
    ~loginDialog();
private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_signup_clicked();

    void on_pushButton_forgotpass_clicked();

private:
    Ui::loginDialog *ui;
    QSqlDatabase mydb;
    registerForm *registerform;

};

#endif // LOGINDIALOG_H
