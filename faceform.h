#ifndef FACEFORM_H
#define FACEFORM_H

#include <QWidget>
#include <QMqttClient>
namespace Ui {
class faceForm;
}

class faceForm : public QWidget
{
    Q_OBJECT

public:
    explicit faceForm(QWidget *parent = nullptr);
    ~faceForm();

private:
    Ui::faceForm *ui;
    QMqttClient *m_client;
};

#endif // FACEFORM_H
