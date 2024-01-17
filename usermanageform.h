#ifndef USERMANAGEFORM_H
#define USERMANAGEFORM_H

#include <QWidget>

namespace Ui {
class userManageForm;
}

class userManageForm : public QWidget
{
    Q_OBJECT

public:
    explicit userManageForm(QWidget *parent = nullptr);
    ~userManageForm();

private slots:
    void on_pushButton_addUser_clicked();

    void on_pushButton_changeInfo_clicked();

    void on_pushButton_deleteUser_clicked();

private:
    Ui::userManageForm *ui;
};

#endif // USERMANAGEFORM_H
