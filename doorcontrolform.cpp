#include "doorcontrolform.h"
#include "ui_doorcontrolform.h"

#include <QtCore/QDateTime>
#include <QtMqtt/QMqttClient>
#include <QtWidgets/QMessageBox>


doorcontrolForm::doorcontrolForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::doorcontrolForm)
    , m_client_door(new QMqttClient(this))
{
    pass = new passForm();
    finger = new fingerForm();
    rfid = new rfidForm();
    face = new faceForm();
    ui->setupUi(this);
    m_client_door->setHostname("100.114.147.149");
    m_client_door->setPort(1883);
    m_client_door->connectToHost();


    // mydb_door = QSqlDatabase::addDatabase("QSQLITE");
    // mydb_door.setDatabaseName("/home/pi/Desktop/sqlite/user.db");
    // mydb_door.open();

    // if (!mydb_door.isOpen()) {
    //     qDebug() << "Can't open database. Error:" << mydb_door.lastError().text();
    //     //ui->label->setText("Can't open database. Error: " + mydb.lastError().text());
    //     return;
    // }

    connect(m_client_door, &QMqttClient::stateChanged, this, [this](QMqttClient::ClientState state) {
        if (state == QMqttClient::Connected) {
            qDebug() << "Connected to broker";
            // Subscribe sau khi kết nối thành công
            QString topic_door = "esp/door/check/#";
            QMqttTopicFilter topicFilter0(topic_door);
            m_client_door->subscribe(topicFilter0);
        } else {
            qDebug() << "Connection to broker failed";
        }
    });

        // Xử lý khi nhận được tin nhắn từ MQTT broker
    connect(m_client_door, &QMqttClient::messageReceived, this, [this](const QByteArray &message){
//, const QMqttTopicName &topic) {
        const QString content = QDateTime::currentDateTime().toString()
                    //+ QLatin1String(" Received Topic: ")
                    //+ topic.name()
                    + QLatin1String(" Door open: ")
                    + message
                    + QLatin1Char('\n');
        // Kiểm tra ui trước khi sử dụng
        ui->plainTextEdit_door_history->insertPlainText(content);
        if (ui) {

        }
    });



}

doorcontrolForm::~doorcontrolForm()
{
    delete ui;
}


void doorcontrolForm::on_pushButton_pass_clicked()
{
    pass->show();
}


void doorcontrolForm::on_pushButton_rfid_clicked()
{
    rfid->show();
}


void doorcontrolForm::on_pushButton_finger_clicked()
{
    finger->show();
}


void doorcontrolForm::on_pushButton_face_clicked()
{
    face->show();
}

