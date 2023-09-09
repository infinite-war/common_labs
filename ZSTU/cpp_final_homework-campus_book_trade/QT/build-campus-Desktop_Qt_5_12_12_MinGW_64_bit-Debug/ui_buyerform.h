/********************************************************************************
** Form generated from reading UI file 'buyerform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUYERFORM_H
#define UI_BUYERFORM_H

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

class Ui_BuyerForm
{
public:
    QAction *action_log_out;
    QAction *actionchange_your_password;
    QWidget *centralwidget;
    QTableView *booksTableView;
    QLabel *label;
    QPushButton *allBooksButton;
    QLabel *label_2;
    QLineEdit *searchBookTextbox;
    QPushButton *searchBookButton;
    QTableView *ordersTableView;
    QLabel *label_3;
    QPushButton *allOrderButton;
    QPushButton *purchaseButton;
    QPushButton *goToSellerFormButton;
    QLabel *orderNumsLabel;
    QLabel *userNameLabel;
    QMenuBar *menubar;
    QMenu *logoutMenu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *BuyerForm)
    {
        if (BuyerForm->objectName().isEmpty())
            BuyerForm->setObjectName(QString::fromUtf8("BuyerForm"));
        BuyerForm->resize(1050, 950);
        action_log_out = new QAction(BuyerForm);
        action_log_out->setObjectName(QString::fromUtf8("action_log_out"));
        actionchange_your_password = new QAction(BuyerForm);
        actionchange_your_password->setObjectName(QString::fromUtf8("actionchange_your_password"));
        centralwidget = new QWidget(BuyerForm);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        booksTableView = new QTableView(centralwidget);
        booksTableView->setObjectName(QString::fromUtf8("booksTableView"));
        booksTableView->setGeometry(QRect(60, 80, 941, 411));
        booksTableView->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        booksTableView->horizontalHeader()->setVisible(false);
        booksTableView->horizontalHeader()->setCascadingSectionResizes(false);
        booksTableView->horizontalHeader()->setMinimumSectionSize(50);
        booksTableView->horizontalHeader()->setDefaultSectionSize(150);
        booksTableView->horizontalHeader()->setHighlightSections(true);
        booksTableView->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        booksTableView->horizontalHeader()->setStretchLastSection(false);
        booksTableView->verticalHeader()->setCascadingSectionResizes(false);
        booksTableView->verticalHeader()->setMinimumSectionSize(60);
        booksTableView->verticalHeader()->setDefaultSectionSize(60);
        booksTableView->verticalHeader()->setHighlightSections(true);
        booksTableView->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        booksTableView->verticalHeader()->setStretchLastSection(false);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(430, 10, 191, 51));
        allBooksButton = new QPushButton(centralwidget);
        allBooksButton->setObjectName(QString::fromUtf8("allBooksButton"));
        allBooksButton->setGeometry(QRect(60, 510, 141, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 180, 61, 211));
        searchBookTextbox = new QLineEdit(centralwidget);
        searchBookTextbox->setObjectName(QString::fromUtf8("searchBookTextbox"));
        searchBookTextbox->setGeometry(QRect(580, 510, 221, 31));
        searchBookButton = new QPushButton(centralwidget);
        searchBookButton->setObjectName(QString::fromUtf8("searchBookButton"));
        searchBookButton->setGeometry(QRect(820, 510, 141, 31));
        ordersTableView = new QTableView(centralwidget);
        ordersTableView->setObjectName(QString::fromUtf8("ordersTableView"));
        ordersTableView->setGeometry(QRect(60, 630, 941, 211));
        ordersTableView->horizontalHeader()->setCascadingSectionResizes(false);
        ordersTableView->horizontalHeader()->setMinimumSectionSize(50);
        ordersTableView->horizontalHeader()->setDefaultSectionSize(150);
        ordersTableView->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        ordersTableView->horizontalHeader()->setStretchLastSection(false);
        ordersTableView->verticalHeader()->setVisible(false);
        ordersTableView->verticalHeader()->setCascadingSectionResizes(false);
        ordersTableView->verticalHeader()->setMinimumSectionSize(60);
        ordersTableView->verticalHeader()->setDefaultSectionSize(60);
        ordersTableView->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        ordersTableView->verticalHeader()->setStretchLastSection(false);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 630, 61, 211));
        allOrderButton = new QPushButton(centralwidget);
        allOrderButton->setObjectName(QString::fromUtf8("allOrderButton"));
        allOrderButton->setGeometry(QRect(60, 580, 141, 31));
        purchaseButton = new QPushButton(centralwidget);
        purchaseButton->setObjectName(QString::fromUtf8("purchaseButton"));
        purchaseButton->setGeometry(QRect(390, 510, 91, 31));
        goToSellerFormButton = new QPushButton(centralwidget);
        goToSellerFormButton->setObjectName(QString::fromUtf8("goToSellerFormButton"));
        goToSellerFormButton->setGeometry(QRect(840, 20, 161, 31));
        orderNumsLabel = new QLabel(centralwidget);
        orderNumsLabel->setObjectName(QString::fromUtf8("orderNumsLabel"));
        orderNumsLabel->setGeometry(QRect(60, 860, 181, 31));
        userNameLabel = new QLabel(centralwidget);
        userNameLabel->setObjectName(QString::fromUtf8("userNameLabel"));
        userNameLabel->setGeometry(QRect(20, 20, 301, 16));
        BuyerForm->setCentralWidget(centralwidget);
        menubar = new QMenuBar(BuyerForm);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1050, 26));
        logoutMenu = new QMenu(menubar);
        logoutMenu->setObjectName(QString::fromUtf8("logoutMenu"));
        BuyerForm->setMenuBar(menubar);
        statusbar = new QStatusBar(BuyerForm);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        BuyerForm->setStatusBar(statusbar);

        menubar->addAction(logoutMenu->menuAction());
        logoutMenu->addAction(action_log_out);
        logoutMenu->addAction(actionchange_your_password);

        retranslateUi(BuyerForm);
        QObject::connect(goToSellerFormButton, SIGNAL(clicked()), BuyerForm, SLOT(goto_sellerForm_click()));
        QObject::connect(allBooksButton, SIGNAL(clicked()), BuyerForm, SLOT(search_selling_book_click()));
        QObject::connect(searchBookButton, SIGNAL(clicked()), BuyerForm, SLOT(search_target_book_click()));
        QObject::connect(purchaseButton, SIGNAL(clicked()), BuyerForm, SLOT(on_purchase_button_click()));
        QObject::connect(allOrderButton, SIGNAL(clicked()), BuyerForm, SLOT(on_search_buyerOrder_click()));

        QMetaObject::connectSlotsByName(BuyerForm);
    } // setupUi

    void retranslateUi(QMainWindow *BuyerForm)
    {
        BuyerForm->setWindowTitle(QApplication::translate("BuyerForm", "MainWindow", nullptr));
        action_log_out->setText(QApplication::translate("BuyerForm", "log_out", nullptr));
        actionchange_your_password->setText(QApplication::translate("BuyerForm", "change_your_password", nullptr));
        label->setText(QApplication::translate("BuyerForm", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt;\">\344\271\260\346\226\271\347\225\214\351\235\242</span></p></body></html>", nullptr));
        allBooksButton->setText(QApplication::translate("BuyerForm", "\346\230\276\347\244\272\346\211\200\346\234\211\345\234\250\345\224\256\344\271\246\347\261\215", nullptr));
        label_2->setText(QApplication::translate("BuyerForm", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt;\">\345\234\250<br/>\345\224\256<br/>\344\271\246<br/>\347\261\215<br/>\346\240\217</span></p></body></html>", nullptr));
        searchBookButton->setText(QApplication::translate("BuyerForm", "\346\214\211\344\271\246\345\220\215\345\205\263\351\224\256\345\255\227\346\237\245\350\257\242", nullptr));
        label_3->setText(QApplication::translate("BuyerForm", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt;\">\345\267\262<br>\350\264\255<br>\350\256\242<br/>\345\215\225<br/>\346\240\217</span></p></body></html>", nullptr));
        allOrderButton->setText(QApplication::translate("BuyerForm", "\346\230\276\347\244\272\345\267\262\350\264\255\350\256\242\345\215\225", nullptr));
        purchaseButton->setText(QApplication::translate("BuyerForm", "\350\264\255\345\205\245", nullptr));
        goToSellerFormButton->setText(QApplication::translate("BuyerForm", "\350\277\233\345\205\245\345\215\226\346\226\271\347\225\214\351\235\242", nullptr));
        orderNumsLabel->setText(QApplication::translate("BuyerForm", "<html><head/><body><p>\350\256\242\345\215\225\346\200\273\346\225\260\357\274\232</p></body></html>", nullptr));
        userNameLabel->setText(QApplication::translate("BuyerForm", "\347\224\250\346\210\267\357\274\232", nullptr));
        logoutMenu->setTitle(QApplication::translate("BuyerForm", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BuyerForm: public Ui_BuyerForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUYERFORM_H
