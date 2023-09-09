#pragma once
#include "register.h"
#include "ui_register.h"

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);

    //限制输入长度
    this->ui->userNameTextbox->setMaxLength(35);
    this->ui->passwordTextbox->setMaxLength(20);
    this->ui->phoneTextbox->setMaxLength(20);
    this->ui->addressTextbox->setMaxLength(250);
}

Register::~Register()
{
    delete ui;
}



//=============================================private slots==========================================
//----------------------------------------------自定义控件事件-----------------------------------------


/*
函数名：register_botton_click()
功能：注册一个账号并存入account数据表
*/

void Register::register_button_click()
{
    //获取输入框信息
    QString id=this->ui->userNameTextbox->text();
    QString password=this->ui->passwordTextbox->text();
    QString phone=this->ui->phoneTextbox->text();
    QString address=this->ui->addressTextbox->text();

    //输入检查
    if(id.isEmpty() || password.isEmpty() || phone.isEmpty()|| address.isEmpty()){
        QMessageBox::warning(NULL,"error","注册信息不完整");
        return ;
    }

    Account user(id,password,phone,address);
    //查询account表，判定用户名是否已存在
    DbManager* dba=DbManager::get_dba();
    QSqlQuery res(dba->db);
    QString sqlSentence=QString("select id from account where id='%1';").arg(id);
    res.exec(sqlSentence);
    if(res.next()){ //发现重名就弹窗报错
        QMessageBox::warning(NULL,"error","用户名已存在");
        return ;
    }

    //添加账号记录,弹出成功提示后返回登录界面
    sqlSentence=QString("insert into account values('%1','%2','%3','%4');").arg(id).arg(password).arg(phone).arg(address);
    res.exec(sqlSentence);
    QMessageBox::information(NULL,"success","账号已注册!");
    this->hide();
    emit show_loginForm();
}

/*
函数名：cancel_botton_click()
功能：取消注册，回到登录界面
*/
void Register::cancel_button_click()
{
    this->hide();
    emit show_loginForm();
}




//---------------------------------------------接收其他窗口信号----------------------------------------

/*
函数名：receive_from_login()
功能：接收login界面点击注册按钮后发出的信号，并显示注册界面
*/
void Register::receive_from_login()
{
    this->show();
}
