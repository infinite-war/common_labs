#ifndef PURCHASEDIALOG_H
#define PURCHASEDIALOG_H

#include "all_headers.h"
#include "order.h"
#include "account.h"
#include <QDialog>

namespace Ui {
class PurchaseDialog;
}

class PurchaseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PurchaseDialog(QWidget *parent = nullptr);
    ~PurchaseDialog();

    void set_ui(QString sellerName,Book book);

private slots:
    //自定义控件事件
    void confirmButton_click();
    void cancelButton_click();

signals:
    void purchase_confirm(Order order);


private:
    Ui::PurchaseDialog *ui;
    Order* order;
};

#endif // PURCHASEDIALOG_H
