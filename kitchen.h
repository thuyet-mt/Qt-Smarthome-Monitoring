#ifndef KITCHEN_H
#define KITCHEN_H

#include <QDialog>

namespace Ui {
class Kitchen;
}

class Kitchen : public QDialog
{
    Q_OBJECT

public:
    explicit Kitchen(QWidget *parent = nullptr);
    ~Kitchen();

private:
    Ui::Kitchen *ui;
};

#endif // KITCHEN_H
