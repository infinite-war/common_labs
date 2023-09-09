/********************************************************************************
** Form generated from reading UI file 'insertdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTDIALOG_H
#define UI_INSERTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_InsertDialog
{
public:
    QLineEdit *takeMethodEdit;
    QPushButton *cancelButton;
    QLabel *label;
    QComboBox *newStatusComboBox;
    QLabel *label_2;
    QPushButton *confirmButton;
    QLabel *label_7;
    QLabel *label_4;
    QLineEdit *bookNameEdit;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *isbnLabel;
    QComboBox *sellingStatuscomboBox;
    QLineEdit *priceEdit;
    QLineEdit *writerEdit;
    QLabel *label_9;
    QLineEdit *isbnEdit;
    QLineEdit *publisherEdit;
    QLabel *label_3;
    QLabel *label_8;
    QLabel *titleLabel;

    void setupUi(QDialog *InsertDialog)
    {
        if (InsertDialog->objectName().isEmpty())
            InsertDialog->setObjectName(QString::fromUtf8("InsertDialog"));
        InsertDialog->resize(650, 520);
        takeMethodEdit = new QLineEdit(InsertDialog);
        takeMethodEdit->setObjectName(QString::fromUtf8("takeMethodEdit"));
        takeMethodEdit->setGeometry(QRect(430, 200, 181, 31));
        cancelButton = new QPushButton(InsertDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(370, 440, 93, 28));
        label = new QLabel(InsertDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 210, 72, 15));
        newStatusComboBox = new QComboBox(InsertDialog);
        newStatusComboBox->addItem(QString());
        newStatusComboBox->addItem(QString());
        newStatusComboBox->addItem(QString());
        newStatusComboBox->addItem(QString());
        newStatusComboBox->addItem(QString());
        newStatusComboBox->addItem(QString());
        newStatusComboBox->addItem(QString());
        newStatusComboBox->addItem(QString());
        newStatusComboBox->addItem(QString());
        newStatusComboBox->addItem(QString());
        newStatusComboBox->setObjectName(QString::fromUtf8("newStatusComboBox"));
        newStatusComboBox->setGeometry(QRect(470, 290, 91, 22));
        label_2 = new QLabel(InsertDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 280, 72, 15));
        confirmButton = new QPushButton(InsertDialog);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        confirmButton->setGeometry(QRect(160, 440, 93, 28));
        label_7 = new QLabel(InsertDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(350, 360, 72, 21));
        label_4 = new QLabel(InsertDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(350, 210, 72, 15));
        bookNameEdit = new QLineEdit(InsertDialog);
        bookNameEdit->setObjectName(QString::fromUtf8("bookNameEdit"));
        bookNameEdit->setGeometry(QRect(130, 200, 171, 31));
        label_5 = new QLabel(InsertDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(380, 140, 72, 15));
        label_6 = new QLabel(InsertDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(350, 290, 72, 15));
        isbnLabel = new QLabel(InsertDialog);
        isbnLabel->setObjectName(QString::fromUtf8("isbnLabel"));
        isbnLabel->setGeometry(QRect(50, 140, 61, 21));
        sellingStatuscomboBox = new QComboBox(InsertDialog);
        sellingStatuscomboBox->addItem(QString());
        sellingStatuscomboBox->addItem(QString());
        sellingStatuscomboBox->setObjectName(QString::fromUtf8("sellingStatuscomboBox"));
        sellingStatuscomboBox->setGeometry(QRect(470, 350, 87, 22));
        priceEdit = new QLineEdit(InsertDialog);
        priceEdit->setObjectName(QString::fromUtf8("priceEdit"));
        priceEdit->setGeometry(QRect(430, 130, 181, 31));
        writerEdit = new QLineEdit(InsertDialog);
        writerEdit->setObjectName(QString::fromUtf8("writerEdit"));
        writerEdit->setGeometry(QRect(130, 270, 171, 31));
        label_9 = new QLabel(InsertDialog);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(330, 310, 111, 21));
        isbnEdit = new QLineEdit(InsertDialog);
        isbnEdit->setObjectName(QString::fromUtf8("isbnEdit"));
        isbnEdit->setGeometry(QRect(130, 130, 171, 31));
        publisherEdit = new QLineEdit(InsertDialog);
        publisherEdit->setObjectName(QString::fromUtf8("publisherEdit"));
        publisherEdit->setGeometry(QRect(130, 350, 171, 31));
        label_3 = new QLabel(InsertDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 360, 72, 15));
        label_8 = new QLabel(InsertDialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(330, 380, 111, 21));
        titleLabel = new QLabel(InsertDialog);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setGeometry(QRect(250, 30, 171, 41));

        retranslateUi(InsertDialog);
        QObject::connect(cancelButton, SIGNAL(clicked()), InsertDialog, SLOT(cancelButton_click()));
        QObject::connect(confirmButton, SIGNAL(clicked()), InsertDialog, SLOT(confirmButton_click()));

        QMetaObject::connectSlotsByName(InsertDialog);
    } // setupUi

    void retranslateUi(QDialog *InsertDialog)
    {
        InsertDialog->setWindowTitle(QApplication::translate("InsertDialog", "Dialog", nullptr));
        cancelButton->setText(QApplication::translate("InsertDialog", "\345\217\226\346\266\210\346\267\273\345\212\240", nullptr));
        label->setText(QApplication::translate("InsertDialog", "\344\271\246\345\220\215:", nullptr));
        newStatusComboBox->setItemText(0, QApplication::translate("InsertDialog", "10", nullptr));
        newStatusComboBox->setItemText(1, QApplication::translate("InsertDialog", "9", nullptr));
        newStatusComboBox->setItemText(2, QApplication::translate("InsertDialog", "8", nullptr));
        newStatusComboBox->setItemText(3, QApplication::translate("InsertDialog", "7", nullptr));
        newStatusComboBox->setItemText(4, QApplication::translate("InsertDialog", "6", nullptr));
        newStatusComboBox->setItemText(5, QApplication::translate("InsertDialog", "5", nullptr));
        newStatusComboBox->setItemText(6, QApplication::translate("InsertDialog", "4", nullptr));
        newStatusComboBox->setItemText(7, QApplication::translate("InsertDialog", "3", nullptr));
        newStatusComboBox->setItemText(8, QApplication::translate("InsertDialog", "2", nullptr));
        newStatusComboBox->setItemText(9, QApplication::translate("InsertDialog", "1", nullptr));

        label_2->setText(QApplication::translate("InsertDialog", "\344\275\234\350\200\205\357\274\232", nullptr));
        confirmButton->setText(QApplication::translate("InsertDialog", "\347\241\256\350\256\244\346\267\273\345\212\240", nullptr));
        label_7->setText(QApplication::translate("InsertDialog", "\345\234\250\345\224\256\347\212\266\346\200\201\357\274\232", nullptr));
        label_4->setText(QApplication::translate("InsertDialog", "\345\217\226\344\271\246\346\226\271\345\274\217\357\274\232", nullptr));
        label_5->setText(QApplication::translate("InsertDialog", "\344\273\267\346\240\274\357\274\232", nullptr));
        label_6->setText(QApplication::translate("InsertDialog", "\346\226\260\346\227\247\347\250\213\345\272\246\357\274\232", nullptr));
        isbnLabel->setText(QApplication::translate("InsertDialog", "ISBN\357\274\232", nullptr));
        sellingStatuscomboBox->setItemText(0, QApplication::translate("InsertDialog", "0", nullptr));
        sellingStatuscomboBox->setItemText(1, QApplication::translate("InsertDialog", "1", nullptr));

        label_9->setText(QApplication::translate("InsertDialog", "(\"1\"\344\273\243\350\241\250\346\234\200\346\227\247)", nullptr));
        label_3->setText(QApplication::translate("InsertDialog", "\345\207\272\347\211\210\347\244\276\357\274\232", nullptr));
        label_8->setText(QApplication::translate("InsertDialog", "(\"0\"\344\273\243\350\241\250\345\234\250\345\224\256)", nullptr));
        titleLabel->setText(QApplication::translate("InsertDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">\346\267\273\345\212\240\344\271\246\347\261\215</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InsertDialog: public Ui_InsertDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTDIALOG_H
