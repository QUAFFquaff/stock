#ifndef DATABASE_H
#define DATABASE_H

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QStringList>
#include <QVariant>
#include <QSqlDriver>
#include <QSqlRecord>
#include <QSqlField>
#include <QSqlError>

static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connection");
    db.setHostName("dearjohn.cn");
    db.setPort(3306);
    db.setDatabaseName("stock");
    db.setUserName("stock");
    db.setPassword("357721012");
    bool ok = db.open();
    if (ok)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif // DATABASE_H
