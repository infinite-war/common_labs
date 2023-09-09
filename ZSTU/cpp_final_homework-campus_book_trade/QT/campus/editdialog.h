#pragma once
#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include "all_headers.h"
#include "book.h"
#include "account.h"
#include <QDialog>

namespace Ui {
class EditDialog;
}

class EditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditDialog(QWidget *parent = nullptr);
    ~EditDialog();

    void set_ui(Book book);

private slots:
    //自定义控件事件
    void cancelButton_click();
    void confirmButton_click();


signals:
    void book_edit_confirm(Book book);

private:
    Ui::EditDialog *ui;
};

#endif // EDITDIALOG_H
