#include "account.h"

Account::Account(){ }

Account::Account(QString id, QString password, QString phone, QString address)
    :id(id),password(password),phone(phone),address(address){
}


//============================设置内容==============================


void Account::renew_account(QString id, QString password, QString phone, QString address)
{
    set_id(id);
    set_password(password);
    set_phone(phone);
    set_address(address);
}

void Account::renew_account(Account &user)
{
    set_id(user.get_id());
    set_password(user.get_password());
    set_phone(user.get_phone());
    set_address(user.get_password());
}

void Account::set_id(QString id){this->id=id;}
void Account::set_password(QString password){this->password=password;}
void Account::set_phone(QString phone){this->phone=phone;}
void Account::set_address(QString address){this->address=address;}

//============================获取内容==============================
QString Account::get_id(){return this->id;}
QString Account::get_password(){return this->password;}
QString Account::get_phone(){return this->phone;}
QString Account::get_address(){return this->address;}
