#include "insertdata.h"
#include "ui_insertdata.h"
#include "data.h"

insertData::insertData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::insertData)
{
    ui->setupUi(this);
    ui->Kod_Tovary->setInputMask("99999999");
    ui->Price_Tovary->setInputMask("9999999999");
    ui->Name_Tovary->setInputMask("NNNNNNNNNNNNNNNN");
    QString dataMask="[0-9]?[0-9]\\.[0-9]?[0-2]\\.2[0-9]{3}";
    QRegExp dataRegExp(dataMask);
    QRegExpValidator *dataValidator=new QRegExpValidator(dataRegExp,this);
    ui->Termin_Pridatnosti->setValidator(dataValidator);
}
insertData::~insertData()
{
    delete ui;
}

void insertData::on_Dobaviti_clicked()
{

    QString Code=ui->Kod_Tovary->text();
    QString name=ui->Name_Tovary->text();
    QString price=ui->Price_Tovary->text();
    QString kilkist=ui->Kilkist_Tovary->text();
    QString termin=ui->Termin_Pridatnosti->text();
    QString postavchik=ui->Postavchik_Tovary->text();

    if(Code=="" || name=="" || price=="" || kilkist=="" || termin=="" || postavchik=="")
    {
        QMessageBox::warning(0,"Помилка","Заповніть усі поля!");
        return;
    }

    Data obec(name,termin,postavchik,Code.toInt(),price.toInt(),kilkist.toInt());
    DataBaseManager::InsertIntoTable(obec.getdata());
    this->close();

}

void insertData::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(this->rect(),QPixmap(":/images/vvid.png").scaled(this->size()));
}
