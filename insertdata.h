#ifndef INSERTDATA_H
#define INSERTDATA_H

#include <QDialog>
#include <QMessageBox>
#include <QString>
#include <QPainter>
#include <QRegExpValidator>
#include "databasemanager.h"

namespace Ui {
class insertData;
}

class insertData : public QDialog
{
    Q_OBJECT

public:
    void paintEvent(QPaintEvent *);
    explicit insertData(QWidget *parent = nullptr);
    ~insertData();

private slots:
    void on_Dobaviti_clicked();

private:

    Ui::insertData *ui;
};

#endif // INSERTDATA_H
