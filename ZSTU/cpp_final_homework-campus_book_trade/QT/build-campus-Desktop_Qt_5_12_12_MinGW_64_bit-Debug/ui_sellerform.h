/********************************************************************************
** Form generated from reading UI file 'sellerform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELLERFORM_H
#define UI_SELLERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SellerForm
{
public:
    QAction *action_log_out;
    QAction *actionchange_your_password;
    QWidget *centralwidget;
    QLabel *label;
    QTableView *ordersTableView;
    QTableView *booksTableView;
    QPushButton *allBooksButton;
    QLabel *label_2;
    QPushButton *searchBookButton;
    QPushButton *allOrderButton;
    QLabel *label_3;
    QPushButton *insertButton;
    QLineEdit *searchBookTextbox;
    QPushButton *deleteButton;
    QPushButton *updateButton;
    QPushButton *goToBuyerFormButton;
    QLabel *orderNumsLabel;
    QLabel *userNameLabel;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SellerForm)
    {
        if (SellerForm->objectName().isEmpty())
            SellerForm->setObjectName(QString::fromUtf8("SellerForm"));
        SellerForm->resize(1050, 950);
        action_log_out = new QAction(SellerForm);
        action_log_out->setObjectName(QString::fromUtf8("action_log_out"));
        actionchange_your_password = new QAction(SellerForm);
        actionchange_your_password->setObjectName(QString::fromUtf8("actionchange_your_password"));
        centralwidget = new QWidget(SellerForm);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(430, 20, 191, 51));
        ordersTableView = new QTableView(centralwidget);
        ordersTableView->setObjectName(QString::fromUtf8("ordersTableView"));
        ordersTableView->setGeometry(QRect(70, 620, 941, 221));
        ordersTableView->horizontalHeader()->setMinimumSectionSize(50);
        ordersTableView->horizontalHeader()->setDefaultSectionSize(150);
        ordersTableView->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        ordersTableView->verticalHeader()->setMinimumSectionSize(60);
        ordersTableView->verticalHeader()->setDefaultSectionSize(60);
        ordersTableView->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        booksTableView = new QTableView(centralwidget);
        booksTableView->setObjectName(QString::fromUtf8("booksTableView"));
        booksTableView->setGeometry(QRect(70, 80, 941, 411));
        booksTableView->horizontalHeader()->setMinimumSectionSize(50);
        booksTableView->horizontalHeader()->setDefaultSectionSize(150);
        booksTableView->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        booksTableView->verticalHeader()->setMinimumSectionSize(60);
        booksTableView->verticalHeader()->setDefaultSectionSize(60);
        booksTableView->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        allBooksButton = new QPushButton(centralwidget);
        allBooksButton->setObjectName(QString::fromUtf8("allBooksButton"));
        allBooksButton->setGeometry(QRect(80, 500, 141, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 180, 61, 211));
        searchBookButton = new QPushButton(centralwidget);
        searchBookButton->setObjectName(QString::fromUtf8("searchBookButton"));
        searchBookButton->setGeometry(QRect(920, 500, 91, 31));
        allOrderButton = new QPushButton(centralwidget);
        allOrderButton->setObjectName(QString::fromUtf8("allOrderButton"));
        allOrderButton->setGeometry(QRect(80, 570, 141, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 630, 61, 211));
        insertButton = new QPushButton(centralwidget);
        insertButton->setObjectName(QString::fromUtf8("insertButton"));
        insertButton->setGeometry(QRect(290, 530, 91, 31));
        searchBookTextbox = new QLineEdit(centralwidget);
        searchBookTextbox->setObjectName(QString::fromUtf8("searchBookTextbox"));
        searchBookTextbox->setGeometry(QRect(680, 500, 221, 31));
        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setGeometry(QRect(430, 530, 91, 31));
        updateButton = new QPushButton(centralwidget);
        updateButton->setObjectName(QString::fromUtf8("updateButton"));
        updateButton->setGeometry(QRect(560, 530, 91, 31));
        goToBuyerFormButton = new QPushButton(centralwidget);
        goToBuyerFormButton->setObjectName(QString::fromUtf8("goToBuyerFormButton"));
        goToBuyerFormButton->setGeometry(QRect(850, 20, 161, 31));
        orderNumsLabel = new QLabel(centralwidget);
        orderNumsLabel->setObjectName(QString::fromUtf8("orderNumsLabel"));
        orderNumsLabel->setGeometry(QRect(70, 860, 131, 31));
        userNameLabel = new QLabel(centralwidget);
        userNameLabel->setObjectName(QString::fromUtf8("userNameLabel"));
        userNameLabel->setGeometry(QRect(20, 20, 301, 16));
        SellerForm->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SellerForm);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1050, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        SellerForm->setMenuBar(menubar);
        statusbar = new QStatusBar(SellerForm);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SellerForm->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(action_log_out);
        menu->addAction(actionchange_your_password);

        retranslateUi(SellerForm);
        QObject::connect(goToBuyerFormButton, SIGNAL(clicked()), SellerForm, SLOT(goto_buyerForm_click()));
        QObject::connect(allBooksButton, SIGNAL(clicked()), SellerForm, SLOT(get_my_book_click()));
        QObject::connect(searchBookButton, SIGNAL(clicked()), SellerForm, SLOT(search_target_book_click()));
        QObject::connect(updateButton, SIGNAL(clicked()), SellerForm, SLOT(on_edit_button_clicked()));
        QObject::connect(insertButton, SIGNAL(clicked()), SellerForm, SLOT(on_insert_button_clicked()));
        QObject::connect(deleteButton, SIGNAL(clicked()), SellerForm, SLOT(on_delete_button_clicked()));
        QObject::connect(allOrderButton, SIGNAL(clicked()), SellerForm, SLOT(on_search_sellerOrder_click()));

        QMetaObject::connectSlotsByName(SellerForm);
    } // setupUi

    void retranslateUi(QMainWindow *SellerForm)
    {
        SellerForm->setWindowTitle(QApplication::translate("SellerForm", "MainWindow", nullptr));
        action_log_out->setText(QApplication::translate("SellerForm", "log_out", nullptr));
        actionchange_your_password->setText(QApplication::translate("SellerForm", "change_your_password", nullptr));
        label->setText(QApplication::translate("SellerForm", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt;\">\345\215\226\346\226\271\347\225\214\351\235\242</span></p></body></html>", nullptr));
        allBooksButton->setText(QApplication::translate("SellerForm", "\346\230\276\347\244\272\346\211\200\346\234\211\347\232\204\345\272\223\350\227\217\344\271\246", nullptr));
        label_2->setText(QApplication::translate("SellerForm", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt;\">\344\275\240<br>\347\232\204<br>\344\271\246<br>\345\272\223</span></p></body></html>", nullptr));
        searchBookButton->setText(QApplication::translate("SellerForm", "\345\205\263\351\224\256\345\255\227\346\237\245\350\257\242", nullptr));
        allOrderButton->setText(QApplication::translate("SellerForm", "\346\230\276\347\244\272\345\267\262\345\224\256\350\256\242\345\215\225", nullptr));
        label_3->setText(QApplication::translate("SellerForm", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt;\">\345\267\262<br/>\345\224\256<br/>\350\256\242<br/>\345\215\225<br/>\346\240\217</span></p></body></html>", nullptr));
        insertButton->setText(QApplication::translate("SellerForm", "\346\267\273\345\212\240\344\271\246", nullptr));
        deleteButton->setText(QApplication::translate("SellerForm", "\345\210\240\351\231\244\344\271\246", nullptr));
        updateButton->setText(QApplication::translate("SellerForm", "\344\277\256\346\224\271\344\271\246", nullptr));
        goToBuyerFormButton->setText(QApplication::translate("SellerForm", "\350\277\233\345\205\245\344\271\260\346\226\271\347\225\214\351\235\242", nullptr));
        orderNumsLabel->setText(QApplication::translate("SellerForm", "<html><head/><body><p>\350\256\242\345\215\225\346\200\273\346\225\260\357\274\232</p></body></html>", nullptr));
        userNameLabel->setText(QApplication::translate("SellerForm", "\347\224\250\346\210\267\357\274\232", nullptr));
        menu->setTitle(QApplication::translate("SellerForm", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SellerForm: public Ui_SellerForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELLERFORM_H
