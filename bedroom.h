#ifndef BEDROOM_H
#define BEDROOM_H

#include <QDialog>

namespace Ui {
class Bedroom;
}

class Bedroom : public QDialog
{
    Q_OBJECT

public:
    explicit Bedroom(QWidget *parent = nullptr);
    ~Bedroom();

private:
    Ui::Bedroom *ui;
};

#endif // BEDROOM_H
