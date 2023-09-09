#pragma once
#include "insertdialog.h"
#include "ui_insertdialog.h"

InsertDialog::InsertDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertDialog)
{
    ui->setupUi(this);

    //限制输入长度
    this->ui->isbnEdit->setMaxLength(60);
    this->ui->bookNameEdit->setMaxLength(250);
    this->ui->writerEdit->setMaxLength(40);
    this->ui->publisherEdit->setMaxLength(40);
    this->ui->priceEdit->setMaxLength(6);
    this->ui->takeMethodEdit->setMaxLength(250);
}

InsertDialog::~InsertDialog()
{
    delete ui;
}

//=========================================private slots================================================
//-----------------------------------------自定义控件事件--------------------------------------------------------


/*
函数名：cancelButton_click()
功能：取消添加记录流程
*/

void InsertDialog::cancelButton_click()
{
    this->close();
}


/*
函数名：confirmButton_click()
功能：完成编辑，并将编辑完成的对象发送给卖方界面
*/
void InsertDialog::confirmButton_click()
{
    //获取初始化book对象所需的内容
    QString isbn=this->ui->isbnEdit->text();
    QString bookName=this->ui->bookNameEdit->text();
    QString writer=this->ui->writerEdit->text();
    QString publisher=this->ui->publisherEdit->text();
    QString takeMethod=this->ui->takeMethodEdit->text();
    QString textPrice=this->ui->priceEdit->text();
    int status=this->ui->newStatusComboBox->currentText().toInt();
    int selled=this->ui->sellingStatuscomboBox->currentIndex();


    //判断输入信息是否完整
    if(isbn.isEmpty() || bookName.isEmpty() || writer.isEmpty() ||
            publisher.isEmpty() || takeMethod.isEmpty() || QString("%1").arg(textPrice)<=0){
        QMessageBox::warning(NULL,"error","存在未填信息.(也可能是书本价格为0)");
        return ;
    }


    int pos=0;
    QValidator::State res;

    //正则匹配ISBN信息
    QRegExp isbnFormula("^978-7-[0-9]{2,6}-[0-9]{2,6}-[0-9]$");
    QRegExpValidator isbnCheck(isbnFormula,0);
    pos=0;
    res=isbnCheck.validate(isbn,pos);
    if(QValidator::Acceptable==res){
    }
    else{
        QMessageBox::warning(NULL,"error","isbn值必须形如“978-7-04-051102-4”\n"
                                          "中国的ISBN编号共13位,978为固定,其他十位,"
                                          "第一位为中国的标识7,之后是标识出版社的2-6位数字,"
                                          "之后是出版社内刊物的流水,最后一位是校验位0-9或X");
        return ;
    }

    //正则匹配书籍价格信息
    QRegExp priceFormula("\\d+\\.\\d+|(\\d+)");
    QRegExpValidator priceCheck(priceFormula,0);
    res=priceCheck.validate(textPrice,pos);
    if(QValidator::Acceptable==res){
        qDebug()<<1;
    }
    else{
        QMessageBox::warning(NULL,"error","书本价格必须是大于0的数值");
        return ;
    }

    float price=this->ui->priceEdit->text().toFloat();

    Account* account=Account::get_account();

    Book book(0,isbn,bookName,writer,publisher,account->get_id(),price,takeMethod,status,selled);
    emit book_insert_confirm(book);
}
