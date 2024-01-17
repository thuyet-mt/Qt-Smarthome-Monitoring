#ifndef GARDEN_H
#define GARDEN_H

#include <QDialog>

namespace Ui {
class Garden;
}

class Garden : public QDialog
{
    Q_OBJECT

public:
    explicit Garden(QWidget *parent = nullptr);
    ~Garden();

private:
    Ui::Garden *ui;
};

#endif // GARDEN_H
