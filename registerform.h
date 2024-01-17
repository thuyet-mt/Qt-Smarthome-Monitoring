#ifndef REGISTERFORM_H
#define REGISTERFORM_H

#include <QWidget>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QMessageBox>
#include "main.h"
namespace Ui {
class registerForm;
}

class registerForm : public QWidget
{
    Q_OBJECT

public:
    explicit registerForm(QWidget *parent = nullptr);
    ~registerForm();
protected:
    void closeEvent(QCloseEvent *event) override; // Khai báo phương thức closeEvent
signals:
    void registerClosed(); // Signal mới cho việc đóng cửa sổ đăng ký

private slots:



    void on_pushButton_register_clicked();

private:
    Ui::registerForm *ui;
};

#endif // REGISTERFORM_H
