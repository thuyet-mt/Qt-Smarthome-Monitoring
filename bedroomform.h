#ifndef BEDROOMFORM_H
#define BEDROOMFORM_H

#include <QWidget>
#include <QCloseEvent>
#include <QMqttClient>
#include "tempchartform.h"
#include "preschartform.h"
#include "co2chartform.h"
#include "humidchartform.h"
namespace Ui {
class bedroomForm;
}

class bedroomForm : public QWidget
{
    Q_OBJECT

public:

    explicit bedroomForm(QWidget *parent = nullptr);
    void publishToMqtt(const QString &topic, const QString &message);
    ~bedroomForm();
public slots:

private slots:

    void on_pushButton_lamp_clicked();

    void on_pushButton_fan_clicked();

    void on_pushButton_airConditional_clicked();

    void on_spinBox_airConditional_valueChanged(int arg1);


    void on_pushButton_temp_clicked();

    void on_pushButton_humid_clicked();

    void on_pushButton_pres_clicked();

    void on_pushButton_co2_clicked();

private:
    Ui::bedroomForm *ui;
    QMqttClient *m_client;
    int lampState = 0; // Initial state is Off
    int fanState = 0; // Initial state is Off
    int airConditionalState = 0; // Initial state is Off
    tempChartForm *tempchartform;
    presChartForm *preschartform;
    humidChartForm *humidchartform;
    co2ChartForm *co2chartform;
};

#endif // BEDROOMFORM_H
