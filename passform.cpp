#include "passform.h"
#include "ui_passform.h"

passForm::passForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::passForm)
{
    ui->setupUi(this);
    QSqlDatabase mydb_forgotpass = QSqlDatabase::addDatabase("QSQLITE");
    mydb_forgotpass.setDatabaseName(nameDatabase);

    if (!mydb_forgotpass.open()) {
        qDebug() << "Không thể mở kết nối đến cơ sở dữ liệu!";
        return;
    }
    QSqlQuery query;
    query.prepare("SELECT PASSWORD FROM PASSWORD WHERE ID = 1");

    if (query.exec()) {
        if (query.next()) {
            QString password = query.value(0).toString();
            ui->label_display_password->setText(password);
        }
    } else {
        qDebug() << "Không thể thực hiện truy vấn INSERT:" << query.lastError();
        QMessageBox::critical(this, "Lỗi", "Tìm kiếm mật khẩu thất bại!");
    }

    mydb_forgotpass.close();
    mydb_forgotpass.removeDatabase(QSqlDatabase::defaultConnection);
    //close();
}

passForm::~passForm()
{
    delete ui;
}
