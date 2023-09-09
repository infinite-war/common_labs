/****************************************************************************
** Meta object code from reading C++ file 'sellerform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../campus/sellerform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sellerform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SellerForm_t {
    QByteArrayData data[18];
    char stringdata0[358];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SellerForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SellerForm_t qt_meta_stringdata_SellerForm = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SellerForm"
QT_MOC_LITERAL(1, 11, 14), // "show_buyerForm"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 14), // "show_loginForm"
QT_MOC_LITERAL(4, 42, 27), // "on_action_log_out_triggered"
QT_MOC_LITERAL(5, 70, 20), // "goto_buyerForm_click"
QT_MOC_LITERAL(6, 91, 39), // "on_actionchange_your_password..."
QT_MOC_LITERAL(7, 131, 17), // "get_my_book_click"
QT_MOC_LITERAL(8, 149, 24), // "search_target_book_click"
QT_MOC_LITERAL(9, 174, 22), // "on_edit_button_clicked"
QT_MOC_LITERAL(10, 197, 24), // "on_insert_button_clicked"
QT_MOC_LITERAL(11, 222, 24), // "on_delete_button_clicked"
QT_MOC_LITERAL(12, 247, 27), // "on_search_sellerOrder_click"
QT_MOC_LITERAL(13, 275, 18), // "receive_from_buyer"
QT_MOC_LITERAL(14, 294, 25), // "receive_from_edit_confirm"
QT_MOC_LITERAL(15, 320, 4), // "Book"
QT_MOC_LITERAL(16, 325, 4), // "book"
QT_MOC_LITERAL(17, 330, 27) // "receive_from_insert_confirm"

    },
    "SellerForm\0show_buyerForm\0\0show_loginForm\0"
    "on_action_log_out_triggered\0"
    "goto_buyerForm_click\0"
    "on_actionchange_your_password_triggered\0"
    "get_my_book_click\0search_target_book_click\0"
    "on_edit_button_clicked\0on_insert_button_clicked\0"
    "on_delete_button_clicked\0"
    "on_search_sellerOrder_click\0"
    "receive_from_buyer\0receive_from_edit_confirm\0"
    "Book\0book\0receive_from_insert_confirm"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SellerForm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    0,   91,    2, 0x08 /* Private */,
      10,    0,   92,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    1,   96,    2, 0x08 /* Private */,
      17,    1,   99,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 15,   16,

       0        // eod
};

void SellerForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SellerForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->show_buyerForm(); break;
        case 1: _t->show_loginForm(); break;
        case 2: _t->on_action_log_out_triggered(); break;
        case 3: _t->goto_buyerForm_click(); break;
        case 4: _t->on_actionchange_your_password_triggered(); break;
        case 5: _t->get_my_book_click(); break;
        case 6: _t->search_target_book_click(); break;
        case 7: _t->on_edit_button_clicked(); break;
        case 8: _t->on_insert_button_clicked(); break;
        case 9: _t->on_delete_button_clicked(); break;
        case 10: _t->on_search_sellerOrder_click(); break;
        case 11: _t->receive_from_buyer(); break;
        case 12: _t->receive_from_edit_confirm((*reinterpret_cast< Book(*)>(_a[1]))); break;
        case 13: _t->receive_from_insert_confirm((*reinterpret_cast< Book(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SellerForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SellerForm::show_buyerForm)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SellerForm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SellerForm::show_loginForm)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SellerForm::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_SellerForm.data,
    qt_meta_data_SellerForm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SellerForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SellerForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SellerForm.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SellerForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void SellerForm::show_buyerForm()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SellerForm::show_loginForm()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
