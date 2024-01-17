#ifndef LIVINGROOMFORM_H
#define LIVINGROOMFORM_H

#include <QWidget>

namespace Ui {
class livingroomForm;
}

class livingroomForm : public QWidget
{
    Q_OBJECT

public:
    explicit livingroomForm(QWidget *parent = nullptr);
    ~livingroomForm();

private:
    Ui::livingroomForm *ui;
};

#endif // LIVINGROOMFORM_H
