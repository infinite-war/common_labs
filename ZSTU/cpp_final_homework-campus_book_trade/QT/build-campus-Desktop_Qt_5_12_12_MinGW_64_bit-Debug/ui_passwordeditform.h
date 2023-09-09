/********************************************************************************
** Form generated from reading UI file 'passwordeditform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDEDITFORM_H
#define UI_PASSWORDEDITFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PasswordEditForm
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *originalTextbox;
    QLineEdit *newTextbox;
    QLineEdit *newConfirmTextbox;
    QPushButton *editBotton;
    QPushButton *cancelBotton;

    void setupUi(QWidget *PasswordEditForm)
    {
        if (PasswordEditForm->objectName().isEmpty())
            PasswordEditForm->setObjectName(QString::fromUtf8("PasswordEditForm"));
        PasswordEditForm->resize(716, 503);
        label = new QLabel(PasswordEditForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(270, 60, 181, 61));
        label_2 = new QLabel(PasswordEditForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(170, 170, 81, 21));
        label_3 = new QLabel(PasswordEditForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(170, 240, 81, 21));
        label_4 = new QLabel(PasswordEditForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(160, 310, 91, 21));
        originalTextbox = new QLineEdit(PasswordEditForm);
        originalTextbox->setObjectName(QString::fromUtf8("originalTextbox"));
        originalTextbox->setGeometry(QRect(300, 160, 191, 31));
        newTextbox = new QLineEdit(PasswordEditForm);
        newTextbox->setObjectName(QString::fromUtf8("newTextbox"));
        newTextbox->setGeometry(QRect(300, 230, 191, 31));
        newConfirmTextbox = new QLineEdit(PasswordEditForm);
        newConfirmTextbox->setObjectName(QString::fromUtf8("newConfirmTextbox"));
        newConfirmTextbox->setGeometry(QRect(300, 300, 191, 31));
        editBotton = new QPushButton(PasswordEditForm);
        editBotton->setObjectName(QString::fromUtf8("editBotton"));
        editBotton->setGeometry(QRect(170, 390, 93, 28));
        cancelBotton = new QPushButton(PasswordEditForm);
        cancelBotton->setObjectName(QString::fromUtf8("cancelBotton"));
        cancelBotton->setGeometry(QRect(430, 390, 93, 28));

        retranslateUi(PasswordEditForm);
        QObject::connect(editBotton, SIGNAL(clicked()), PasswordEditForm, SLOT(password_edit_click()));
        QObject::connect(cancelBotton, SIGNAL(clicked()), PasswordEditForm, SLOT(cancel_click()));

        QMetaObject::connectSlotsByName(PasswordEditForm);
    } // setupUi

    void retranslateUi(QWidget *PasswordEditForm)
    {
        PasswordEditForm->setWindowTitle(QApplication::translate("PasswordEditForm", "Form", nullptr));
        label->setText(QApplication::translate("PasswordEditForm", "<html><head/><body><p><span style=\" font-size:18pt;\">\344\277\256\346\224\271\345\257\206\347\240\201\347\225\214\351\235\242</span></p></body></html>", nullptr));
        label_2->setText(QApplication::translate("PasswordEditForm", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\345\216\237\345\257\206\347\240\201:</span></p></body></html>", nullptr));
        label_3->setText(QApplication::translate("PasswordEditForm", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\346\226\260\345\257\206\347\240\201:</span></p></body></html>", nullptr));
        label_4->setText(QApplication::translate("PasswordEditForm", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\347\241\256\350\256\244\345\257\206\347\240\201:</span></p></body></html>", nullptr));
        editBotton->setText(QApplication::translate("PasswordEditForm", "\347\241\256\350\256\244\344\277\256\346\224\271", nullptr));
        cancelBotton->setText(QApplication::translate("PasswordEditForm", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PasswordEditForm: public Ui_PasswordEditForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDEDITFORM_H
