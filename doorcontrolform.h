#ifndef DOORCONTROLFORM_H
#define DOORCONTROLFORM_H

#include <QWidget>
#include <QMqttClient>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "faceform.h"
#include "fingerform.h"
#include "passform.h"
#include "rfidform.h"
namespace Ui {
class doorcontrolForm;
}

class doorcontrolForm : public QWidget
{
    Q_OBJECT

public:
    explicit doorcontrolForm(QWidget *parent = nullptr);
    ~doorcontrolForm();

private slots:
    void on_pushButton_pass_clicked();

    void on_pushButton_rfid_clicked();

    void on_pushButton_finger_clicked();

    void on_pushButton_face_clicked();

private:
    Ui::doorcontrolForm *ui;
    QMqttClient *m_client_door;
    QSqlDatabase mydb_door;
    faceForm *face;
    fingerForm *finger;
    passForm *pass;
    rfidForm *rfid;
};

#endif // DOORCONTROLFORM_H
