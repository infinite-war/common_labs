/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *userNameTextbox;
    QLineEdit *passwordTextbox;
    QLineEdit *phoneTextbox;
    QLineEdit *addressTextbox;
    QPushButton *registerButton;
    QPushButton *cancelButton;

    void setupUi(QWidget *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QString::fromUtf8("Register"));
        Register->resize(809, 589);
        label = new QLabel(Register);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(320, 60, 161, 51));
        label_3 = new QLabel(Register);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(220, 160, 71, 21));
        label_4 = new QLabel(Register);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(240, 240, 71, 21));
        label_5 = new QLabel(Register);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(200, 310, 101, 31));
        label_6 = new QLabel(Register);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(200, 390, 101, 31));
        userNameTextbox = new QLineEdit(Register);
        userNameTextbox->setObjectName(QString::fromUtf8("userNameTextbox"));
        userNameTextbox->setGeometry(QRect(340, 150, 171, 31));
        passwordTextbox = new QLineEdit(Register);
        passwordTextbox->setObjectName(QString::fromUtf8("passwordTextbox"));
        passwordTextbox->setGeometry(QRect(340, 230, 171, 31));
        phoneTextbox = new QLineEdit(Register);
        phoneTextbox->setObjectName(QString::fromUtf8("phoneTextbox"));
        phoneTextbox->setGeometry(QRect(340, 310, 171, 31));
        addressTextbox = new QLineEdit(Register);
        addressTextbox->setObjectName(QString::fromUtf8("addressTextbox"));
        addressTextbox->setGeometry(QRect(340, 390, 341, 31));
        registerButton = new QPushButton(Register);
        registerButton->setObjectName(QString::fromUtf8("registerButton"));
        registerButton->setGeometry(QRect(250, 470, 93, 28));
        cancelButton = new QPushButton(Register);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(470, 470, 93, 28));

        retranslateUi(Register);
        QObject::connect(registerButton, SIGNAL(clicked()), Register, SLOT(register_button_click()));
        QObject::connect(cancelButton, SIGNAL(clicked()), Register, SLOT(cancel_button_click()));

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QWidget *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Form", nullptr));
        label->setText(QApplication::translate("Register", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt;\">\346\263\250\345\206\214\347\225\214\351\235\242</span></p></body></html>", nullptr));
        label_3->setText(QApplication::translate("Register", "<html><head/><body><p><span style=\" font-size:12pt;\">\347\224\250\346\210\267\345\220\215\357\274\232</span></p></body></html>", nullptr));
        label_4->setText(QApplication::translate("Register", "<html><head/><body><p><span style=\" font-size:12pt;\">\345\257\206\347\240\201\357\274\232</span></p></body></html>", nullptr));
        label_5->setText(QApplication::translate("Register", "<html><head/><body><p><span style=\" font-size:12pt;\">\350\201\224\347\263\273\347\224\265\350\257\235\357\274\232</span></p></body></html>", nullptr));
        label_6->setText(QApplication::translate("Register", "<html><head/><body><p><span style=\" font-size:12pt;\">\350\201\224\347\263\273\345\234\260\345\235\200\357\274\232</span></p></body></html>", nullptr));
        registerButton->setText(QApplication::translate("Register", "\346\263\250\345\206\214", nullptr));
        cancelButton->setText(QApplication::translate("Register", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
