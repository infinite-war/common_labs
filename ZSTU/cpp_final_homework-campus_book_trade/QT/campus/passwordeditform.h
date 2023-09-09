#pragma once
#ifndef PASSWORDEDITFORM_H
#define PASSWORDEDITFORM_H

#include "account.h"
#include "dbmanager.h"
#include "order.h"
#include <QWidget>

namespace Ui {
class PasswordEditForm;
}

class PasswordEditForm : public QWidget
{
    Q_OBJECT

public:
    explicit PasswordEditForm(QWidget *parent = nullptr);
    ~PasswordEditForm();
    void clear_lineEdit();

private slots:
    void password_edit_click();
    void cancel_click();

signals:
    void renew_account();

private:
    Ui::PasswordEditForm *ui;
};

#endif // PASSWORDEDITFORM_H
