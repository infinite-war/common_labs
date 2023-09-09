#include "purchasedialog.h"
#include "ui_purchasedialog.h"

PurchaseDialog::PurchaseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PurchaseDialog)
{
    ui->setupUi(this);
}

PurchaseDialog::~PurchaseDialog()
{
    delete ui;
}

/*
函数名：set_ui(QString sellerName, Book book)
功能：设置订单界面内容
*/
void PurchaseDialog::set_ui(QString sellerName, Book book)
{
    this->order=new Order(sellerName,book);
    Account* buyer=Account::get_account();
    Account* seller=this->order->get_seller();
    //设置订单界面内容
    this->ui->buyerNameLabel->setText(buyer->get_id());
    this->ui->buyerPhoneLabel->setText(buyer->get_phone());
    this->ui->buyerAddressLabel->setText(buyer->get_address());
    this->ui->sellerNameLabel->setText(seller->get_id());
    this->ui->sellerPhoneLabel->setText(seller->get_phone());
    this->ui->sellerAddressLabel->setText(seller->get_address());

    this->ui->bookNameLabel->setText(book.get_bookName());
    this->ui->takeMethodLabel->setText(book.get_takeMethod());
    this->ui->priceLabel->setText(QString("%1").arg(book.get_price()));
    this->ui->statusLabel->setText(QString("%1").arg(book.get_status()));
}

//=============================================private slots==========================================
//----------------------------------------------自定义控件事件-----------------------------------------


/*
函数名：confirmButton_click()
功能：确认购买
*/
void PurchaseDialog::confirmButton_click()
{
    emit purchase_confirm(*this->order);
}

/*
函数名：cancelButton_click()
功能：取消购买
*/
void PurchaseDialog::cancelButton_click()
{
    QMessageBox::information(NULL,"revert","订单已取消");
    this->close();
}



