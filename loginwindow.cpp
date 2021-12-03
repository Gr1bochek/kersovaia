#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "loginadmin.h"

LoginWindow::LoginWindow(bool& successfull_Login,QWidget *parent) :
    QDialog(parent),
    loginADM(&successfull_Login),
    ui(new Ui::LoginWindow)

{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_ButtonAdmin_clicked()
{

    LoginAdmin loggar(*loginADM);
    loggar.exec();
    if(*loginADM)
        this->close();
}

void LoginWindow::on_ButtonUser_clicked()
{

    close();
}

void LoginWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(this->rect(),QPixmap(":/images/Desktop11.png").scaled(this->size()));
}
