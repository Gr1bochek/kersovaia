#ifndef STORAGE_H
#define STORAGE_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QPainter>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include "insertdata.h"
#include "databasemanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Storage; }
QT_END_NAMESPACE

class Storage : public QMainWindow
{
    Q_OBJECT

public:
    void paintEvent(QPaintEvent *);
    Storage(bool,QWidget *parent = nullptr);
    ~Storage();

private slots:
    void on_Button_Dodaty_clicked();

    void on_Button_Delete_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_Button_Spisaty_clicked();


private:

bool UserRole;
    Ui::Storage *ui;
    QSqlTableModel *model;
    int row=-1;
    DataBaseManager db;

private:
    void hider(bool);

};
#endif // STORAGE_H
