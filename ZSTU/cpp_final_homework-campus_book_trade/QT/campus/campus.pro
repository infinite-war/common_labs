QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    account.cpp \
    book.cpp \
    buyerform.cpp \
    dbmanager.cpp \
    editdialog.cpp \
    insertdialog.cpp \
    main.cpp \
    login.cpp \
    order.cpp \
    passwordeditform.cpp \
    purchasedialog.cpp \
    register.cpp \
    sellerform.cpp

HEADERS += \
    account.h \
    all_headers.h \
    book.h \
    buyerform.h \
    dbmanager.h \
    editdialog.h \
    insertdialog.h \
    login.h \
    order.h \
    passwordeditform.h \
    purchasedialog.h \
    register.h \
    sellerform.h

FORMS += \
    buyerform.ui \
    editdialog.ui \
    insertdialog.ui \
    login.ui \
    passwordeditform.ui \
    purchasedialog.ui \
    register.ui \
    sellerform.ui

TRANSLATIONS += \
    campus_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
QT+=sql
