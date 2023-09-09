#pragma once
#ifndef BUYERFORM_H
#define BUYERFORM_H

#include "all_headers.h"
#include "account.h"
#include "sellerform.h"
#include "dbmanager.h"
#include "passwordeditform.h"
#include "purchasedialog.h"

namespace Ui {
class BuyerForm;
}

class BuyerForm : public QMainWindow
{
    Q_OBJECT

public:
    //公用方法
    explicit BuyerForm(QWidget *parent = nullptr);
    ~BuyerForm();

    //Account& get_account();
    PasswordEditForm& get_passwordEditForm();
    void set_booksTableView();
    void set_ordersTableView();

private slots:
    //自定义控件事件
    void on_action_log_out_triggered();
    void goto_sellerForm_click();
    void on_actionchange_your_password_triggered();
    void search_selling_book_click();
    void search_target_book_click();
    void on_purchase_button_click();
    void on_search_buyerOrder_click();


    //接收其他窗口的信号
    void receive_from_login();
    void receive_from_seller();
    void receive_from_purchaseDialog(Order order);


signals:
    void show_loginForm();
    void show_sellerForm();

private:
    Ui::BuyerForm *ui;
    PasswordEditForm passwordEditForm;
    QSqlTableModel* model;
    QSqlTableModel* orderModel;
    PurchaseDialog* purchaseDialog;

};

#endif // BUYERFORM_H
