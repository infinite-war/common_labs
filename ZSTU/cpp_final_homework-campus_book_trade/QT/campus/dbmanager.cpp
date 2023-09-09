#pragma once
#include "all_headers.h"
#include "dbmanager.h"
#include <QDir>

/*
函数名:DbManager
功能:构造函数。通过读取txt文件中的账号信息连接数据库
*/
DbManager::DbManager()
{
    db=QSqlDatabase::addDatabase("QODBC");

    QFile ifs("./database_user/accounts.txt");
    if(!ifs.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"数据库账号文件打开失败";
    }

    ifs.readLine();//跳过第一行
    QString a=ifs.readLine();
    QStringList list=a.split(' ');   //空格作为分隔符拆开一行文本

    db.setHostName(list[0]);
    db.setDatabaseName(list[1]);
    db.setUserName(list[2]);
    db.setPassword(list[3]);
    db.setPort(list[4].toInt());

    if(!db.open()){
        QMessageBox::information(NULL,"DBA","数据库连接失败");
    }
    else {
        QMessageBox::information(NULL,"DBA","数据库连接成功");
    }

    ifs.close();
}
DbManager::~DbManager(){}
