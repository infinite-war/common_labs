#include "book.h"

Book::Book(){}

Book::Book(int id, QString ISBN, QString bookName, QString writer, QString publisher,QString owner, float price,  QString takeMethod, int status, int selled)
    :id(id),isbn(ISBN),bookName(bookName),writer(writer),publisher(publisher),owner(owner),price(price),takeMethod(takeMethod),status(status),selled(selled){
}



//============================设置内容==============================
void Book::renew_book(QString ISBN, QString bookName, QString writer, QString publisher,QString owner, float price,  QString takeMethod, int status, int selled){
    set_isbn(ISBN);
    set_bookName(bookName);
    set_writer(writer);
    set_publisher(publisher);
    set_takeMethod(takeMethod);
    set_owner(owner);
    set_price(price);
    set_status(status);
    set_selled(selled);
}
void Book::set_isbn(QString isbn){this->isbn=isbn;}
void Book::set_bookName(QString bookName){this->bookName=bookName;}
void Book::set_writer(QString writer){this->writer=writer;}
void Book::set_publisher(QString publisher){this->publisher=publisher;}
void Book::set_takeMethod(QString takeMethod){this->takeMethod=takeMethod;}
void Book::set_owner(QString owner){this->owner=owner;}
void Book::set_price(float price){this->price=price;}
void Book::set_status(int status){this->status=status;}
void Book::set_selled(int selled){this->selled=selled;}


//============================设置内容==============================
int Book::get_id(){return this->id;}
QString Book::get_isbn(){return this->isbn;}
QString Book::get_bookName(){return this->bookName;}
QString Book::get_writer(){return this->writer;}
QString Book::get_publisher(){return this->publisher;}
QString Book::get_takeMethod(){return this->takeMethod;}
QString Book::get_owner(){return this->owner;}
float Book::get_price(){return this->price;}
int Book::get_status(){return this->status;}
int Book::get_selled(){return this->selled;}
