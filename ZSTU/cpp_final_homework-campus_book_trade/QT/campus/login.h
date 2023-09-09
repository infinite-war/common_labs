#pragma once
#ifndef LOGIN_H
#define LOGIN_H

#include "all_headers.h"
#include "register.h"
#include "buyerform.h"
#include "sellerform.h"
#include "dbmanager.h"
#include "account.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();



private slots:
    //自定义控件事件
    void register_button_click();   //按下注册按钮
    void login_button_click();   //按下登录按钮

    //接收其他窗口发出的信号
    void receive_from_register();
    void receive_from_buyerOrseller();

signals://信号量只用声明不用实现
    void show_registerForm();
    void show_buyerForm();

private:
    Ui::Login *ui;
//    BuyerForm *buyerForm;
//    SellerForm *sellerForm;
};
#endif // LOGIN_H
