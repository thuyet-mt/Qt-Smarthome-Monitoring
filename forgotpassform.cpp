#include "forgotpassform.h"
#include "ui_forgotpassform.h"

forgotpassForm::forgotpassForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::forgotpassForm)

{
    ui->setupUi(this);
}

forgotpassForm::~forgotpassForm()
{
    delete ui;
}
void forgotpassForm::closeEvent(QCloseEvent *event)
{
    // ... code khác nếu cần ...
    QWidget::closeEvent(event);

    emit forgotpassFormClosed(); // Phát ra signal khi cửa sổ đăng ký được đóng
}

void forgotpassForm::on_pushButton_takebackpass_clicked()
{
    QString username = ui->lineEdit_user->text();
    QString email = ui -> lineEdit_email->text();

    QSqlDatabase mydb_forgotpass = QSqlDatabase::addDatabase("QSQLITE");
    mydb_forgotpass.setDatabaseName(nameDatabase);

    if (!mydb_forgotpass.open()) {
        qDebug() << "Không thể mở kết nối đến cơ sở dữ liệu!";
        return;
    }
    if (username.isEmpty() && email.isEmpty()) {
        QMessageBox::warning(this, "Lỗi", "Vui lòng nhập thông tin!");
        return;
    }
    QSqlQuery query;
    query.prepare("SELECT password FROM listuser WHERE name = ? OR mail = ?");
    query.addBindValue(username);
    query.addBindValue(email);

    if (query.exec()) {
        if (query.next()) {
            QString password = query.value(0).toString();
            QMessageBox::information(this, "Tìm lại mật khẩu thành công", "Mật khẩu của bạn là: " + password);
        }
    } else {
        qDebug() << "Không thể thực hiện truy vấn INSERT:" << query.lastError();
        QMessageBox::critical(this, "Lỗi", "Đăng ký thất bại!");
    }

    mydb_forgotpass.close();
    mydb_forgotpass.removeDatabase(QSqlDatabase::defaultConnection);
    //close();
}


