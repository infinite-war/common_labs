/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *centralwidget;
    QLineEdit *accountTextbox;
    QLineEdit *passwordTextbox;
    QPushButton *loginBotton;
    QPushButton *pushButton_3;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(800, 600);
        centralwidget = new QWidget(Login);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        accountTextbox = new QLineEdit(centralwidget);
        accountTextbox->setObjectName(QString::fromUtf8("accountTextbox"));
        accountTextbox->setGeometry(QRect(370, 200, 241, 31));
        accountTextbox->setMaxLength(32769);
        passwordTextbox = new QLineEdit(centralwidget);
        passwordTextbox->setObjectName(QString::fromUtf8("passwordTextbox"));
        passwordTextbox->setGeometry(QRect(370, 300, 241, 31));
        passwordTextbox->setMaxLength(32769);
        loginBotton = new QPushButton(centralwidget);
        loginBotton->setObjectName(QString::fromUtf8("loginBotton"));
        loginBotton->setGeometry(QRect(330, 400, 93, 28));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(450, 470, 93, 28));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 60, 471, 61));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(210, 200, 71, 31));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(230, 300, 71, 31));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(230, 470, 201, 31));
        Login->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Login);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        Login->setMenuBar(menubar);
        statusbar = new QStatusBar(Login);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Login->setStatusBar(statusbar);

        retranslateUi(Login);
        QObject::connect(pushButton_3, SIGNAL(clicked()), Login, SLOT(register_button_click()));
        QObject::connect(loginBotton, SIGNAL(clicked()), Login, SLOT(login_button_click()));

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Login", nullptr));
        loginBotton->setText(QApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
        pushButton_3->setText(QApplication::translate("Login", "\346\263\250\345\206\214", nullptr));
        label->setText(QApplication::translate("Login", "<html><head/><body><p align=\"center\"><span style=\" font-size:28pt;\">\346\240\241\345\233\255\344\272\214\346\211\213\344\271\246\344\272\244\346\230\223\345\271\263\345\217\260</span></p></body></html>", nullptr));
        label_3->setText(QApplication::translate("Login", "<html><head/><body><p><span style=\" font-size:12pt;\">\347\224\250\346\210\267\345\220\215\357\274\232</span></p></body></html>", nullptr));
        label_4->setText(QApplication::translate("Login", "<html><head/><body><p><span style=\" font-size:12pt;\">\345\257\206\347\240\201\357\274\232</span></p></body></html>", nullptr));
        label_5->setText(QApplication::translate("Login", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\346\262\241\346\234\211\350\264\246\345\217\267?\347\202\271\346\255\244\346\263\250\345\206\214\360\237\221\211</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
