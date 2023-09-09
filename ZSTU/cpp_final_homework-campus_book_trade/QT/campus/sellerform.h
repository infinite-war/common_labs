#pragma once
#ifndef SELLERFORM_H
#define SELLERFORM_H

#include "all_headers.h"
#include "account.h"
#include "dbmanager.h"
#include "passwordeditform.h"
#include "insertdialog.h"
#include "editdialog.h"
#include "book.h"

namespace Ui {
class SellerForm;
}

class SellerForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit SellerForm(QWidget *parent = nullptr);
    ~SellerForm();

    PasswordEditForm &get_passwordEditForm();
    void set_booksTableView();
    void set_ordersTableView();

private slots:
    //自定义控件事件
    void on_action_log_out_triggered();
    void goto_buyerForm_click();
    void on_actionchange_your_password_triggered();
    void get_my_book_click();
    void search_target_book_click();
    void on_edit_button_clicked();
    void on_insert_button_clicked();
    void on_delete_button_clicked();
    void on_search_sellerOrder_click();

    //接收其他窗口的信号
    void receive_from_buyer();
    void receive_from_edit_confirm(Book book);
    void receive_from_insert_confirm(Book book);

signals:
    void show_buyerForm();
    void show_loginForm();

private:
    Ui::SellerForm *ui;
    PasswordEditForm passwordEditForm;
    QSqlTableModel* model;
    QSqlTableModel* orderModel;
    EditDialog* editDialog;
    InsertDialog* insertDialog;
};

#endif // SELLERFORM_H
