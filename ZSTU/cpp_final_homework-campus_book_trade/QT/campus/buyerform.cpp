#pragma once
#include "buyerform.h"
#include "ui_buyerform.h"

BuyerForm::BuyerForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BuyerForm)
{
    ui->setupUi(this);

    //预设置model
    DbManager* dba=DbManager::get_dba();
    this->model=new QSqlTableModel(this->ui->booksTableView,dba->db);
    this->orderModel=new QSqlTableModel(this->ui->ordersTableView,dba->db);
    //设置为手动提交数据库信息
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    orderModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
}

BuyerForm::~BuyerForm()
{
    delete ui;
}

//获取私有对象
PasswordEditForm &BuyerForm::get_passwordEditForm(){return this->passwordEditForm;}


/*
函数名：set_booksTableView()
功能：设置booksTableView的字段行
*/
void BuyerForm::set_booksTableView()
{
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("ISBN"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("书名"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("作者"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("出版社"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("卖方"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("获取方式"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("价格"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("新旧程度"));
    model->setHeaderData(9,Qt::Horizontal,QObject::tr("售出状态"));
}


/*
函数名：set_ordersTableView()
功能：设置ordersTableView的字段行
*/
void BuyerForm::set_ordersTableView()
{
    orderModel->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    orderModel->setHeaderData(1,Qt::Horizontal,QObject::tr("买方"));
    orderModel->setHeaderData(2,Qt::Horizontal,QObject::tr("买方电话"));
    orderModel->setHeaderData(3,Qt::Horizontal,QObject::tr("买方地址"));
    orderModel->setHeaderData(4,Qt::Horizontal,QObject::tr("卖方"));
    orderModel->setHeaderData(5,Qt::Horizontal,QObject::tr("卖方电话"));
    orderModel->setHeaderData(6,Qt::Horizontal,QObject::tr("卖方地址"));
    orderModel->setHeaderData(7,Qt::Horizontal,QObject::tr("书名"));
    orderModel->setHeaderData(8,Qt::Horizontal,QObject::tr("价格"));
    orderModel->setHeaderData(9,Qt::Horizontal,QObject::tr("购买时间"));

}



//===============================================private slots===================================================

//-----------------------------------------------自定义控件事件---------------------------------------------

/*
函数名：on_action_log_out_triggered()
功能：退出当前用户
*/
void BuyerForm::on_action_log_out_triggered()
{
    this->close();
    emit show_loginForm();
}


/*
函数名：goto_sellerForm_click()
功能：当前用户转到卖方界面
*/
void BuyerForm::goto_sellerForm_click()
{
    this->hide();
    emit show_sellerForm();
}

/*
函数名：on_actionchange_your_password_triggered()
功能：弹出修改密码界面
*/
void BuyerForm::on_actionchange_your_password_triggered()
{
    this->passwordEditForm.clear_lineEdit();
    this->passwordEditForm.show();
}


/*
函数名：search_selling_book_click()
功能：查询所有在售书籍
*/
void BuyerForm::search_selling_book_click()
{
    model->setTable("book");
    Account* account=Account::get_account();

    //筛选条件
    model->setFilter(QString("owner!='%1' and selled=0").arg(account->get_id()));
    model->select();

    //设置表头
    this->set_booksTableView();

    this->ui->booksTableView->setModel(model);
    //table界面设为不可编辑
    this->ui->booksTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    if(model->rowCount()==0){
        QMessageBox::information(NULL,"tip","暂无在售书籍");
    }
}


/*
函数名：search_target_book_click()
功能：按关键字搜索指定书籍
*/
void BuyerForm::search_target_book_click()
{

    QString target=this->ui->searchBookTextbox->text();
    Account* account=Account::get_account();

    //筛选条件
    model->setTable("book");
    model->setFilter(QString("owner!='%1' and bookName like '%"+target+"%' ;").arg(account->get_id()));//.arg(target)); //筛选条件
    model->select();

    this->set_booksTableView();

    this->ui->booksTableView->setModel(model);
    //table界面设为不可编辑
    this->ui->booksTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    if(model->rowCount()==0){
        QMessageBox::information(NULL,"tip","没有相关在售书籍");
    }
}



/*
函数名：on_purchase_button_click()
功能：打开买书界面
*/
void BuyerForm::on_purchase_button_click()
{
    int curRow=this->ui->booksTableView->currentIndex().row();
    //判断用户是否有选中一条记录，-1代表未选择记录
    if(curRow==-1){
        QMessageBox::warning(NULL,"error","请选择一条书籍记录");
        return ;
    }

    //与购买对话框建立连接
    this->purchaseDialog=new PurchaseDialog(this);
    QObject::connect(purchaseDialog,SIGNAL(purchase_confirm(Order)),this,SLOT(receive_from_purchaseDialog(Order)));

    //获取选中的记录
    QSqlRecord record=this->model->record(curRow);

    //书籍基本信息
    int id=record.value(0).toInt();
    QString isbn=record.value(1).toString();
    QString bookName=record.value(2).toString();
    QString writer=record.value(3).toString();
    QString publisher=record.value(4).toString();
    QString sellerName=record.value(5).toString();
    QString takeMethod=record.value(6).toString();
    float price=record.value(7).toFloat();
    int status=record.value(8).toInt();
    int selled=record.value(9).toInt();
    qDebug()<<price<<status<<selled;
    Account* account=Account::get_account();

    Book book(id,isbn,bookName,writer,publisher,account->get_id(),price,takeMethod,status,selled);

    //设置购买对话框的内容
    this->purchaseDialog->set_ui(sellerName,book);
    this->purchaseDialog->show();
}


/*
函数名：on_search_buyerOrder_click()
功能：查询当前账号作为买方的订单
*/
void BuyerForm::on_search_buyerOrder_click()
{
    orderModel->setTable("detailorder");
    Account* account=Account::get_account();
    //筛选条件
    orderModel->setFilter(QString("buyerName='%1'").arg(account->get_id()));
    orderModel->select();

    //设置订单栏的表头
    this->set_ordersTableView();

    this->ui->ordersTableView->setModel(orderModel);
    this->ui->ordersTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->ui->orderNumsLabel->setText(QString("订单总数：%1").arg(orderModel->rowCount()));
    if(orderModel->rowCount()==0){
        QMessageBox::information(NULL,"tip","该用户暂无购入订单");
    }
}



//------------------------------------------接收其他窗口的信号--------------------------------------------

/*
函数名：receive_from_login()
功能：完成登录事件后进入买方界面，并清空买方界面中tableview的内容
*/
void BuyerForm::receive_from_login()
{
    //清空两个tableview的内容
    QSqlQueryModel* res=new QSqlQueryModel(this->ui->booksTableView);
    res->clear();
    this->ui->booksTableView->setModel(res);
    this->ui->ordersTableView->setModel(res);

    Account* account=Account::get_account();
    this->ui->userNameLabel->setText(QString("用户：%1").arg(account->get_id()));
    this->ui->orderNumsLabel->setText(QString("订单总数："));
    this->show();
}

/*
函数名：receive_from_seller()
功能：从卖方界面切换到买方界面，并清空买方界面中tableview的内容
*/
void BuyerForm::receive_from_seller()
{
    //清空两个tableview的内容
    QSqlQueryModel* res=new QSqlQueryModel(this->ui->booksTableView);
    res->clear();
    this->ui->booksTableView->setModel(res);
    this->ui->ordersTableView->setModel(res);
    this->ui->orderNumsLabel->setText(QString("订单总数："));
    this->show();
}


/*
函数名：receive_from_purchaseDialog()
功能：完成购买流程
*/
void BuyerForm::receive_from_purchaseDialog(Order order)
{
    orderModel->setTable("bookorder");
    orderModel->select();

    //设置订单记录
    QSqlRecord record=orderModel->record();
    Account* account=Account::get_account();
    record.setValue(1,account->get_id());
    record.setValue(2,order.get_seller()->get_id());
    record.setValue(3,order.get_book()->get_bookName());
    record.setValue(4,QString("%1").arg(order.get_book()->get_price()));
    record.setValue(5,order.get_time());

    if(orderModel->insertRecord(orderModel->rowCount(),record)){
        QMessageBox::information(NULL,"success","购买成功!");

        //修改书籍拥有者，并将书籍售出状态设置为1(已售出)
        int curRow=this->ui->booksTableView->currentIndex().row();
        QSqlRecord purchasedBook=model->record(curRow);
        purchasedBook.setValue(5,account->get_id());
        purchasedBook.setValue(9,1);
        model->setRecord(curRow,purchasedBook);

        //提交所有修改信息
        model->submitAll();
        orderModel->submitAll();
        this->purchaseDialog->close();
        this->on_search_buyerOrder_click();
    }
    else{
        QMessageBox::warning(NULL,"error","购买失败。");
        this->purchaseDialog->close();
    }
}
