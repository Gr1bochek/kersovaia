#include "data.h"

int Data::getCode() const
{
    return codeTov;
}

QVariantList Data::getdata()
{
    QVariantList data;
    data.append(codeTov);
    data.append(NameTov);
    data.append(priceTov);
    data.append(kilkistTov);
    data.append(TerminPrid);
    data.append(PostachTov);



    return data;
}

Data::Data(QString NameTov, QString TerminPrid, QString PostachTov, int codeTov, int priceTov, int kilkistTov)
    :NameTov(NameTov),TerminPrid(TerminPrid),PostachTov(PostachTov),codeTov(codeTov),priceTov(priceTov),kilkistTov(kilkistTov)
{

}

Data::Data()
{

}
