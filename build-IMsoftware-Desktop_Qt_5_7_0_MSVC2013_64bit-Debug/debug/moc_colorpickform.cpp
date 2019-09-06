/****************************************************************************
** Meta object code from reading C++ file 'colorpickform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../IMsoftware_client/ui/colorpickform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'colorpickform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ColorPickForm_t {
    QByteArrayData data[14];
    char stringdata0[162];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ColorPickForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ColorPickForm_t qt_meta_stringdata_ColorPickForm = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ColorPickForm"
QT_MOC_LITERAL(1, 14, 16), // "themColorChanged"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 8), // "colorStr"
QT_MOC_LITERAL(4, 41, 15), // "onColorButClick"
QT_MOC_LITERAL(5, 57, 12), // "QPushButton*"
QT_MOC_LITERAL(6, 70, 3), // "pub"
QT_MOC_LITERAL(7, 74, 11), // "eventFilter"
QT_MOC_LITERAL(8, 86, 6), // "sender"
QT_MOC_LITERAL(9, 93, 7), // "QEvent*"
QT_MOC_LITERAL(10, 101, 1), // "e"
QT_MOC_LITERAL(11, 103, 18), // "onThemeColorChange"
QT_MOC_LITERAL(12, 122, 17), // "onColorPanleClick"
QT_MOC_LITERAL(13, 140, 21) // "on_pushButton_clicked"

    },
    "ColorPickForm\0themColorChanged\0\0"
    "colorStr\0onColorButClick\0QPushButton*\0"
    "pub\0eventFilter\0sender\0QEvent*\0e\0"
    "onThemeColorChange\0onColorPanleClick\0"
    "on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ColorPickForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   47,    2, 0x08 /* Private */,
       7,    2,   50,    2, 0x08 /* Private */,
      11,    1,   55,    2, 0x08 /* Private */,
      12,    0,   58,    2, 0x08 /* Private */,
      13,    0,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 9,    8,   10,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ColorPickForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ColorPickForm *_t = static_cast<ColorPickForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->themColorChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->onColorButClick((*reinterpret_cast< QPushButton*(*)>(_a[1]))); break;
        case 2: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: _t->onThemeColorChange((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->onColorPanleClick(); break;
        case 5: _t->on_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QPushButton* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ColorPickForm::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ColorPickForm::themColorChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ColorPickForm::staticMetaObject = {
    { &MoveableFramelessWindow::staticMetaObject, qt_meta_stringdata_ColorPickForm.data,
      qt_meta_data_ColorPickForm,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ColorPickForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ColorPickForm::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ColorPickForm.stringdata0))
        return static_cast<void*>(const_cast< ColorPickForm*>(this));
    if (!strcmp(_clname, "Singleton<ColorPickForm>"))
        return static_cast< Singleton<ColorPickForm>*>(const_cast< ColorPickForm*>(this));
    return MoveableFramelessWindow::qt_metacast(_clname);
}

int ColorPickForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MoveableFramelessWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ColorPickForm::themColorChanged(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
