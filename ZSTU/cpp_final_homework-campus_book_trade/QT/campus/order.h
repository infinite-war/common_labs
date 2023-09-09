#pragma once
#ifndef ORDER_H
#define ORDER_H

#include "all_headers.h"
#include "book.h"
#include "account.h"
#include "dbmanager.h"

class Order
{
public:
    Order();
    //交易完成后，订单便不可再修改
    Order(QString sellerName,Book book);

    Account* get_seller();
    Book* get_book();
    QDateTime get_time();

private:
    Account* seller;
    Book book;
    QDateTime createTime;
};

#endif // ORDER_H
