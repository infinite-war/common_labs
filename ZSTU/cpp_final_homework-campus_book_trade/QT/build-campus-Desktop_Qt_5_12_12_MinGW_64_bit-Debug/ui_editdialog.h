/********************************************************************************
** Form generated from reading UI file 'editdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITDIALOG_H
#define UI_EDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EditDialog
{
public:
    QLabel *titleLabel;
    QPushButton *confirmButton;
    QPushButton *cancelButton;
    QLabel *isbnLabel;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *isbnEdit;
    QLineEdit *bookNameEdit;
    QLineEdit *takeMethodEdit;
    QLineEdit *writerEdit;
    QLineEdit *priceEdit;
    QLineEdit *publisherEdit;
    QComboBox *newStatusComboBox;
    QComboBox *sellingStatuscomboBox;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *bookNumberlabel;

    void setupUi(QDialog *EditDialog)
    {
        if (EditDialog->objectName().isEmpty())
            EditDialog->setObjectName(QString::fromUtf8("EditDialog"));
        EditDialog->resize(650, 520);
        titleLabel = new QLabel(EditDialog);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setGeometry(QRect(250, 30, 171, 41));
        confirmButton = new QPushButton(EditDialog);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        confirmButton->setGeometry(QRect(160, 440, 93, 28));
        cancelButton = new QPushButton(EditDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(370, 440, 93, 28));
        isbnLabel = new QLabel(EditDialog);
        isbnLabel->setObjectName(QString::fromUtf8("isbnLabel"));
        isbnLabel->setGeometry(QRect(50, 140, 61, 21));
        label = new QLabel(EditDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 210, 72, 15));
        label_2 = new QLabel(EditDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 280, 72, 15));
        label_3 = new QLabel(EditDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 360, 72, 15));
        label_4 = new QLabel(EditDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(350, 210, 72, 15));
        label_5 = new QLabel(EditDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(380, 140, 72, 15));
        label_6 = new QLabel(EditDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(350, 290, 72, 15));
        label_7 = new QLabel(EditDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(350, 360, 72, 21));
        isbnEdit = new QLineEdit(EditDialog);
        isbnEdit->setObjectName(QString::fromUtf8("isbnEdit"));
        isbnEdit->setGeometry(QRect(130, 130, 171, 31));
        bookNameEdit = new QLineEdit(EditDialog);
        bookNameEdit->setObjectName(QString::fromUtf8("bookNameEdit"));
        bookNameEdit->setGeometry(QRect(130, 200, 171, 31));
        takeMethodEdit = new QLineEdit(EditDialog);
        takeMethodEdit->setObjectName(QString::fromUtf8("takeMethodEdit"));
        takeMethodEdit->setGeometry(QRect(430, 200, 181, 31));
        writerEdit = new QLineEdit(EditDialog);
        writerEdit->setObjectName(QString::fromUtf8("writerEdit"));
        writerEdit->setGeometry(QRect(130, 270, 171, 31));
        priceEdit = new QLineEdit(EditDialog);
        priceEdit->setObjectName(QString::fromUtf8("priceEdit"));
        priceEdit->setGeometry(QRect(430, 130, 181, 31));
        publisherEdit = new QLineEdit(EditDialog);
        publisherEdit->setObjectName(QString::fromUtf8("publisherEdit"));
        publisherEdit->setGeometry(QRect(130, 350, 171, 31));
        newStatusComboBox = new QComboBox(EditDialog);
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
        sellingStatuscomboBox = new QComboBox(EditDialog);
        sellingStatuscomboBox->addItem(QString());
        sellingStatuscomboBox->addItem(QString());
        sellingStatuscomboBox->setObjectName(QString::fromUtf8("sellingStatuscomboBox"));
        sellingStatuscomboBox->setGeometry(QRect(470, 350, 87, 22));
        label_8 = new QLabel(EditDialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(330, 380, 111, 21));
        label_9 = new QLabel(EditDialog);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(330, 310, 111, 21));
        label_10 = new QLabel(EditDialog);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 80, 72, 15));
        bookNumberlabel = new QLabel(EditDialog);
        bookNumberlabel->setObjectName(QString::fromUtf8("bookNumberlabel"));
        bookNumberlabel->setGeometry(QRect(130, 80, 72, 15));

        retranslateUi(EditDialog);
        QObject::connect(cancelButton, SIGNAL(clicked()), EditDialog, SLOT(cancelButton_click()));
        QObject::connect(confirmButton, SIGNAL(clicked()), EditDialog, SLOT(confirmButton_click()));

        QMetaObject::connectSlotsByName(EditDialog);
    } // setupUi

    void retranslateUi(QDialog *EditDialog)
    {
        EditDialog->setWindowTitle(QApplication::translate("EditDialog", "Dialog", nullptr));
        titleLabel->setText(QApplication::translate("EditDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">\344\271\246\347\261\215\344\277\241\346\201\257\344\277\256\346\224\271</span></p></body></html>", nullptr));
        confirmButton->setText(QApplication::translate("EditDialog", "\347\241\256\350\256\244\344\277\256\346\224\271", nullptr));
        cancelButton->setText(QApplication::translate("EditDialog", "\347\273\223\346\235\237\344\277\256\346\224\271", nullptr));
        isbnLabel->setText(QApplication::translate("EditDialog", "ISBN\357\274\232", nullptr));
        label->setText(QApplication::translate("EditDialog", "\344\271\246\345\220\215:", nullptr));
        label_2->setText(QApplication::translate("EditDialog", "\344\275\234\350\200\205\357\274\232", nullptr));
        label_3->setText(QApplication::translate("EditDialog", "\345\207\272\347\211\210\347\244\276\357\274\232", nullptr));
        label_4->setText(QApplication::translate("EditDialog", "\345\217\226\344\271\246\346\226\271\345\274\217\357\274\232", nullptr));
        label_5->setText(QApplication::translate("EditDialog", "\344\273\267\346\240\274\357\274\232", nullptr));
        label_6->setText(QApplication::translate("EditDialog", "\346\226\260\346\227\247\347\250\213\345\272\246\357\274\232", nullptr));
        label_7->setText(QApplication::translate("EditDialog", "\345\234\250\345\224\256\347\212\266\346\200\201\357\274\232", nullptr));
        newStatusComboBox->setItemText(0, QApplication::translate("EditDialog", "1", nullptr));
        newStatusComboBox->setItemText(1, QApplication::translate("EditDialog", "2", nullptr));
        newStatusComboBox->setItemText(2, QApplication::translate("EditDialog", "3", nullptr));
        newStatusComboBox->setItemText(3, QApplication::translate("EditDialog", "4", nullptr));
        newStatusComboBox->setItemText(4, QApplication::translate("EditDialog", "5", nullptr));
        newStatusComboBox->setItemText(5, QApplication::translate("EditDialog", "6", nullptr));
        newStatusComboBox->setItemText(6, QApplication::translate("EditDialog", "7", nullptr));
        newStatusComboBox->setItemText(7, QApplication::translate("EditDialog", "8", nullptr));
        newStatusComboBox->setItemText(8, QApplication::translate("EditDialog", "9", nullptr));
        newStatusComboBox->setItemText(9, QApplication::translate("EditDialog", "10", nullptr));

        sellingStatuscomboBox->setItemText(0, QApplication::translate("EditDialog", "0", nullptr));
        sellingStatuscomboBox->setItemText(1, QApplication::translate("EditDialog", "1", nullptr));

        label_8->setText(QApplication::translate("EditDialog", "(\"0\"\344\273\243\350\241\250\345\234\250\345\224\256)", nullptr));
        label_9->setText(QApplication::translate("EditDialog", "(\"1\"\344\273\243\350\241\250\346\234\200\346\227\247)", nullptr));
        label_10->setText(QApplication::translate("EditDialog", "\344\271\246\347\261\215\347\274\226\345\217\267:", nullptr));
        bookNumberlabel->setText(QApplication::translate("EditDialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditDialog: public Ui_EditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITDIALOG_H
