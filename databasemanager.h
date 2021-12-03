#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QDebug>
#include <QString>

class DataBaseManager
{
private:
    QSqlDatabase db;

public:
    static void InsertIntoTable_people(const QVariantList&);

    static void spysat(int,int);
    void deleteData(int);
    QSqlDatabase getDB();
    static void InsertIntoTable(const QVariantList&);
    void ConnectToDB();
    void CreateTable(const QString&);
    DataBaseManager();
};

#endif // DATABASEMANAGER_H
