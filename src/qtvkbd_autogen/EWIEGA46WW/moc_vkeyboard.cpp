/****************************************************************************
** Meta object code from reading C++ file 'vkeyboard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../vkeyboard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vkeyboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VKeyboard_t {
    QByteArrayData data[12];
    char stringdata0[166];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VKeyboard_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VKeyboard_t qt_meta_stringdata_VKeyboard = {
    {
QT_MOC_LITERAL(0, 0, 9), // "VKeyboard"
QT_MOC_LITERAL(1, 10, 18), // "keyProcessComplete"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 17), // "groupStateChanged"
QT_MOC_LITERAL(4, 48, 21), // "ModifierGroupStateMap"
QT_MOC_LITERAL(5, 70, 14), // "modifier_state"
QT_MOC_LITERAL(6, 85, 13), // "layoutUpdated"
QT_MOC_LITERAL(7, 99, 15), // "processKeyPress"
QT_MOC_LITERAL(8, 115, 13), // "queryModState"
QT_MOC_LITERAL(9, 129, 16), // "constructLayouts"
QT_MOC_LITERAL(10, 146, 13), // "layoutChanged"
QT_MOC_LITERAL(11, 160, 5) // "start"

    },
    "VKeyboard\0keyProcessComplete\0\0"
    "groupStateChanged\0ModifierGroupStateMap\0"
    "modifier_state\0layoutUpdated\0"
    "processKeyPress\0queryModState\0"
    "constructLayouts\0layoutChanged\0start"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VKeyboard[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       3,    1,   57,    2, 0x06 /* Public */,
       6,    2,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   65,    2, 0x0a /* Public */,
       8,    0,   68,    2, 0x0a /* Public */,
       9,    0,   69,    2, 0x0a /* Public */,
      10,    0,   70,    2, 0x0a /* Public */,
      11,    0,   71,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt,    2,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void VKeyboard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VKeyboard *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->keyProcessComplete((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 1: _t->groupStateChanged((*reinterpret_cast< const ModifierGroupStateMap(*)>(_a[1]))); break;
        case 2: _t->layoutUpdated((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->processKeyPress((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 4: _t->queryModState(); break;
        case 5: _t->constructLayouts(); break;
        case 6: _t->layoutChanged(); break;
        case 7: _t->start(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VKeyboard::*)(unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VKeyboard::keyProcessComplete)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (VKeyboard::*)(const ModifierGroupStateMap & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VKeyboard::groupStateChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (VKeyboard::*)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VKeyboard::layoutUpdated)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject VKeyboard::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_VKeyboard.data,
    qt_meta_data_VKeyboard,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VKeyboard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VKeyboard::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VKeyboard.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int VKeyboard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void VKeyboard::keyProcessComplete(unsigned int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VKeyboard::groupStateChanged(const ModifierGroupStateMap & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void VKeyboard::layoutUpdated(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
