#include "storage.h"
#include "ui_storage.h"

Storage::Storage(QString vallk,QWidget *parent)
    : QMainWindow(parent)
    ,UserRole(vallk)
    , ui(new Ui::Storage)
{
    ui->setupUi(this);

    db.ConnectToDB();

    db.CreateTable("Store_storage");
    db.CreateTable("informationOfUsers");

    model=new QSqlTableModel(this,db.getDB());
    model->setTable("Store_storage");


    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0,true);


    model->select();
    hider(UserRole);
}

Storage::~Storage()
{
    delete ui;
}

void Storage::hider(QString valv)
{
    if (valv=="user")
    {
        ui->ChangeTable->hide();
        ui->Button_Dodaty->hide();
        ui->Button_Delete->hide();
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }

}
void Storage::on_Button_Dodaty_clicked()
{
    insertData object;
    object.exec();
    model->select();
}
void Storage::on_Button_Delete_clicked()
{
    int code=model->index(row,1).data().toInt();
    db.deleteData(code);
    model->removeRow(row);
    model->select();
}
void Storage::on_tableView_clicked(const QModelIndex &index)
{
    row=index.row();
}


void Storage::on_Button_Spisaty_clicked()
{
    People zapisani;
    zapisani.setProductName(model->index(row,2).data().toString());
    zapisani.setProductCode(model->index(row,1).data().toInt());

    zapisani.exec();

    model->select();

}

void Storage::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(this->rect(),QPixmap(":/images/main.png").scaled(this->size()));
}

void Storage::on_ChangeTable_clicked()
{
    if(ui->ChangeTable->text()=="Показати\nсписаний товар")
    {
        ui->ChangeTable->setText("Показати\nтовар на складі");
        model->setTable("informationOfUsers");
        ui->tableView->setModel(model);
        model->select();
    }
    else
    {
        ui->ChangeTable->setText("Показати\nсписаний товар");
        model->setTable("Store_storage");
        ui->tableView->setModel(model);
        model->select();
    }
}

