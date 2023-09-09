#pragma once

#include "login.h"
#include "dbmanager.h"
#include "register.h"
#include <QDir>

DbManager* DbManager::dba=NULL;
Account* Account::account=NULL;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qDebug()<<"1111";
    //界面声明
    Login loginForm;
    Register registerForm;
    BuyerForm buyerForm;
    SellerForm sellerForm;

    loginForm.show();
    qDebug()<<"2222";


    //连接登录界面和注册界面
    QObject::connect(&loginForm,SIGNAL(show_registerForm()),&registerForm,SLOT(receive_from_login()));
    QObject::connect(&registerForm,SIGNAL(show_loginForm()),&loginForm,SLOT(receive_from_register()));

    //连接登录界面和买(卖)方界面
    QObject::connect(&loginForm,SIGNAL(show_buyerForm()),&buyerForm,SLOT(receive_from_login()));
    QObject::connect(&buyerForm,SIGNAL(show_loginForm()),&loginForm,SLOT(receive_from_buyerOrseller()));
    QObject::connect(&sellerForm,SIGNAL(show_loginForm()),&loginForm,SLOT(receive_from_buyerOrseller()));

    //连接买方界面和买方界面
    QObject::connect(&buyerForm,SIGNAL(show_sellerForm()),&sellerForm,SLOT(receive_from_buyer()));
    QObject::connect(&sellerForm,SIGNAL(show_buyerForm()),&buyerForm,SLOT(receive_from_seller()));



    return a.exec();
}
