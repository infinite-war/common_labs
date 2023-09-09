#pragma once
#ifndef INSERTDIALOG_H
#define INSERTDIALOG_H

#include "all_headers.h"
#include "book.h"
#include "account.h"
#include <QDialog>


namespace Ui {
class InsertDialog;
}

class InsertDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InsertDialog(QWidget *parent = nullptr);
    ~InsertDialog();

private slots:
    //自定义控件事件
    void cancelButton_click();
    void confirmButton_click();


signals:
    void book_insert_confirm(Book book);


private:
    Ui::InsertDialog *ui;
};

#endif // INSERTDIALOG_H
