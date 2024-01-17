#ifndef LIVING_ROOM_H
#define LIVING_ROOM_H

#include <QDialog>

namespace Ui {
class Living_Room;
}

class Living_Room : public QDialog
{
    Q_OBJECT

public:
    explicit Living_Room(QWidget *parent = nullptr);
    ~Living_Room();

private:
    Ui::Living_Room *ui;
};

#endif // LIVING_ROOM_H
