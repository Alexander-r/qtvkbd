/****************************************************************************
** Meta object code from reading C++ file 'qtvkbdapp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../qtvkbdapp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtvkbdapp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtvkbdApp_t {
    QByteArrayData data[23];
    char stringdata0[248];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtvkbdApp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtvkbdApp_t qt_meta_stringdata_QtvkbdApp = {
    {
QT_MOC_LITERAL(0, 0, 9), // "QtvkbdApp"
QT_MOC_LITERAL(1, 10, 10), // "textSwitch"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 11), // "fontUpdated"
QT_MOC_LITERAL(4, 34, 4), // "font"
QT_MOC_LITERAL(5, 39, 16), // "startupCompleted"
QT_MOC_LITERAL(6, 56, 18), // "keyProcessComplete"
QT_MOC_LITERAL(7, 75, 12), // "buttonAction"
QT_MOC_LITERAL(8, 88, 6), // "action"
QT_MOC_LITERAL(9, 95, 11), // "storeConfig"
QT_MOC_LITERAL(10, 107, 15), // "toggleExtension"
QT_MOC_LITERAL(11, 123, 10), // "chooseFont"
QT_MOC_LITERAL(12, 134, 14), // "autoResizeFont"
QT_MOC_LITERAL(13, 149, 4), // "mode"
QT_MOC_LITERAL(14, 154, 16), // "setStickyModKeys"
QT_MOC_LITERAL(15, 171, 10), // "partLoaded"
QT_MOC_LITERAL(16, 182, 11), // "MainWidget*"
QT_MOC_LITERAL(17, 194, 5), // "vPart"
QT_MOC_LITERAL(18, 200, 10), // "total_rows"
QT_MOC_LITERAL(19, 211, 10), // "total_cols"
QT_MOC_LITERAL(20, 222, 12), // "buttonLoaded"
QT_MOC_LITERAL(21, 235, 8), // "VButton*"
QT_MOC_LITERAL(22, 244, 3) // "btn"

    },
    "QtvkbdApp\0textSwitch\0\0fontUpdated\0"
    "font\0startupCompleted\0keyProcessComplete\0"
    "buttonAction\0action\0storeConfig\0"
    "toggleExtension\0chooseFont\0autoResizeFont\0"
    "mode\0setStickyModKeys\0partLoaded\0"
    "MainWidget*\0vPart\0total_rows\0total_cols\0"
    "buttonLoaded\0VButton*\0btn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtvkbdApp[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       3,    1,   77,    2, 0x06 /* Public */,
       5,    0,   80,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   81,    2, 0x0a /* Public */,
       7,    1,   84,    2, 0x0a /* Public */,
       9,    0,   87,    2, 0x0a /* Public */,
      10,    0,   88,    2, 0x0a /* Public */,
      11,    0,   89,    2, 0x0a /* Public */,
      12,    1,   90,    2, 0x0a /* Public */,
      14,    1,   93,    2, 0x0a /* Public */,
      15,    3,   96,    2, 0x0a /* Public */,
      20,    1,  103,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::QFont,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt,    2,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, 0x80000000 | 16, QMetaType::Int, QMetaType::Int,   17,   18,   19,
    QMetaType::Void, 0x80000000 | 21,   22,

       0        // eod
};

void QtvkbdApp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtvkbdApp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->textSwitch((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->fontUpdated((*reinterpret_cast< const QFont(*)>(_a[1]))); break;
        case 2: _t->startupCompleted(); break;
        case 3: _t->keyProcessComplete((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 4: _t->buttonAction((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->storeConfig(); break;
        case 6: _t->toggleExtension(); break;
        case 7: _t->chooseFont(); break;
        case 8: _t->autoResizeFont((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->setStickyModKeys((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->partLoaded((*reinterpret_cast< MainWidget*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 11: _t->buttonLoaded((*reinterpret_cast< VButton*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MainWidget* >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< VButton* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QtvkbdApp::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtvkbdApp::textSwitch)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QtvkbdApp::*)(const QFont & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtvkbdApp::fontUpdated)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QtvkbdApp::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QtvkbdApp::startupCompleted)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QtvkbdApp::staticMetaObject = { {
    QMetaObject::SuperData::link<QApplication::staticMetaObject>(),
    qt_meta_stringdata_QtvkbdApp.data,
    qt_meta_data_QtvkbdApp,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QtvkbdApp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtvkbdApp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtvkbdApp.stringdata0))
        return static_cast<void*>(this);
    return QApplication::qt_metacast(_clname);
}

int QtvkbdApp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QApplication::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void QtvkbdApp::textSwitch(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QtvkbdApp::fontUpdated(const QFont & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QtvkbdApp::startupCompleted()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
