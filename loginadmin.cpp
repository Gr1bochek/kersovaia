#include "loginadmin.h"
#include "ui_loginAdmin.h"

#include <QMessageBox>

LoginAdmin::LoginAdmin(bool& vavle,QWidget *parent) :
    QDialog(parent),
    ADMLog(&vavle),
    ui(new Ui::LoginAdmin)
{
    ui->setupUi(this);
    ui->ParolAutorization->setEchoMode(QLineEdit::Password);
}

LoginAdmin::~LoginAdmin()
{
    delete ui;
}



void LoginAdmin::on_ButtonAdminAutorization_clicked()
{
    QString Login_Admina = ui->LoginAutorization->text();
    QString Pass_Admina = ui->ParolAutorization->text();

    if(Login_Admina == "123" && Pass_Admina == "123")
    {
        *ADMLog=true;
        hide();

    }
    else
    {
      QMessageBox::warning(this, "Помилка" , "Не вірний логін або пароль" );
    }
}


void LoginAdmin::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(this->rect(),QPixmap(":/images/admin77.png").scaled(this->size()));
}
