#pragma once
#ifndef DBMANAGER_H
#define DBMANAGER_H
#include "all_headers.h"

class DbManager
{
private:
    static DbManager* dba;

    DbManager();
    ~DbManager();
public:
    static DbManager* get_dba(){
        if(dba==NULL) dba=new DbManager();
        return dba;
    }
    QSqlDatabase db;
};

#endif // DBMANAGER_H
