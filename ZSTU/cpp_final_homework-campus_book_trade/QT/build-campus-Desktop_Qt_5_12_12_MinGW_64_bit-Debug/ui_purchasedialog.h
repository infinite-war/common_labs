/********************************************************************************
** Form generated from reading UI file 'purchasedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PURCHASEDIALOG_H
#define UI_PURCHASEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PurchaseDialog
{
public:
    QLabel *label_6;
    QLabel *label_5;
    QLabel *titleLabel;
    QPushButton *cancelButton;
    QLabel *label_9;
    QLabel *label_4;
    QLabel *label;
    QPushButton *confirmButton;
    QLabel *label_2;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *buyerNameLabel;
    QLabel *buyerPhoneLabel;
    QLabel *buyerAddressLabel;
    QLabel *priceLabel;
    QLabel *statusLabel;
    QLabel *sellerPhoneLabel;
    QLabel *sellerNameLabel;
    QLabel *sellerAddressLabel;
    QLabel *takeMethodLabel;
    QLabel *bookNameLabel;

    void setupUi(QDialog *PurchaseDialog)
    {
        if (PurchaseDialog->objectName().isEmpty())
            PurchaseDialog->setObjectName(QString::fromUtf8("PurchaseDialog"));
        PurchaseDialog->resize(800, 600);
        label_6 = new QLabel(PurchaseDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(470, 384, 72, 21));
        label_5 = new QLabel(PurchaseDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(100, 420, 72, 15));
        titleLabel = new QLabel(PurchaseDialog);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setGeometry(QRect(300, 40, 171, 41));
        cancelButton = new QPushButton(PurchaseDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(450, 500, 93, 28));
        label_9 = new QLabel(PurchaseDialog);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(450, 410, 111, 21));
        label_4 = new QLabel(PurchaseDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(70, 370, 72, 15));
        label = new QLabel(PurchaseDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 320, 72, 15));
        confirmButton = new QPushButton(PurchaseDialog);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        confirmButton->setGeometry(QRect(240, 500, 93, 28));
        label_2 = new QLabel(PurchaseDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 140, 81, 21));
        label_10 = new QLabel(PurchaseDialog);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(470, 140, 72, 15));
        label_11 = new QLabel(PurchaseDialog);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(60, 180, 81, 21));
        label_12 = new QLabel(PurchaseDialog);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(90, 220, 81, 21));
        label_13 = new QLabel(PurchaseDialog);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(440, 180, 81, 21));
        label_14 = new QLabel(PurchaseDialog);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(470, 220, 81, 21));
        buyerNameLabel = new QLabel(PurchaseDialog);
        buyerNameLabel->setObjectName(QString::fromUtf8("buyerNameLabel"));
        buyerNameLabel->setGeometry(QRect(160, 140, 151, 16));
        buyerPhoneLabel = new QLabel(PurchaseDialog);
        buyerPhoneLabel->setObjectName(QString::fromUtf8("buyerPhoneLabel"));
        buyerPhoneLabel->setGeometry(QRect(160, 180, 281, 16));
        buyerAddressLabel = new QLabel(PurchaseDialog);
        buyerAddressLabel->setObjectName(QString::fromUtf8("buyerAddressLabel"));
        buyerAddressLabel->setGeometry(QRect(160, 220, 181, 16));
        priceLabel = new QLabel(PurchaseDialog);
        priceLabel->setObjectName(QString::fromUtf8("priceLabel"));
        priceLabel->setGeometry(QRect(170, 420, 201, 16));
        statusLabel = new QLabel(PurchaseDialog);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setGeometry(QRect(570, 390, 72, 15));
        sellerPhoneLabel = new QLabel(PurchaseDialog);
        sellerPhoneLabel->setObjectName(QString::fromUtf8("sellerPhoneLabel"));
        sellerPhoneLabel->setGeometry(QRect(540, 180, 181, 16));
        sellerNameLabel = new QLabel(PurchaseDialog);
        sellerNameLabel->setObjectName(QString::fromUtf8("sellerNameLabel"));
        sellerNameLabel->setGeometry(QRect(540, 140, 181, 16));
        sellerAddressLabel = new QLabel(PurchaseDialog);
        sellerAddressLabel->setObjectName(QString::fromUtf8("sellerAddressLabel"));
        sellerAddressLabel->setGeometry(QRect(540, 220, 181, 16));
        takeMethodLabel = new QLabel(PurchaseDialog);
        takeMethodLabel->setObjectName(QString::fromUtf8("takeMethodLabel"));
        takeMethodLabel->setGeometry(QRect(170, 370, 311, 16));
        bookNameLabel = new QLabel(PurchaseDialog);
        bookNameLabel->setObjectName(QString::fromUtf8("bookNameLabel"));
        bookNameLabel->setGeometry(QRect(170, 320, 441, 16));

        retranslateUi(PurchaseDialog);
        QObject::connect(confirmButton, SIGNAL(clicked()), PurchaseDialog, SLOT(confirmButton_click()));
        QObject::connect(cancelButton, SIGNAL(clicked()), PurchaseDialog, SLOT(cancelButton_click()));

        QMetaObject::connectSlotsByName(PurchaseDialog);
    } // setupUi

    void retranslateUi(QDialog *PurchaseDialog)
    {
        PurchaseDialog->setWindowTitle(QApplication::translate("PurchaseDialog", "Dialog", nullptr));
        label_6->setText(QApplication::translate("PurchaseDialog", "\346\226\260\346\227\247\347\250\213\345\272\246\357\274\232", nullptr));
        label_5->setText(QApplication::translate("PurchaseDialog", "\344\273\267\346\240\274\357\274\232", nullptr));
        titleLabel->setText(QApplication::translate("PurchaseDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">\350\256\242\345\215\225\344\277\241\346\201\257</span></p></body></html>", nullptr));
        cancelButton->setText(QApplication::translate("PurchaseDialog", "\345\217\226\346\266\210\350\264\255\344\271\260", nullptr));
        label_9->setText(QApplication::translate("PurchaseDialog", "(\"1\"\344\273\243\350\241\250\346\234\200\346\227\247)", nullptr));
        label_4->setText(QApplication::translate("PurchaseDialog", "\345\217\226\344\271\246\346\226\271\345\274\217\357\274\232", nullptr));
        label->setText(QApplication::translate("PurchaseDialog", "\344\271\246\345\220\215:", nullptr));
        confirmButton->setText(QApplication::translate("PurchaseDialog", "\347\241\256\350\256\244\350\264\255\344\271\260", nullptr));
        label_2->setText(QApplication::translate("PurchaseDialog", "\344\271\260\346\226\271\357\274\232", nullptr));
        label_10->setText(QApplication::translate("PurchaseDialog", "\345\215\226\346\226\271\357\274\232", nullptr));
        label_11->setText(QApplication::translate("PurchaseDialog", "\350\201\224\347\263\273\347\224\265\350\257\235\357\274\232", nullptr));
        label_12->setText(QApplication::translate("PurchaseDialog", "\345\234\260\345\235\200\357\274\232", nullptr));
        label_13->setText(QApplication::translate("PurchaseDialog", "\350\201\224\347\263\273\347\224\265\350\257\235\357\274\232", nullptr));
        label_14->setText(QApplication::translate("PurchaseDialog", "\345\234\260\345\235\200\357\274\232", nullptr));
        buyerNameLabel->setText(QApplication::translate("PurchaseDialog", "TextLabel", nullptr));
        buyerPhoneLabel->setText(QApplication::translate("PurchaseDialog", "TextLabel", nullptr));
        buyerAddressLabel->setText(QApplication::translate("PurchaseDialog", "TextLabel", nullptr));
        priceLabel->setText(QApplication::translate("PurchaseDialog", "TextLabel", nullptr));
        statusLabel->setText(QApplication::translate("PurchaseDialog", "TextLabel", nullptr));
        sellerPhoneLabel->setText(QApplication::translate("PurchaseDialog", "TextLabel", nullptr));
        sellerNameLabel->setText(QApplication::translate("PurchaseDialog", "TextLabel", nullptr));
        sellerAddressLabel->setText(QApplication::translate("PurchaseDialog", "TextLabel", nullptr));
        takeMethodLabel->setText(QApplication::translate("PurchaseDialog", "TextLabel", nullptr));
        bookNameLabel->setText(QApplication::translate("PurchaseDialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PurchaseDialog: public Ui_PurchaseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PURCHASEDIALOG_H
