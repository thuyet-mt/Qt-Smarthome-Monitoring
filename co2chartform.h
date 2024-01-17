#ifndef CO2CHARTFORM_H
#define CO2CHARTFORM_H

#include <QWidget>

namespace Ui {
class co2ChartForm;
}

class co2ChartForm : public QWidget
{
    Q_OBJECT

public:
    explicit co2ChartForm(QWidget *parent = nullptr);
    ~co2ChartForm();

private:
    Ui::co2ChartForm *ui;
};

#endif // CO2CHARTFORM_H
