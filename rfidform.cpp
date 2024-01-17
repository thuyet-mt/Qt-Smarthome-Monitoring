#include "rfidform.h"
#include "ui_rfidform.h"

rfidForm::rfidForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::rfidForm)
    , m_client_rfid(new QMqttClient(this))
{
    ui->setupUi(this);
    mydb_rfid = QSqlDatabase::addDatabase("QSQLITE");
    mydb_rfid.setDatabaseName(nameDatabase);
    mydb_rfid.open();
    if (!mydb_rfid.isOpen()) {
        qDebug() << "Can't open database in rfidform.cpp. Error:" << mydb_rfid.lastError().text();
        //ui->label->setText("Can't open database. Error: " + mydb.lastError().text());
        return;
    }
    else{
        qDebug() << "Open database done";
    }

    // Create QSqlTableModel

    QSqlTableModel *model = new QSqlTableModel(this, mydb_rfid);
    model->setTable("RFID"); // Change to your table name
    model->select();

    //Create QTableView
    //QTableView *tableView = new QTableView(this);
    ui->tableView->setModel(model);
    mydb_rfid.close();
    mydb_rfid.removeDatabase(QSqlDatabase::defaultConnection);


}


rfidForm::~rfidForm()
{
    delete ui;
}

void rfidForm::on_pushButton_2_clicked()
{

}


void rfidForm::on_pushButton_addRfidCard_clicked()
{

}


void rfidForm::on_pushButton_deleteRfidCard_clicked()
{

}

