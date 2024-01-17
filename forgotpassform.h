#ifndef FORGOTPASSFORM_H
#define FORGOTPASSFORM_H

#include <QWidget>
#include <QWidget>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QMessageBox>
#include "main.h"
namespace Ui {
class forgotpassForm;
}

class forgotpassForm : public QWidget
{
    Q_OBJECT

public:
    explicit forgotpassForm(QWidget *parent = nullptr);
    ~forgotpassForm();
protected:
    void closeEvent(QCloseEvent *event) override; // Khai báo phương thức closeEvent
signals:
    void forgotpassFormClosed(); // Signal mới cho việc đóng cửa sổ đăng ký
private slots:
    void on_pushButton_takebackpass_clicked();

private:
    Ui::forgotpassForm *ui;
    QSqlDatabase mydb_forgotpass;
};

#endif // FORGOTPASSFORM_H
