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
    void spysat(int,int);
    void deleteData(int);
    QSqlDatabase getDB();
    static void InsertIntoTable(const QVariantList&);
    void ConnectToDB();
    void CreateTable();
    DataBaseManager();
};

#endif // DATABASEMANAGER_H
