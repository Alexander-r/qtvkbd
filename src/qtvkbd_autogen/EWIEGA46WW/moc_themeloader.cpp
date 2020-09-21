/****************************************************************************
** Meta object code from reading C++ file 'themeloader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../themeloader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'themeloader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ThemeLoader_t {
    QByteArrayData data[12];
    char stringdata0[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ThemeLoader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ThemeLoader_t qt_meta_stringdata_ThemeLoader = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ThemeLoader"
QT_MOC_LITERAL(1, 12, 10), // "partLoaded"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 11), // "MainWidget*"
QT_MOC_LITERAL(4, 36, 5), // "vPart"
QT_MOC_LITERAL(5, 42, 10), // "total_rows"
QT_MOC_LITERAL(6, 53, 10), // "total_cols"
QT_MOC_LITERAL(7, 64, 12), // "buttonLoaded"
QT_MOC_LITERAL(8, 77, 8), // "VButton*"
QT_MOC_LITERAL(9, 86, 3), // "btn"
QT_MOC_LITERAL(10, 90, 17), // "colorStyleChanged"
QT_MOC_LITERAL(11, 108, 14) // "loadColorStyle"

    },
    "ThemeLoader\0partLoaded\0\0MainWidget*\0"
    "vPart\0total_rows\0total_cols\0buttonLoaded\0"
    "VButton*\0btn\0colorStyleChanged\0"
    "loadColorStyle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ThemeLoader[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   34,    2, 0x06 /* Public */,
       7,    1,   41,    2, 0x06 /* Public */,
      10,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int,    4,    5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void ThemeLoader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ThemeLoader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->partLoaded((*reinterpret_cast< MainWidget*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->buttonLoaded((*reinterpret_cast< VButton*(*)>(_a[1]))); break;
        case 2: _t->colorStyleChanged(); break;
        case 3: _t->loadColorStyle(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MainWidget* >(); break;
            }
            break;
        case 1:
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
            using _t = void (ThemeLoader::*)(MainWidget * , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThemeLoader::partLoaded)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ThemeLoader::*)(VButton * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThemeLoader::buttonLoaded)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ThemeLoader::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ThemeLoader::colorStyleChanged)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ThemeLoader::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ThemeLoader.data,
    qt_meta_data_ThemeLoader,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ThemeLoader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ThemeLoader::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ThemeLoader.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ThemeLoader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ThemeLoader::partLoaded(MainWidget * _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ThemeLoader::buttonLoaded(VButton * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ThemeLoader::colorStyleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
