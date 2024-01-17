#ifndef GARDENFORM_H
#define GARDENFORM_H

#include <QWidget>

namespace Ui {
class gardenForm;
}

class gardenForm : public QWidget
{
    Q_OBJECT

public:
    explicit gardenForm(QWidget *parent = nullptr);
    ~gardenForm();

private:
    Ui::gardenForm *ui;
};

#endif // GARDENFORM_H
