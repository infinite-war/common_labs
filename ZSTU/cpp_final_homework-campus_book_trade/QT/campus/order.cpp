#pragma once
#include "order.h"

Order::Order(){}

Order::Order(QString sellerName,Book book)
    :book(book){
    //设置卖方信息
    QString search=QString("select * from account"
                           " where id='%1'").arg(sellerName);
    DbManager* dba=DbManager::get_dba();
    QSqlQuery res(dba->db);
    res.exec(search);
    res.next();
    this->seller=new Account(res.value("id").toString(),res.value("password").toString(),
                             res.value("phone").toString(),res.value("address").toString());
}

Account *Order::get_seller(){return this->seller;}
Book *Order::get_book(){return &(this->book);}
QDateTime Order::get_time(){return this->createTime.currentDateTime();}


