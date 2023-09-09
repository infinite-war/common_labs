#pragma once
#ifndef REGISTER_H
#define REGISTER_H

#include "all_headers.h"
#include "account.h"
#include "dbmanager.h"

namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private slots:
    //自定义控件事件
    void register_button_click();
    void cancel_button_click();

    //接收其他窗口发出的信号
    void receive_from_login();


signals:
    void show_loginForm();

private:
    Ui::Register *ui;
};

#endif // REGISTER_H
