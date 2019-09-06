/****************************************************************************
** Meta object code from reading C++ file 'mainform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../IMsoftware_client/widget/mainform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainForm_t {
    QByteArrayData data[7];
    char stringdata0[103];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainForm_t qt_meta_stringdata_MainForm = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MainForm"
QT_MOC_LITERAL(1, 9, 17), // "do_close_mainform"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 18), // "onThemeColorChange"
QT_MOC_LITERAL(4, 47, 8), // "colorStr"
QT_MOC_LITERAL(5, 56, 22), // "on_skin_Button_clicked"
QT_MOC_LITERAL(6, 79, 23) // "on_close_Button_clicked"

    },
    "MainForm\0do_close_mainform\0\0"
    "onThemeColorChange\0colorStr\0"
    "on_skin_Button_clicked\0on_close_Button_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   35,    2, 0x08 /* Private */,
       5,    0,   38,    2, 0x08 /* Private */,
       6,    0,   39,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainForm *_t = static_cast<MainForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->do_close_mainform(); break;
        case 1: _t->onThemeColorChange((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_skin_Button_clicked(); break;
        case 3: _t->on_close_Button_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainForm::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainForm::do_close_mainform)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MainForm::staticMetaObject = {
    { &MoveableFramelessWindow::staticMetaObject, qt_meta_stringdata_MainForm.data,
      qt_meta_data_MainForm,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainForm::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainForm.stringdata0))
        return static_cast<void*>(const_cast< MainForm*>(this));
    return MoveableFramelessWindow::qt_metacast(_clname);
}

int MainForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MoveableFramelessWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void MainForm::do_close_mainform()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
