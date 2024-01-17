#ifndef HUMIDCHARTFORM_H
#define HUMIDCHARTFORM_H

#include <QWidget>

namespace Ui {
class humidChartForm;
}

class humidChartForm : public QWidget
{
    Q_OBJECT

public:
    explicit humidChartForm(QWidget *parent = nullptr);
    ~humidChartForm();

private:
    Ui::humidChartForm *ui;
};

#endif // HUMIDCHARTFORM_H
