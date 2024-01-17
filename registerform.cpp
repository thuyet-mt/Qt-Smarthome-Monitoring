#include "registerform.h"
#include "ui_registerform.h"

registerForm::registerForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::registerForm)
{
    ui->setupUi(this);


}

registerForm::~registerForm()
{
    delete ui;

}

void registerForm::on_pushButton_register_clicked()
{
    QString username = ui->lineEdit_reg_user->text();
    QString password = ui->lineEdit_reg_pass->text();
    QString verify_pass = ui->lineEdit_verify_pass->text();
    QString email = ui -> lineEdit_reg_email->text();

    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(nameDatabase);

    if (!mydb.open()) {
        qDebug() << "Không thể mở kết nối đến cơ sở dữ liệu!";
        return;
    }
    if (username.isEmpty() || password.isEmpty() || verify_pass.isEmpty()) {
        QMessageBox::warning(this, "Lỗi", "Vui lòng nhập đầy đủ thông tin!");
        return;
    }
    if (!(password==verify_pass)){
        QMessageBox::warning(this, "Error", "Verify password failed!");
    }
    QSqlQuery query;
    query.prepare("INSERT INTO listuser (name, roletype, password, mail) VALUES (?, ?, ?, ?)");
    query.addBindValue(username);
    query.addBindValue("admin");
    query.addBindValue(password);
    query.addBindValue(email);

    if (query.exec()) {
        QMessageBox::information(this, "Thành công", "Đăng ký thành công!");
    } else {
        qDebug() << "Không thể thực hiện truy vấn INSERT:" << query.lastError();
                                                                           QMessageBox::critical(this, "Lỗi", "Đăng ký thất bại!");
    }

    mydb.close();
    mydb.removeDatabase(QSqlDatabase::defaultConnection);
    //close();
}

void registerForm::closeEvent(QCloseEvent *event)
{
    // ... code khác nếu cần ...
    QWidget::closeEvent(event);

    emit registerClosed(); // Phát ra signal khi cửa sổ đăng ký được đóng
}
