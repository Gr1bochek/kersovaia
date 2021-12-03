#include "people.h"
#include "ui_people.h"

void People::setProductName(const QString & neimer)
{
    product_name=neimer;
}

void People::setProductCode(int coderator)
{
ProductCode=coderator;
}

People::People(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::People)
{
    ui->setupUi(this);
}

People::~People()
{
    delete ui;
}

void People::on_pushButton_clicked()
{
    QString name=ui->lineEdit_Name->text();
    QString date=QDate::currentDate().toString();
    QString count=ui->lineEdit_count->text();

    if(product_name== "")
    {
        QMessageBox::warning(0,"Помилка","Не вибрано продукт.");
    return;
    }

    QVariantList zbir;
    zbir.append(name);
    zbir.append(count);
    zbir.append(product_name);
    zbir.append(date);

    DataBaseManager::InsertIntoTable_people(zbir);
    DataBaseManager::spysat(ProductCode,count.toInt());
    this->close();
}

