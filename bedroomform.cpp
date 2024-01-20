#include "bedroomform.h"
#include "ui_bedroomform.h"
#include <QtCore/QDateTime>
#include <QtMqtt/QMqttClient>
#include <QtWidgets/QMessageBox>
bedroomForm::bedroomForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::bedroomForm)
    , m_client(new QMqttClient(this))
{
    ui->setupUi(this);
    tempchartform = new tempChartForm();
    preschartform = new presChartForm();
    humidchartform = new humidChartForm();
    co2chartform = new co2ChartForm();
    m_client->setHostname("100.114.147.149");
    m_client->setPort(1883);
    m_client->connectToHost();
    connect(m_client, &QMqttClient::stateChanged, this, [this](QMqttClient::ClientState state) {
        if (state == QMqttClient::Connected) {
            qDebug() << "Connected to broker";
            // Subscribe sau khi kết nối thành công
            // QString topic_temp = "esp/bme280/temperature";
            // QString topic_humid = "esp/bme280/humidity";
            // QString topic_pres = "esp/bme280/pressure";
            // QString topic_co2 = "esp/mq2/gas";
            // QMqttTopicFilter topicFilter0(topic_temp);
            // QMqttTopicFilter topicFilter1(topic_humid);
            // QMqttTopicFilter topicFilter2(topic_pres);
            // QMqttTopicFilter topicFilter3(topic_co2);
            // m_client->subscribe(topicFilter0);
            // m_client->subscribe(topicFilter1);
            // m_client->subscribe(topicFilter2);
            // m_client->subscribe(topicFilter3);
            QString topic_esp = "esp/#";
            QMqttTopicFilter topicFilter(topic_esp);
            m_client->subscribe(topicFilter);
        } else {
            qDebug() << "Connection to broker failed";
        }
    });

        // Xử lý khi nhận được tin nhắn từ MQTT broker
        connect(m_client, &QMqttClient::messageReceived, this, [this](const QByteArray &message, const QMqttTopicName &topic) {
            const QString content =
                    //QDateTime::currentDateTime().toString()
                        //+ QLatin1String(" Received Topic: ")
                        //+ topic.name()

                        //+ QLatin1String(" Message: ")
                        message;
                        //+ QLatin1Char('\n');
            // Kiểm tra ui trước khi sử dụng
            if (ui) {
                if(topic.name()== "esp/bme280/temperature"){
                    ui->label_displaytemp->setText(content+" °C");
                }
                else if(topic.name()== "esp/bme280/humidity"){
                    ui->label_displayhumid->setText(content+" %");
                }
                else if(topic.name()== "esp/bme280/pressure"){
                    ui->label_displaypres->setText(content+" hPa");
                }
                else if(topic.name()== "esp/mq2/gas"){
                    ui->label_displaygas->setText(content+" ppm");
                }
            }
        });


    // Kết nối đến broker
    //m_client->connectToHost();
}


bedroomForm::~bedroomForm()
{
    delete ui;
}



void bedroomForm::on_pushButton_lamp_clicked()
{
    // Toggle the state of the lamp
    lampState = (lampState == 0) ? 1 : 0;

    // Update the button text
    ui->pushButton_lamp->setText((lampState == 1) ? "On" : "Off");

    // Create the QMqttClient instance only if it's not already created
    if (!m_client) {
        m_client = new QMqttClient(this);
        m_client->setHostname("100.114.147.149");
        m_client->setPort(1883);
        m_client->connectToHost();

        // Connect other necessary signals and slots for MQTT communication
    }

    // Publish the new lamp state to the MQTT topic
    publishToMqtt("esp/lamp", (lampState)?"true":"false");

}
void bedroomForm::publishToMqtt(const QString &topic, const QString &message){
    if (m_client && m_client->state() == QMqttClient::Connected) {
        m_client->publish(topic, message.toUtf8(), 0, false);
    } else {
        QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Not connected to MQTT broker"));
    }
}
void bedroomForm::on_pushButton_fan_clicked()
{
    // Toggle the state of the fan
    fanState = (fanState == 0) ? 1 : 0;

    // Update the button text
    ui->pushButton_fan->setText((fanState == 1) ? "On" : "Off");

    // Create the QMqttClient instance only if it's not already created
    if (!m_client) {
        m_client = new QMqttClient(this);
        m_client->setHostname("100.114.147.149");
        m_client->setPort(1883);
        m_client->connectToHost();

        // Connect other necessary signals and slots for MQTT communication
    }

    // Publish the new fan state to the MQTT topic
    publishToMqtt("esp/bedroom/fan", QString::number(fanState));
}
void bedroomForm::on_pushButton_airConditional_clicked()
{
    // Toggle the state of the airConditional
    airConditionalState = (airConditionalState == 0) ? 1 : 0;

    // Update the button text
    ui->pushButton_airConditional->setText((airConditionalState == 1) ? "On" : "Off");

    // Create the QMqttClient instance only if it's not already created
    if (!m_client) {
        m_client = new QMqttClient(this);
        m_client->setHostname("100.114.147.149");
        m_client->setPort(1883);
        m_client->connectToHost();

        // Connect other necessary signals and slots for MQTT communication
    }

    // Publish the new airConditional state to the MQTT topic
    publishToMqtt("esp/bedroom/airConditional", QString::number(airConditionalState));
}
void bedroomForm::on_spinBox_airConditional_valueChanged(int arg1)
{
    // Check if the Air Conditional button is in the "On" state
    QString buttonText = ui->pushButton_airConditional->text();

    if (buttonText == "On") {
        // Get the new temperature value from the spinbox
        QString temperatureValue = QString::number(arg1);
        if (!m_client) {
            m_client = new QMqttClient(this);
            m_client->setHostname("100.114.147.149");
            m_client->setPort(1883);
            m_client->connectToHost();

            // Connect other necessary signals and slots for MQTT communication
        }
        // Publish the new temperature to the MQTT topic
        publishToMqtt("esp/bedroom/airConditional/temp", temperatureValue);
    }
    else{
        QMessageBox::warning(this, "Warning", "Chú ý, bạn cần bật điều hoà trước!!");
    }
}
void bedroomForm::on_pushButton_temp_clicked()
{
    tempchartform -> show();
}


void bedroomForm::on_pushButton_humid_clicked()
{
    humidchartform -> show();
}


void bedroomForm::on_pushButton_pres_clicked()
{
    preschartform -> show();
}


void bedroomForm::on_pushButton_co2_clicked()
{
    co2chartform -> show();
}

