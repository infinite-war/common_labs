#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "all_headers.h"

class Account
{
public:
    static Account* get_account(){
        if(account==NULL) account=new Account("0","0","0","0");
        return account;
    }

    Account();
    Account(QString id,QString password,QString phone, QString address);

    //设置内容
    void renew_account(QString id,QString password,QString phone, QString address);
    void renew_account(Account& user);
    void set_id(QString id);
    void set_password(QString password);
    void set_phone(QString phone);
    void set_address(QString address);


    //获取内容
    QString get_id();
    QString get_password();
    QString get_phone();
    QString get_address();


private:
    QString id;
    QString password;
    QString phone;
    QString address;
    static Account* account;
};

#endif // ACCOUNT_H
