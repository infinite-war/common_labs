#include "passwordeditform.h"
#include "ui_passwordeditform.h"

PasswordEditForm::PasswordEditForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PasswordEditForm)
{
    ui->setupUi(this);

    //限制输入长度
    this->ui->originalTextbox->setMaxLength(20);
    this->ui->newTextbox->setMaxLength(20);
    this->ui->newConfirmTextbox->setMaxLength(20);
}

PasswordEditForm::~PasswordEditForm()
{
    delete ui;
}


/*
函数名：clear_lineEdit()
功能：清空界面中的编辑框内容
*/
void PasswordEditForm::clear_lineEdit()
{
    this->ui->originalTextbox->clear();
    this->ui->newTextbox->clear();
    this->ui->newConfirmTextbox->clear();
}


//=============================================private slots==========================================
//----------------------------------------------自定义控件事件-----------------------------------------


/*
函数名：password_edit_click()
功能：确认修改密码
*/
void PasswordEditForm::password_edit_click()
{
    QString original=this->ui->originalTextbox->text();
    QString newPasswd=this->ui->newTextbox->text();
    QString newConfirmPasswd=this->ui->newConfirmTextbox->text();

    Account* account=Account::get_account();

    //信息栏是否完善
    if(original.isEmpty() || newPasswd.isEmpty() || newConfirmPasswd.isEmpty()){
        QMessageBox::warning(NULL,"error","修改信息不完善");
        return ;
    }
    //原密码是否正确
    if(original!=account->get_password()){
        QMessageBox::warning(NULL,"error","原密码不正确");
        return ;
    }
    //新密码与原密码是否相同
    if(newPasswd==account->get_password()){
        QMessageBox::warning(NULL,"error","新密码与原密码相同");
        return ;
    }
    //新密码与确认密码是否相同
    if(newPasswd!=newConfirmPasswd){
        QMessageBox::warning(NULL,"error","新密码与确认密码不吻合");
        return ;
    }


    //修改信息
    DbManager* dba=DbManager::get_dba();
    QSqlQuery res(dba->db);

    QString sqlSentence=QString("update account set password='%1' where id='%2'").arg(newPasswd).arg(account->get_id());
    res.exec(sqlSentence);
    QMessageBox::information(NULL,"success","密码修改成功!");
    this->close();
    account->set_password(newPasswd);
    //emit renew_account();
}


/*
函数名：cancel_click()
功能：取消修改密码
*/
void PasswordEditForm::cancel_click()
{
    this->close();
}
