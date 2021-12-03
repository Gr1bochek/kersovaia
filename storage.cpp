#include "storage.h"
#include "ui_storage.h"

Storage::Storage(bool vallk,QWidget *parent)
    : QMainWindow(parent)
    ,UserRole(vallk)
    , ui(new Ui::Storage)
{
    ui->setupUi(this);

    db.ConnectToDB();
    db.CreateTable();
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

void Storage::hider(bool valv)
{
    if (!valv)
    {
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
QDialog*redag=new QDialog;
redag->setFixedSize(300,150);
QHBoxLayout*reder=new QHBoxLayout(redag);
QLabel*texter=new QLabel(redag);
QLineEdit*editor=new QLineEdit(redag);

editor->setInputMask("99999999");

texter->setText("Введіть ваше значення:");
reder->addWidget(texter);
reder->addWidget(editor);
redag->exec();

int coper=editor->text().toInt();

    int code=model->index(row,1).data().toInt();

if(row==-1)
{
    QMessageBox::warning(0,"Помилка","Виберіть\nпункт з таблиці.");
    return;
}

    db.spysat(code,coper);

    model->select();
delete redag;
}

void Storage::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(this->rect(),QPixmap(":/images/main.png").scaled(this->size()));
}
