#ifndef BOOK_H
#define BOOK_H

#include "all_headers.h"

class Book
{
public:
    Book();

    Book(int id, QString ISBN, QString bookName, QString writer, QString publisher,QString owner, float price,  QString takeMethod, int status, int selled );

    //设置内容
    void renew_book(QString ISBN, QString bookName, QString writer, QString publisher,QString owner, float price,  QString takeMethod, int status, int selled);
    void set_isbn(QString isbn);
    void set_bookName(QString bookName);
    void set_writer(QString writer);
    void set_publisher(QString publisher);
    void set_takeMethod(QString takeMethod);
    void set_owner(QString owner);
    void set_price(float price);
    void set_status(int status);
    void set_selled(int selled);


    //获取内容
    int get_id();
    QString get_isbn();
    QString get_bookName();
    QString get_writer();
    QString get_publisher();
    QString get_takeMethod();
    QString get_owner();
    float get_price();
    int get_status();
    int get_selled();



private:
    int id;
    QString isbn;
    QString bookName;
    QString writer;
    QString publisher;
    QString owner;
    float price;
    QString takeMethod;
    int status;
    int selled;
};

#endif // BOOK_H
