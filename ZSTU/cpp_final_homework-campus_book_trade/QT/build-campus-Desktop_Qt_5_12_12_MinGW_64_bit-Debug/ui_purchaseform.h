/********************************************************************************
** Form generated from reading UI file 'purchaseform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PURCHASEFORM_H
#define UI_PURCHASEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PurchaseForm
{
public:

    void setupUi(QWidget *PurchaseForm)
    {
        if (PurchaseForm->objectName().isEmpty())
            PurchaseForm->setObjectName(QString::fromUtf8("PurchaseForm"));
        PurchaseForm->resize(400, 300);

        retranslateUi(PurchaseForm);

        QMetaObject::connectSlotsByName(PurchaseForm);
    } // setupUi

    void retranslateUi(QWidget *PurchaseForm)
    {
        PurchaseForm->setWindowTitle(QApplication::translate("PurchaseForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PurchaseForm: public Ui_PurchaseForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PURCHASEFORM_H
