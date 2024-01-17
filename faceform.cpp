#include "faceform.h"
#include "ui_faceform.h"

faceForm::faceForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::faceForm)
    , m_client(new QMqttClient(this))
{
    ui->setupUi(this);
    m_client->setHostname("100.114.147.149");
    m_client->setPort(1883);
    m_client->connectToHost();
    connect(m_client, &QMqttClient::stateChanged, this, [this](QMqttClient::ClientState state) {
        if (state == QMqttClient::Connected) {
            qDebug() << "Connected to broker";
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
        }
    });

}

faceForm::~faceForm()
{
    delete ui;
}
