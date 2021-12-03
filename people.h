#ifndef PEOPLE_H
#define PEOPLE_H

#include <QDialog>
#include <QDate>
#include <QMessageBox>

#include "databasemanager.h"

namespace Ui {
class People;
}

class People : public QDialog
{
    Q_OBJECT

public:
    void setProductName(const QString &);
    void setProductCode(int);

    explicit People(QWidget *parent = nullptr);
    ~People();

private slots:
    void on_pushButton_clicked();

private:
    int ProductCode;
    QString product_name;
    Ui::People *ui;
};

#endif // PEOPLE_H
