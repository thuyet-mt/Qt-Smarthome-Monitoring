#ifndef DOOR_CONTROL_H
#define DOOR_CONTROL_H

#include <QDialog>

namespace Ui {
class Door_control;
}

class Door_control : public QDialog
{
    Q_OBJECT

public:
    explicit Door_control(QWidget *parent = nullptr);
    ~Door_control();

private:
    Ui::Door_control *ui;
};

#endif // DOOR_CONTROL_H
