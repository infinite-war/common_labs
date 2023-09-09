#pragma once
#include "sellerform.h"
#include "ui_sellerform.h"

SellerForm::SellerForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SellerForm)
{
    ui->setupUi(this);

    //预设置model
    DbManager* dba=DbManager::get_dba();
    model=new QSqlTableModel(this->ui->booksTableView,dba->db);
    this->orderModel=new QSqlTableModel(this->ui->ordersTableView,dba->db);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    orderModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
}

SellerForm::~SellerForm()
{
    delete ui;
}

//获取私有对象
PasswordEditForm &SellerForm::get_passwordEditForm(){return this->passwordEditForm;}



/*
函数名：set_booksTableView()
功能：设置booksTableView的字段行
*/
void SellerForm::set_booksTableView()
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
void SellerForm::set_ordersTableView()
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




//=========================================private slots================================================
//-----------------------------------------自定义控件事件--------------------------------------------------------

/*
函数名：on_action_log_out_triggered()
功能：退出当前账号
*/
void SellerForm::on_action_log_out_triggered()
{
    this->close();
    emit show_loginForm();
}


/*
函数名：goto_buyerForm_click()
功能：切换到买方界面
*/
void SellerForm::goto_buyerForm_click()
{
    this->close();
    emit show_buyerForm();
}


/*
函数名：on_actionchange_your_password_triggered()
功能：弹出修改密码界面
*/
void SellerForm::on_actionchange_your_password_triggered()
{
    this->passwordEditForm.clear_lineEdit();
    this->passwordEditForm.show();
}


/*
函数名：get_my_book_click()
功能：查询自己的书
*/
void SellerForm::get_my_book_click()
{
    model->setTable("book");
    Account* account=Account::get_account();

    //筛选条件
    model->setFilter(QString("owner='%1'").arg(account->get_id()));
    model->select();

    //设置书籍栏的表头
    this->set_booksTableView();

    this->ui->booksTableView->setModel(model);
    this->ui->booksTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);   //table界面设为不可编辑
    if(model->rowCount()==0){
        QMessageBox::information(NULL,"tip","你的书库为空");
    }
}


/*
函数名：search_target_book_click()
功能：搜索指定书籍
*/
void SellerForm::search_target_book_click()
{

    QString target=this->ui->searchBookTextbox->text();
    Account* account=Account::get_account();
    model->setTable("book");

    //筛选条件
    model->setFilter(QString("owner='%1' and bookName like '%"+target+"%' ;").arg(account->get_id())); //筛选条件
    model->select();

    //设置书籍栏表头
    this->set_booksTableView();
    this->ui->booksTableView->setModel(model);

    if(model->rowCount()==0){
        QMessageBox::information(NULL,"tip","你的书库没有相关书籍");
    }
}


/*
函数名：on_edit_botton_clicked()
功能：修改书籍信息，显示书籍信息编辑界面
*/
void SellerForm::on_edit_button_clicked()
{
    int curRow=this->ui->booksTableView->currentIndex().row();
    if(curRow==-1){
        QMessageBox::warning(NULL,"error","请选择一条书籍记录");
        return ;
    }
    QSqlRecord record=this->model->record(curRow);

    //建立卖书界面和书籍编辑界面的连接
    this->editDialog=new EditDialog(this);
    QObject::connect(editDialog,SIGNAL(book_edit_confirm(Book)),this,SLOT(receive_from_edit_confirm(Book)));


    //书籍基本信息
    int id=record.value(0).toInt();
    QString isbn=record.value(1).toString();
    QString bookName=record.value(2).toString();
    QString writer=record.value(3).toString();
    QString publisher=record.value(4).toString();
    float price=record.value(7).toFloat();
    QString takeMethod=record.value(6).toString();
    int status=record.value(8).toInt();
    int selled=record.value(9).toInt();
    qDebug()<<price<<status<<selled;
    Account* account=Account::get_account();


    Book book(id,isbn,bookName,writer,publisher,account->get_id(),price,takeMethod,status,selled);


    //设置书籍编辑界面的基本信息
    this->editDialog->set_ui(book);
    this->editDialog->show();
}


/*
函数名：on_insert_botton_clicked()
功能：添加一本书，显示书籍信息添加界面
*/
void SellerForm::on_insert_button_clicked()
{
    //建立卖书界面和添加书籍界面的连接
    this->insertDialog=new InsertDialog(this);
    QObject::connect(insertDialog,SIGNAL(book_insert_confirm(Book)),this,SLOT(receive_from_insert_confirm(Book)));
    this->insertDialog->show();
}

/*
函数名：on_delete_botton_clicked()
功能：删除选中的一本书
*/
void SellerForm::on_delete_button_clicked()
{
    int curRow=this->ui->booksTableView->currentIndex().row();
    if(curRow==-1){
        QMessageBox::warning(NULL,"error","请选择一条书籍记录");
        return ;
    }

    this->model->removeRow(curRow);

    //确认删除
    int ok=QMessageBox::warning(this,"删除当前行","确定删除这本书的记录吗？",
                                 QMessageBox::Yes,QMessageBox::No);
    if(ok==QMessageBox::No){
        this->model->revertAll();
        QMessageBox::information(NULL,"revert","已取消");
        return ;
    }
    else{
        this->model->submitAll();
        QMessageBox::information(NULL,"success","相关书本已删除");
    }
}


/*
函数名：on_search_sellerOrder_click()
功能：查询当前账号作为卖方的订单
*/
void SellerForm::on_search_sellerOrder_click()
{
    orderModel->setTable("detailorder");
    Account* account=Account::get_account();

    //筛选条件
    orderModel->setFilter(QString("sellerName='%1'").arg(account->get_id()));
    orderModel->select();

    //设置订单栏表头
    this->set_ordersTableView();

    this->ui->ordersTableView->setModel(orderModel);
    this->ui->ordersTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->ui->orderNumsLabel->setText(QString("订单总数：%1").arg(orderModel->rowCount()));
    if(orderModel->rowCount()==0){
        QMessageBox::information(NULL,"tip","该用户暂无售出订单");
    }
}



//----------------------------------------------接收其他窗口的信号-----------------------------------------

/*
函数名：receive_from_buyer()
功能：接收从买方界面切换到卖方界面发出的信号，并清空卖方界面中tableview的所有内容
*/
void SellerForm::receive_from_buyer()
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
函数名：receive_from_edit_confirm(Book book)
功能：接收从修改书籍界面传来的书籍对象信号，并更新数据库
*/
void SellerForm::receive_from_edit_confirm(Book book)
{
    //设置待更新的书籍记录
    int curRow=this->ui->booksTableView->currentIndex().row();
    QSqlRecord record=this->model->record(curRow);
    record.setValue(1,book.get_isbn());
    record.setValue(2,book.get_bookName());
    record.setValue(3,book.get_writer());
    record.setValue(4,book.get_publisher());
    record.setValue(6,book.get_takeMethod());
    record.setValue(7,QString("%1").arg(book.get_price()));
    record.setValue(8,book.get_status());
    record.setValue(9,book.get_selled());


    //提交要更新的记录
    if(model->setRecord(curRow,record)){
        model->submitAll();
        QMessageBox::information(NULL,"success","记录修改成功");
        this->editDialog->close();
    }
    else{
        QMessageBox::warning(NULL,"error","书籍信息修改失败");
    }
}


/*
函数名：receive_from_insert_confirm(Book book)
功能：接收从添加书籍界面传来的书籍对象信号，并插入数据库
*/
void SellerForm::receive_from_insert_confirm(Book book)
{
    //设置要插入的记录
    QSqlRecord record=model->record();

    record.setValue(1,book.get_isbn());
    record.setValue(2,book.get_bookName());
    record.setValue(3,book.get_writer());
    record.setValue(4,book.get_publisher());
    record.setValue(5,book.get_owner());
    record.setValue(6,book.get_takeMethod());
    record.setValue(7,QString("%1").arg(book.get_price()));
    record.setValue(8,book.get_status());
    record.setValue(9,book.get_selled());

    //插入记录
    if(model->insertRecord(model->rowCount(),record)){
        QMessageBox::information(NULL,"success","书本添加成功");
        model->submitAll();
        this->insertDialog->close();
    }
    else{
        QMessageBox::warning(NULL,"error","书本添加失败");
    }

}

