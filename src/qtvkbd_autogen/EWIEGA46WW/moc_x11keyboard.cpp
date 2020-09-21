/****************************************************************************
** Meta object code from reading C++ file 'x11keyboard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../x11keyboard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'x11keyboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_X11Keyboard_t {
    QByteArrayData data[7];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_X11Keyboard_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_X11Keyboard_t qt_meta_stringdata_X11Keyboard = {
    {
QT_MOC_LITERAL(0, 0, 11), // "X11Keyboard"
QT_MOC_LITERAL(1, 12, 15), // "processKeyPress"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 13), // "queryModState"
QT_MOC_LITERAL(4, 43, 16), // "constructLayouts"
QT_MOC_LITERAL(5, 60, 13), // "layoutChanged"
QT_MOC_LITERAL(6, 74, 5) // "start"

    },
    "X11Keyboard\0processKeyPress\0\0queryModState\0"
    "constructLayouts\0layoutChanged\0start"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_X11Keyboard[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       3,    0,   42,    2, 0x0a /* Public */,
       4,    0,   43,    2, 0x0a /* Public */,
       5,    0,   44,    2, 0x0a /* Public */,
       6,    0,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void X11Keyboard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<X11Keyboard *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->processKeyPress((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 1: _t->queryModState(); break;
        case 2: _t->constructLayouts(); break;
        case 3: _t->layoutChanged(); break;
        case 4: _t->start(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject X11Keyboard::staticMetaObject = { {
    QMetaObject::SuperData::link<VKeyboard::staticMetaObject>(),
    qt_meta_stringdata_X11Keyboard.data,
    qt_meta_data_X11Keyboard,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *X11Keyboard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *X11Keyboard::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_X11Keyboard.stringdata0))
        return static_cast<void*>(this);
    return VKeyboard::qt_metacast(_clname);
}

int X11Keyboard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = VKeyboard::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
