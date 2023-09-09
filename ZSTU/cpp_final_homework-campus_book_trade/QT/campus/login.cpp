#pragma once
#include "login.h"
#include "ui_login.h"
#include "buyerform.h"


Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    //限制输入长度
    this->ui->accountTextbox->setMaxLength(40);
    this->ui->passwordTextbox->setMaxLength(20);

    this->ui->accountTextbox->setText("Mitchell");
    this->ui->passwordTextbox->setText("123456");

}

Login::~Login()
{
    delete ui;
}


//=========================================private slots================================================
//-----------------------------------------自定义控件事件--------------------------------------------------------


/*
函数名：register_button_click()
功能：进入注册界面
*/
void Login::register_button_click()
{
    this->hide();
    emit show_registerForm();
}


/*
函数名：login_button_click()
功能：登录流程
*/
void Login::login_button_click()
{
    //存储输入的账号信息
    QString id=this->ui->accountTextbox->text();
    QString passwd=this->ui->passwordTextbox->text();
    if(id.isEmpty() || passwd.isEmpty()){
        QMessageBox::warning(NULL,"error","用户名或密码未输入");
        return ;
    }

    //匹配数据库中的账号
    QString search=QString("select * from account"
                           " where id='%1' and password ='%2'").arg(id).arg(passwd);
    DbManager* dba=DbManager::get_dba();
    QSqlQuery res(dba->db);
    res.exec(search);
    if(!res.next()){
        QMessageBox::warning(NULL,"error","账号或密码错误");
        return ;
    }

    //登录成功后，获取该用户的基本信息并初始化account对象
    QString userId=res.value("id").toString();
    QString userPassword=res.value("password").toString();
    QString userPhone=res.value("phone").toString();
    QString userAddress=res.value("address").toString();
    Account* user=Account::get_account();
    user->renew_account(userId,userPassword,userPhone,userAddress);
    qDebug()<<userId<<userPassword<<userPhone<<userAddress;


    this->hide();
    emit show_buyerForm();

}




//------------------------------------------接收其他窗口发出的信号----------------------------------------

/*
函数名：receive_from_register()
功能：注册操作完成后返回登录界面
*/
void Login::receive_from_register()
{
    this->ui->accountTextbox->clear();
    this->ui->passwordTextbox->clear();
    this->show();
}


/*
函数名：receive_from_buyer()
功能：从买方或卖方界面退出
*/
void Login::receive_from_buyerOrseller()
{
    this->ui->accountTextbox->clear();
    this->ui->passwordTextbox->clear();
    this->show();
}
