#include "databasemanager.h"

void DataBaseManager::spysat(int spes,int coper=0)
{
    QSqlQuery query;
    query.prepare("SELECT Kilkist FROM Store_storage WHERE Code_Tovary = :code");
    query.bindValue(":code",spes);
    query.exec();
    query.next();
    int Kilkist=query.value(0).toInt()-coper;
    if(Kilkist<0) Kilkist=0;
    query.prepare("UPDATE Store_storage SET Kilkist =:kilk"
" WHERE Code_Tovary =:Code");
    query.bindValue(":kilk",Kilkist);
    query.bindValue(":Code",spes);
    query.exec();
}

void DataBaseManager::deleteData(int str)
{
    QSqlQuery query;
    query.prepare("DELETE FROM Store_storage WHERE Code_Tovary = :code");
    query.bindValue(":code",str);
    query.exec();
}

QSqlDatabase DataBaseManager::getDB()
{
    return db;
}

void DataBaseManager::InsertIntoTable(const QVariantList & data)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Store_storage(Code_Tovary, Name, Price, Kilkist, Srok_pridatnosti, Postavchik)"
" VALUES(:CodeTov,:name,:price,:kilkist,:srokPrid,:post)");
    query.bindValue(":CodeTov",data[0].toInt());
    query.bindValue(":name",data[1].toString());
    query.bindValue(":price",data[2].toInt());
    query.bindValue(":kilkist",data[3].toInt());
    query.bindValue(":srokPrid",data[4].toString());
    query.bindValue(":post",data[5].toString());

    query.exec();

}

void DataBaseManager::ConnectToDB()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./Products.sql");

    if(db.open())
    {
        qDebug("Oppen");
    }
    else
    {
        qDebug("Not Oppen");
    }

}

void DataBaseManager::CreateTable()
{
    QSqlQuery query;

    query.exec("CREATE TABLE Store_storage(id INTEGER PRIMARY KEY AUTOINCREMENT,Code_Tovary INTEGER UNIQUE, Name TEXT, Price INTEGER, Kilkist INTEGER, Srok_pridatnosti TEXT, Postavchik TEXT);");

}

DataBaseManager::DataBaseManager()
{

}
