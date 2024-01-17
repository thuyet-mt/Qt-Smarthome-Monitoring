#include "fingerform.h"
#include "ui_fingerform.h"

fingerForm::fingerForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::fingerForm)
{
    ui->setupUi(this);
    mydb_finger = QSqlDatabase::addDatabase("QSQLITE");
    mydb_finger.setDatabaseName(nameDatabase);
    mydb_finger.open();
    if (!mydb_finger.isOpen()) {
        qDebug() << "Can't open database in rfidform.cpp. Error:" << mydb_finger.lastError().text();
        //ui->label->setText("Can't open database. Error: " + mydb.lastError().text());
        return;
    }
    else{
        qDebug() << "Open database done";
    }

    // Tạo một QSqlQueryModel
    QSqlQueryModel *model = new QSqlQueryModel;

    // Thực hiện truy vấn để lấy 3 cột bạn muốn từ bảng
    model->setQuery("SELECT ID, UID0, UID1, UID2, UID3, UID4, UID5, UID6, UID7, UID8 FROM FINGERPRINT");

    // Tạo một QTableView và đặt model cho nó
    //QTableView *view = new QTableView;
    ui->tableView->setModel(model);
    ui->tableView->show();


}

fingerForm::~fingerForm()
{
    delete ui;
}
