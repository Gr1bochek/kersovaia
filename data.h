#ifndef DATA_H
#define DATA_H

#include <QString>
#include <QVariantList>

class Data
{
private:
    QString NameTov;
    QString TerminPrid;
    QString PostachTov;
    int codeTov;
    int priceTov;
    int kilkistTov;

public:
    int getCode()const;
    QVariantList getdata();
    Data(QString,QString,QString,int,int,int);
    Data();
};

#endif // DATA_H
